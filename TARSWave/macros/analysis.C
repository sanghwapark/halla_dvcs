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

bool fDebug = false;
bool fRefSp = true;
bool SubPed = true;

void read_tree(TTree* tree);

struct CaloData{
  int blockID[fNChannels];
  // cluster information from replay
  double pulseInt[fNChannels];
  double pulseAmp[fNChannels];
  double pulsePed[fNChannels];
};

struct Waveform{
  vector<double> m_wf;
}

void analysis(TString fin)
{

  // Define out tree
  TFile* fout = new TFile("fout.root", "RECREATE");
  CaloData calo;
  TTree* tout = new TTree("tout", "tout");
  tout->Branch("calo", &calo);

  // Read ROOT input file
  TFile* file = new TFile(fin);
  TTree * T = (TTree*)file->Get("T");

  Waveform WF[fNChannels];

  cout << "Read Tree...." << endl;
  read_tree(T);
  
  int nentries = T->GetEntries();
  cout << "We have " << nentries << " events" << endl;
  for(int ientry = 0; ientry<nentries; ientry++)
    {
      // skip the first event
      if(ientry ==0) continue;

      T->GetEntry(ientry);

      //if(ientry>3000) break;

      {
	// loop over all wf quantities
	int this_block = 0;
	int counter = 0;
	for(int i=0; i<fNadcSampWaveform; i++) {
	  // find block ids
	  if(i%(fNSamples + 2)==0) {
	    this_block = adcSampWaveform[i];
	    calo.blockID[this_block] = this_block;
	    calo.pulseInt[this_block] = 0;
	    calo.pulseAmp[this_block] = 0;
	    calo.pulsePed[this_block] = 0; // quick way.. use first 5 channel average
	    //recent sample counter
	    counter = 0;

	    //Calculate Ped first using first give samples
	    for(int j=0; j<5; j++)
	      calo.pulsePed[this_block] += adcSampWaveform[i+2+j]/5;

	    continue;      
	  }
	  // sample number
	  if(i%(fNSamples + 2)==1)
	    continue;
    
	  // only looking for block 0-1079
	  if(this_block > fNChannels -1) continue;
	  
	  if(SubPed)
	    calo.pulseInt[this_block] += (adcSampWaveform[i] - calo.pulsePed[this_block]);
	  else
	    calo.pulseInt[this_block] += adcSampWaveform[i];

	  if( calo.pulseAmp[this_block] < adcSampWaveform[i] )
	    calo.pulseAmp[this_block] = adcSampWaveform[i];

	  counter++;
	}//SampWaveform loop
		
      }//
	
      // we only fill it once
      tout->Fill();
      if(fRefSp)
	{


	}

      
    }//event loop

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
  
