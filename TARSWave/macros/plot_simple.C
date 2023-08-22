void plot_simple(TString fin)
{
  vector<double> m_ref;
  double adc;
  ifstream ifstr(fin);
  int nsamples=0;
  while(ifstr >> adc)
    {
      m_ref.push_back(adc);
      nsamples++;
    }
  
  TH1F* h1 = new TH1F("h1", "sample shape", nsamples, 0, nsamples);
  for(int i=0; i<nsamples; i++)
    h1->SetBinContent(i+1, m_ref[i]);
  h1->Draw();

}
