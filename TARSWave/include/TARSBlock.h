//
// TARSBlock.h, v1.0, Thu Dec  5 14:42:50
// 
//

#ifndef __TARSBlock__
#define __TARSBlock__


#include "TShortArray.h"
#include "TARSWave.h"
#include "TARSBase.h"
#include "TObject.h"

////////////////////////////////////////////////////////////////////////////////
//
// TARSBlock.h
//
// DVCS ARSrimeter block class
// 
////////////////////////////////////////////////////////////////////////////////

using namespace std;

class TARSBlock : public TARSBase
{
  
  private :
    Int_t   fBlockNb;
  //    TARSWave fWave;

  public :

  TARSBlock();
  TARSBlock(const TARSBlock&);
  virtual ~TARSBlock();
  virtual void Copy(TObject&);

  void SetBlockNumber(Int_t blocknb) { fBlockNb=blocknb ; }
  Int_t GetBlockNumber(void) { return fBlockNb ; }
  virtual void Print(char* opt="");

  ClassDef(TARSBlock,1) // DVCS ARSrimeter Block Class

}; // End of TARSBlock class definition

#endif






