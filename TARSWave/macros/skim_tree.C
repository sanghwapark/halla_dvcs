const int fNChannels = 1080;
const int fNSamples = 110;  // default sample number: 110 samples 
const int fNMaxArray = fNChannels * (fNSamples+2) + 2000; // blocks 2000, 2001 for scintillator, add extra room to be safe

// hcana tree variables
Int_t fNadcSampWaveform;
Double_t adcSampWaveform[fNMaxArray];
Int_t fNadcSampPulseInt;
Double_t adcSampPulseInt[fNMaxArray];
Int_t fNadcSampPulseAmp;
Double_t adcSampPulseAmp[fNMaxArray];
Int_t fNadcSampPulseTime;
Double_t adcSampPulseTime[fNMaxArray];

typedef struct{
  double waveform[fNSamples];
} CaloData;

void read_tree(TTree* tree);
void skim_tree(TString fin)
{

  // Set output tree 
  TFile* fout = new TFile("skim_tree.root","RECREATE");
  TTree* tout = new TTree("T","T");

  // List of output vars
  int EvtNum;
  CaloData calo[fNChannels];

  tout->Branch("EvtNum", &EvtNum, "EvtNum/I");
  // 1080 branches
  for(int i=0; i<fNChannels; i++)
    tout->Branch(Form("ch%d",i), calo[i].waveform, Form("ch%d[%d]/D",i,fNSamples));

  // Read ROOT input file
  TFile* file = new TFile(fin);
  TTree * T = (TTree*)file->Get("T");

  cout << "Read Tree...." << endl;
  read_tree(T);
  
  int nentries = T->GetEntries();
  cout << "We have " << nentries << " events" << endl;
  for(int ientry = 0; ientry<nentries; ientry++)
    {
      // skip the first event
      if(ientry ==0) continue;
      T->GetEntry(ientry);
      
      if(ientry > 5000) break;

      for(int i=0; i<fNadcSampWaveform; i++) {
	if(i%(112)==0) {
	  int blockID = int(adcSampWaveform[i]);
	  int nsamples = int(adcSampWaveform[i+1]);
	  
	  if(blockID > 1079) continue;
	  
	  if(nsamples > fNSamples || nsamples < fNSamples)
	    cout << "ERROR: sample number mismatch " << blockID << " " << nsamples << endl;
	  
	  for(int ismp=0; ismp<nsamples; ismp++)
	    calo[blockID].waveform[ismp] = adcSampWaveform[i+2+ismp];
	}
      }//adcSampWaveform loop

      EvtNum = ientry;
      tout->Fill();

    }// event loop

  fout->cd();
  tout->Write();
  fout->Close();

}

void read_tree(TTree* tree)
{

  tree->SetBranchAddress("Ndata.NPS.cal.fly.adcSampWaveform", &fNadcSampWaveform);
  tree->SetBranchAddress("NPS.cal.fly.adcSampWaveform", adcSampWaveform);

  tree->SetBranchAddress("Ndata.NPS.cal.fly.adcSampPulseInt", &fNadcSampPulseInt);
  tree->SetBranchAddress("NPS.cal.fly.adcSampPulseInt", adcSampPulseInt);

  tree->SetBranchAddress("Ndata.NPS.cal.fly.adcSampPulseAmp", &fNadcSampPulseAmp);
  tree->SetBranchAddress("NPS.cal.fly.adcSampPulseAmp", adcSampPulseAmp);

  return;
}
