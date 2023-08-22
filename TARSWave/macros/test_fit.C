{


  TARSWave* w = new TARSWave(128);
  w->SetNbChannel(0,"CALO");

  ifstream ifstr("shape.dat");
  double val;
  for(int i=0; i<128; i++) {
    w->SetValue(i,val);
  }

  TCanvas* c = new TCanvas();
  w->DrawRaw(c);
  c->Update();
  c->Modified();
  
}
