
#include "TCaloEvent.h"
#include "TDVCSEvent.h"
#include "TPAEvent.h"
#include "TVEvent.h"
#include "TARSWave.h"
#include "TChain.h"
#include "TTree.h"
#include "TFile.h"
#include "TKey.h"
#include "TBranch.h"
#include "TLeaf.h"
#include "THaRun.h"
#include "TDVCSChain.h"

#ifndef _TDVCSGLOBAL_
#define _TDVCSGLOBAL_
class TDVCSGlobal {

 public:
  TDVCSGlobal(int v);

  void Print();
  Int_t GetTree(char *treename="all");
  Int_t GetRun(char* filename);
  TARSWave* GetWave(void) {return wave;}
  Bool_t RunChange(char* filename);
  void UpdateCalo(void);
  void UpdatePA(void);
  void UpdateVeto(void);
  void UpdateDVCS(void);
  void UpdatePedestals(void);
  void UpdateWFAna(void);
  void Update(char* filename);
  void UpdateTimeCor(void);
  void Init(void);
  void SetWF(Bool_t val) {kWF=val;}
  void InitHRSTimeCor(TDVCSChain *tree);
  Bool_t TimeCorIsInit(void) { return fgTimeCorInit; }
  void SetTimeCor(Bool_t val=kFALSE) { fgNoTimeCor=val;}
  void InitTimeCor(TDVCSChain *tree);
  Double_t GetTimeCor(void);
  Double_t GetARSCor(Int_t blocknb) { return fgcor1[blocknb] ; }
  Double_t GetARSCorPA(Int_t blocknb) { return fgcor1pa[blocknb] ; }
  Double_t GetARSCorVETO(Int_t blocknb) { return fgcor1veto[blocknb] ; }
  void SetAnalysisWindow(Int_t min,Int_t max) { minanawin=min;maxanawin=max;}
  void SetRun(Int_t n) {run=n;}
  void ForceUpdate(void);
  void GetStatusCALO(void);
  void GetStatusPA(void);
  void GetStatusVETO(void);
  Bool_t GetPAStatus(Int_t n) {return fgstatusPA[n];}
  Bool_t GetCaloStatus(Int_t n) {return fgstatusCalo[n];}
  Bool_t GetVetoStatus(Int_t n) {return fgstatusVeto[n];}

 private:

  static Bool_t fgTimeCorInit;
  static Bool_t fgNoTimeCor;
  static TLeaf *fgdp;
  static TLeaf *fgs2y;
  static TLeaf *fgs2rt;
  static Float_t *fgcor0;
  static Float_t *fgcor1;
  static Float_t *fgcor1pa;
  static Float_t *fgcor1veto;
  static Float_t *fgcor2;
  static Float_t *fgcor3;
  static Float_t *fgcor4;
  static Bool_t *fgstatusCalo;
  static Bool_t *fgstatusPA;
  static Bool_t *fgstatusVeto;
  static TDVCSChain *fgTree;

  char* currentfile;
  THaRun *harun;
  TCaloEvent *caloev;
  TDVCSEvent *ev;
  TARSWave *wave;
  TPAEvent *paev;
  TVEvent *vetoev;
  TTree *gTree;
  Bool_t kWF;
  Int_t run;
  Int_t minanawin;
  Int_t maxanawin;

};
#endif
