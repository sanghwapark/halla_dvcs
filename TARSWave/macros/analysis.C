const int fNChannels = 1080;
const int fNSamples = 110;  // default sample number: 110 samples 

// hcana tree variables
Int_t fNadcSampWaveform;
Double_t adcSampWaveform[120960];
Double_t goodAdcPulseTime[fNChannels];
Double_t goodAdcPed[fNChannels];
Double_t goodAdcPulseInt[fNChannels];
Double_t goodAdcPulseAmp[fNChannels];

void read_tree(TTree* tree);

bool fDebug = false;

struct CaloData{
  int m_blockID;
  int m_nSamples;
  vector<double> m_waveform;

  // cluster information from replay
  double pulseInt;
  double pulseAmp;
  double pulsePed;
};

void analysis(TString fin)
{

  // Define out tree
  TFile* fout = new TFile("fout.root", "RECREATE");
  int o_blockID[fNChannels];
  double o_pulseInt[fNChannels];
  double o_pulseAmp[fNChannels];

  TTree* tout = new TTree("tout", "tout");
  tout->Branch("blockID",  o_blockID,  "blockID[1080]/I");
  tout->Branch("pulseInt",  o_pulseInt,  "pulseInt[1080]/D");
  tout->Branch("pulseAmp",  o_pulseAmp,  "pulseAmp[1080]/D");

  TH1F* hped[fNChannels];
  TH1F* hint[fNChannels];
  TH1F* hamp[fNChannels];
  for(int ich=0; ich<fNChannels; ich++)
    {
      hped[ich] = new TH1F(Form("hped_%d",ich), Form("ped_%d",ich), 3000,-1000,2000);
      hint[ich] = new TH1F(Form("hint_%d",ich), Form("int_%d",ich), 3000,-1000,2000);
      hamp[ich] = new TH1F(Form("hamp_%d",ich), Form("amp_%d",ich), 3000,-1000,2000);
    }

  // Read ROOT input file
  TFile* file = new TFile(fin);
  TTree * T = (TTree*)file->Get("T");

  cout << "Read Tree...." << endl;
  read_tree(T);
  
  int nentries = T->GetEntries();
  cout << "We have " << nentries << " events" << endl;
  for(int ientry = 0; ientry<nentries; ientry++)
    {
      T->GetEntry(ientry);

      //initialize output variables
      for(int i=0; i<1080; i++)
	{
	  o_blockID[i] = -1;
	  o_pulseInt[i] = -1;
	  o_pulseAmp[i] = -1;
	}

      //if(ientry == this_event)
      {
	CaloData calo[1080];
	cout << "-------------Event : " <<  ientry << endl;

	// first fill a vector with all samples
	vector<double> waveform;
	for(int i=0; i<fNadcSampWaveform; i++)
	  waveform.push_back(adcSampWaveform[i]);
	
	// loop over the waveform vector
	for(int i=0; i<(int)waveform.size(); i++)
	  {
	    // For each channel, first two values are: block ID, #samples
	    if(i%(fNSamples+2) == 0)
	      {
		int blockID = int(i/(fNSamples+2));
		if(fDebug)
		  cout << "found block: " << i << " " << waveform[i] << " " << blockID << endl;
		if(blockID > 1080) cout << "*********************************ERROR: blockID out of range" << endl;

		calo[blockID].m_blockID = blockID;
		calo[blockID].m_nSamples = int(waveform.at(i+1));

		if(calo[blockID].m_nSamples != fNSamples) cout << "# of samples mismatch" << endl;

		calo[blockID].pulseAmp = 0;
		for(int j=0; j<calo[blockID].m_nSamples; j++)
		  {
		    double adc = (double)waveform.at(i+2);
		    calo[blockID].m_waveform.push_back(adc);
		    calo[blockID].pulseInt += adc;
		    if( adc > calo[blockID].pulseAmp )
		      calo[blockID].pulseAmp = adc;

		  }

		o_blockID[blockID] = blockID;
		o_pulseInt[blockID] = calo[blockID].pulseInt;
		o_pulseAmp[blockID] = calo[blockID].pulseAmp;

	      }// for each block
	  }// for

	for(int ich=0; ich<fNChannels; ich++)
	  {
	    
	    if(goodAdcPulseTime[ich]<1.e38)
	      {
		hped[icn]->Fill(goodAdcPed[ich]);
		hint[icn]->Fill(goodAdcPulseInt[ich]);
		hamp[icn]->Fill(goodAdcPulseAmp[ich]);
	      }
	  }

	tout->Fill();

	// print out calo data

	if(fDebug)
	  {
	    for(int ibl=0; ibl<1080; ibl++)
	      {
		
		cout << "BlockID: " << ibl << " " << calo[ibl].m_blockID << " pulseInt: " << calo[ibl].pulseInt << " pulseAmp: " << calo[ibl].pulseAmp << endl;
	      }
	  }// debugging
	
      }
    }//event loop

  fout->cd();
  tout->Write();
  for(int i=0; i<fNChannels; i++)
    {
      hped[ich]->Write();
      hint[ich]->Write();
      hamp[ich]->Write();
    }
  fout->Close();


}


void read_tree(TTree* tree)
{

  tree->SetBranchAddress("Ndata.NPS.cal.fly.adcSampWaveform", &fNadcSampWaveform);
  // currently max array size is 120960 (set by podd?) 1080 * 112 (blockID, # of samples, 110 samples)
  tree->SetBranchAddress("NPS.cal.fly.adcSampWaveform", adcSampWaveform);
  tree->SetBranchAddress("NPS.cal.fly.goodAdcPulseTime", goodAdcPulseTime);
  tree->SetBranchAddress("NPS.cal.fly.goodAdcPulseInt", goodAdcPulseInt);
  tree->SetBranchAddress("NPS.cal.fly.goodAdcPulseAmp", goodAdcPulseAmp);
  tree->SetBranchAddress("NPS.cal.fly.goodAdcPed", goodAdcPed);

  return;
}
  
