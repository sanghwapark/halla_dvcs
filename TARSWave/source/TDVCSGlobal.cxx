
#include "TDVCSGlobal.h"
#include "./THaRun.h"
#include "TROOT.h"
#include "TString.h"
#include "TChain.h"
#include <iostream>
#include "TDVCSDB.h"
#include "TObjArray.h"
#include "TChainElement.h"

using namespace std;

Bool_t           TDVCSGlobal::fgTimeCorInit = kFALSE;
Bool_t           TDVCSGlobal::fgNoTimeCor = kTRUE;
TLeaf*        TDVCSGlobal::fgdp=0;
TLeaf*        TDVCSGlobal::fgs2y=0;
TLeaf*        TDVCSGlobal::fgs2rt=0;
Float_t*        TDVCSGlobal::fgcor0=0;
Float_t*        TDVCSGlobal::fgcor1=0;
Float_t*        TDVCSGlobal::fgcor1pa=0;
Float_t*        TDVCSGlobal::fgcor1veto=0;
Float_t*        TDVCSGlobal::fgcor2=0;
Float_t*        TDVCSGlobal::fgcor3=0;
Float_t*        TDVCSGlobal::fgcor4=0;
Bool_t*         TDVCSGlobal::fgstatusCalo=0;
Bool_t*         TDVCSGlobal::fgstatusPA=0;
Bool_t*         TDVCSGlobal::fgstatusVeto=0;

TDVCSChain*     TDVCSGlobal::fgTree=0;

TDVCSGlobal::TDVCSGlobal(int v):run(v)
{
  if(!wave) wave=new TARSWave(128);
  //  wave->InitAnalysisWindowDB();
  fgTimeCorInit=kFALSE;
  caloev=0;
  ev=0;
  wave=0;
  paev=0;
  vetoev=0;
  gTree=0;
  harun=0;
  currentfile="toto";
  run=9000;
  kWF=kTRUE;
  minanawin=0;//default
  maxanawin=128;//default
  fgNoTimeCor=kTRUE;
  fgstatusCalo=new Bool_t[132];
  fgstatusPA=new Bool_t[100];
  fgstatusVeto=new Bool_t[57];
}

void TDVCSGlobal::InitHRSTimeCor(TDVCSChain *tree){
  fgTree=tree;
  fgdp=tree->FindLeaf("L.tr.tg_dp");
  fgs2y=tree->FindLeaf("L.s2.try");
  fgs2rt=tree->FindLeaf("L.s2.rt");
  fgTimeCorInit=kTRUE;

  TDVCSDB *db=new TDVCSDB("dvcs","clrlpc",3306,"munoz","");
  fgcor0=db->GetEntry_f("HRS_calib_S2TDCCor",run);
  fgcor2=db->GetEntry_f("HRS_calib_S2Cor",run);
  fgcor3=db->GetEntry_f("HRS_calib_S2YCor",run);
  fgcor4=db->GetEntry_f("HRS_calib_dPCor",run);
  delete db;

  if(tree->GetBranchStatus("L.s2.try")==0) {
    cout<<"Error : You need to activate branch L.s2.try of the tree to get time corrections"<<endl;
    fgTimeCorInit=kFALSE;
  }

  if(tree->GetBranchStatus("L.s2.rt")==0) {
    cout<<"Error : You need to activate branch L.s2.rt of the tree to get time corrections"<<endl;
    fgTimeCorInit=kFALSE;
  }
  if(tree->GetBranchStatus("L.tr.tg_dp")==0) {
    cout<<"Error : You need to activate branch L.tr.tg_dp of the tree to get time corrections"<<endl;
    fgTimeCorInit=kFALSE;
  }

}

void TDVCSGlobal::GetStatusCALO(void){

  TDVCSDB *db=new TDVCSDB("dvcs","clrlpc",3306,"munoz","");
  Int_t *val=db->GetEntry_i("CALO_status",run);
  for(Int_t i=0;i<132;i++) fgstatusCalo[i]=val[i];
  delete val;
  delete db;
}
void TDVCSGlobal::GetStatusPA(void){

  TDVCSDB *db=new TDVCSDB("dvcs","clrlpc",3306,"munoz","");
  Int_t *val=db->GetEntry_i("PA_status",run);
  for(Int_t i=0;i<100;i++) fgstatusPA[i]=val[i];
  delete val;
  delete db;
}
void TDVCSGlobal::GetStatusVETO(void){

  TDVCSDB *db=new TDVCSDB("dvcs","clrlpc",3306,"munoz","");
  Int_t *val=db->GetEntry_i("VETO_status",run);
  for(Int_t i=0;i<57;i++) fgstatusVeto[i]=val[i];
  delete val;
  delete db;
}

void TDVCSGlobal::InitTimeCor(TDVCSChain *tree){

  if(fgNoTimeCor) InitHRSTimeCor(tree);

  TDVCSDB *db=new TDVCSDB("dvcs","clrlpc",3306,"munoz","");
  fgcor1=db->GetEntry_f("CALO_calib_ARSTimeOffset",run);
  fgcor1pa=db->GetEntry_f("PA_calib_ARSTimeOffset",run);
  fgcor1veto=db->GetEntry_f("VETO_calib_ARSTimeOffset",run);
  delete db;

}

void TDVCSGlobal::UpdateTimeCor(void){

  fgdp=fgTree->FindLeaf("L.tr.tg_dp");
  fgs2y=fgTree->FindLeaf("L.s2.try");
  fgs2rt=fgTree->FindLeaf("L.s2.rt");

  TDVCSDB *db=new TDVCSDB("dvcs","clrlpc",3306,"munoz","");
  Float_t *coef;  
  coef=db->GetEntry_f("HRS_calib_S2TDCCor",run);
  for(Int_t i=0;i<16;i++) fgcor0[i]=coef[i];
  delete coef;
  coef=db->GetEntry_f("CALO_calib_ARSTimeOffset",run);
  for(Int_t i=0;i<132;i++) fgcor1[i]=coef[i];
  delete coef;
  coef=db->GetEntry_f("HRS_calib_S2Cor",run);
  for(Int_t i=0;i<16;i++) fgcor2[i]=coef[i];
  delete coef;
  coef=db->GetEntry_f("HRS_calib_S2YCor",run);
  for(Int_t i=0;i<16;i++) fgcor3[i]=coef[i];
  delete coef;
  coef=db->GetEntry_f("HRS_calib_dPCor",run);
  for(Int_t i=0;i<16;i++) fgcor4[i]=coef[i];
  delete coef;
  delete db;

}



void TDVCSGlobal::Init(void){
  if(!caloev) caloev=new TCaloEvent();
  if(!ev) ev=new TDVCSEvent();
  if(!wave) wave=new TARSWave(128);
  //  wave->InitShapeAnalysis();
  if(!paev) paev=new TPAEvent();
  if(!vetoev) vetoev=new TVEvent();

  //  harun=0;
}

void TDVCSGlobal::Print() {
  cout << "This is working "<< endl;
  cout<<fgdp->GetValue(0)<<endl;
}

Bool_t TDVCSGlobal::RunChange(char* filename) {

  if(run!=GetRun(filename) && fgTimeCorInit==kTRUE) UpdateTimeCor();
  if(GetRun(filename)!=-1 && run!=GetRun(filename)){
    run=GetRun(filename);
    return kTRUE;
  }else{
    return kFALSE;
  }
  
}

Double_t TDVCSGlobal::GetTimeCor(void){

  Int_t nbs2=-1; // S2 paddle number                                                                                     
  Float_t time=0; // time correction                                                                                     
  Int_t S2_mult=0; //S2 multiplicity                                                                                     
  Int_t min=100000;
  
  for(Int_t i=0;i<16;i++) {if(fgs2rt->GetValue(i)>100.) S2_mult++;}

  if(S2_mult>0){
    for(Int_t i=0;i<16;i++) {
      if (TMath::Abs(fgs2rt->GetValue(i)-fgcor0[i])<min) { nbs2=i; min=TMath::Abs(fgs2rt->GetValue(i)-fgcor0[i]);}
    }
    
    if(nbs2==-1) {cout<<"PROBLEM in calotimecor.h !!!!"<<endl;exit(1);}
    //    time-=fgcor1[nbc]; //ARS correction                                                                                      
    time-=fgcor2[nbs2]; // S2 paddle number correction                                                                       
    time-=fgcor3[nbs2]*(fgs2y->GetValue(0)); // y position in S2 paddles correction.                                                          
    time-=fgcor4[nbs2]*(fgdp->GetValue(0)); // dp correction                                                                                  
    
    return time;
  }
  
  if(S2_mult==0){
    //    time-=fgcor1[nbc];
    time-=150;
    
    return time;
  }
}

Int_t TDVCSGlobal::GetRun(char* filename) {

  //  TString n1=filename; TString n2=currentfile;
  TString n1=filename;
  if(filename!=currentfile){

    if(harun) delete harun;
    //    TFile *file=(TFile*)(gROOT->FindObject(filename));
    TFile *file;

    TString sst=gROOT->FindObject("T")->IsA()->GetName();
    if(sst!="TDVCSChain") cout<<"ERROR: TDVCSChain is not named T"<<endl;
    fgTree=(TDVCSChain*)gROOT->FindObject("T");
    
    TObjArray *fileElements=fgTree->GetListOfFiles();
    TIter next(fileElements);
    TChainElement *chEl=0;
    while (( chEl=(TChainElement*)next() )) {
      TFile f(chEl->GetTitle());
      TString myst=f.GetName();
      if(myst==n1){
	f.GetObject("Run_Data",harun);
	currentfile=(char*)f.GetName();
      }
    }
    //    file->GetObject("Run_Data",harun);
    //  harun=(THaRun*)(file->Get("Run_Data"));
    //    currentfile=(char*)file->GetName();
    //    InitTimeCor();
  }
  if(harun) { 
    return harun->GetNumber();
  }else{
    return -1;
  }
}

Int_t TDVCSGlobal::GetTree(char * treename){
  
  TString tree=treename;
  Bool_t kcaloev=0,kpaev=0,kvetoev=0,ktree=0;
  TKey *key;TBranch *br;
  TIter next(gFile->GetListOfKeys());
  TString sol="TTree";
  while ((key = (TKey *) next())) {
    TString s = key->GetClassName();
    if(s==sol) {
      TString name;
      if(tree=="all") {
	name=key->GetName();
      }else{
	name=tree;
      }
      TIter next2(((TTree*)gFile->Get(name.Data()))->GetListOfBranches());
      TString solcalo="TCaloEvent";
      TString solpa="TPAEvent";
      TString solveto="TVEvent";
      while ((br = (TBranch *) next2())) {
	TString s2 = br->GetClassName();
	if(s2==solcalo) {
	  caloev=(TCaloEvent*)br->GetAddress();
	  cout<<"TCaloEvent found at "<<caloev<<endl;
	  kcaloev=kTRUE;ktree=kTRUE;
	}
	if(s2==solpa) {
	  paev=(TPAEvent*)br->GetAddress();
	  cout<<"TPAEvent found at "<<paev<<endl;
	  kpaev=kTRUE;ktree=kTRUE;
	}
	if(s2==solveto) {
	  vetoev=(TVEvent*)br->GetAddress();
	  cout<<"TVEvent found at "<<vetoev<<endl;
	  kvetoev=kTRUE;ktree=kTRUE;
	}
      }
    }
  }
  if(!ktree) cout<<"ERROR: No tree found"<<endl;
  if(!kcaloev) cout<<"Warning: No TCaloEvent found in this file"<<endl;
  if(!kpaev) cout<<"Warning: No TPAEvent found in this file"<<endl;
  if(!kvetoev) cout<<"Warning: No TVEvent found in this file"<<endl;

}

void TDVCSGlobal::UpdateCalo(void){

  caloev->GetGeometry()->SetRun(run);
  caloev->GetGeometry()->InitPositionsDB();
  caloev->GetCalibration()->InitDB(run);
  caloev->GetParameters()->InitDB(run);
  GetStatusCALO();
  cout<<"Calorimeter geometry, parameters and calibration coefficients for run "<<run<<" loaded from mysql database."<<endl;

}

void TDVCSGlobal::UpdatePA(void){
  paev->GetCalibration()->InitDB(run);
  paev->GetGeometry()->InitDB(run);
  cout<<"PA calibration and geometry for run "<<run<<" updated."<<endl;
  GetStatusPA();
}

void TDVCSGlobal::UpdateVeto(void){
  vetoev->GetCalibration()->InitDB(run);
  cout<<"Veto calibration for run "<<run<<" updated."<<endl;
  GetStatusVETO();
}

void TDVCSGlobal::UpdatePedestals(void){

  wave->InitPedDB(run);
  cout<<"ARS pedestals for run "<<run<<" loaded from mysql database."<<endl;

}

void TDVCSGlobal::UpdateDVCS(void){

  ev->GetGeometry()->SetRun(run);
  ev->GetGeometry()->InitDB();
  ev->GetParameters()->InitDB(run);
  cout<<"DVCS geometry and parameters for run "<<run<<" loaded from mysql database."<<endl;
}

void TDVCSGlobal::Update(char* filename){
 
  Init();
  if(RunChange(filename)) {
    cout<<"updating"<<endl;
    UpdatePedestals();
    UpdateDVCS();
    UpdateCalo();
    UpdatePA();
    UpdateVeto();
    if(kWF) UpdateWFAna();
    if(fgTimeCorInit) UpdateTimeCor();
  }
}

void TDVCSGlobal::ForceUpdate(void){
  Init();
  
  UpdatePedestals();
  UpdateDVCS();
  UpdateCalo();
  UpdatePA();
  UpdateVeto();
  if(kWF) UpdateWFAna();
  if(fgTimeCorInit) UpdateTimeCor();
  
}

void TDVCSGlobal::UpdateWFAna(void){
//   Double_t chi20=wave->GetChi20();
//   Double_t chi21=wave->GetChi21();
//   Double_t chi22=wave->GetChi22();
//  wave->SetAnalysisWindow(minanawin,maxanawin);
  TString line("garswave->InitShapeAnalysisDB(");line+=run;line+=");";
  gROOT->ProcessLine(line.Data());

//   wave->SetFirstWindow(-10,10,"data",kTRUE);
//   wave->SetSecondWindow(-10,10,-10,10,"data",kTRUE);
  wave->InitPedSigmaDB(run);
//   wave->SetChi20(chi20);
//   wave->SetChi21(chi21);
//   wave->SetChi22(chi22);

}
