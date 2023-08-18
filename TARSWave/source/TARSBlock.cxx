//
// TARSBlock.cxx, v1.0, Thu Dec  5 14:42:50
// Author: C. Muñoz
//

#include <iostream>
#include "TARSBlock.h"
#include "TARSBase.h"

ClassImp(TARSBlock)

////////////////////////////////////////////////////////////////////////////////
//
// DVCS ARS raw data class
// 
////////////////////////////////////////////////////////////////////////////////

//_____________________________________________________________________________
 TARSBlock::TARSBlock()
{
  // Default constructor
  //  gTARSBlock = this;
  //  cout<<"TARSBlock constructor"<<endl;
}

//_____________________________________________________________________________
 TARSBlock::TARSBlock(const TARSBlock& block)
{
  // Copy constructor
  fBlockNb= block.fBlockNb;
  //  fWave= block.fWave;
  //((TARSBlock&)TARSblock).Copy(*this);
  
}

//_____________________________________________________________________________
 void TARSBlock::Copy(TObject& obj)
{

  // Copy routine. Used by copy ctor.

  //  TObject::Copy(obj);
  
  //  fgParameters.Copy(((TARSBase&)obj).fgParameters);
  //  ((TARSBase&)obj).fgIsInit = fgIsInit;

}

//_____________________________________________________________________________
 TARSBlock::~TARSBlock()
{
  // Default destructor
  // cout<<"TARSBlock destructor"<<endl;
}

//_____________________________________________________________________________
 void TARSBlock::Print(char* opt)
{
  // Output on screen
  cout<<"Block number = "<<fBlockNb<<endl;
}













