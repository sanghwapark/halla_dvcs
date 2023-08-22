{

  ifstream f("initdata/refshapecalo.txt");
  Double_t val=0.;
  TARSWave *w=new TARSWave(110);
  w->SetNbChannel(0, "CALO");
  for (Int_t j=0;j<20;j++) w->SetValue(j,200);
  for(Int_t j=0;j<110;j++){
    f>>val;
    cout<<j<<" " << val<<endl;
    if(j+20<110) 
      w->SetValue(j+20,-val*3.56+200);
  }
  TCanvas *c=new TCanvas();
  w->DrawRaw(c);
  c->Update();
  c->Modified();
  w->Analyze("data");
  //  w->GetFit("data")->Draw();

}
