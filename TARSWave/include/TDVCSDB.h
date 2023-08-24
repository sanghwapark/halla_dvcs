//
// TDVCSDB.h, v1.0, Thu Mar  25 14:42:50
// Author: C. Muñoz Camacho
//

#ifndef __TDVCSDB__
#define __TDVCSDB__

#ifndef ROOT_TObject
#include "TObject.h"
#endif

#ifndef ROOT_TSystem
#include "TSystem.h"
#endif

#ifndef ROOT_TString
#include "TString.h"
#endif

#ifndef ROOT_TSQLServer
#include "TSQLServer.h"
#endif

#ifndef ROOT_TSQLResult
#include "TSQLResult.h"
#endif

#ifndef ROOT_TSQLRow
#include "TSQLRow.h"
#endif

#include <iostream>
#include <stdlib.h>
#include <fstream>

////////////////////////////////////////////////////////////////////////////////
//
// TDVCSDB.h
//
// DVCS database class
// 
////////////////////////////////////////////////////////////////////////////////

class TDVCSDB : public TObject
{
  
  private :

    TSQLServer *fServer;
    TString fUser;
  
    void UpdateLatest(char* name, char * username, char* date, char* shift, char* job);
    void ClearLatest(char* date, char* shift, char* job);

  public :

    TDVCSDB(char* db, char* host ,Int_t port, char* user);
    TDVCSDB(char* db, char* host, Int_t port, char* user, char* passwd);
    TDVCSDB(char* host ,Int_t port, char* user);
    TDVCSDB(const TDVCSDB&);
    virtual ~TDVCSDB();

    Int_t GetLastValueId(const char* nametable, Int_t run);
    Int_t CreateTable(char* nametable, char* type, Int_t number);

    //20190410(start)
    Int_t DeleteTable(char* nametable);
    //20190410(finish)
    
    Int_t AddEntry(char* tablename, Int_t runmin, Int_t runmax, Int_t col, Double_t val, char* comment=""); 
    Int_t AddEntry(char* tablename, Int_t run, Int_t runmin, Int_t runmax, Int_t col, Double_t val, char* comment=""); 
    Int_t AddEntry(char* tablename, Int_t runmin, Int_t runmax, char* filename, char* comment="");
    void AddEntry_f(char* tablename, Int_t runmin, Int_t runmax, Float_t* val, char* comment="");
    void AddEntry_d(char* tablename, Int_t runmin, Int_t runmax, Double_t* val, char* comment="");
    void AddEntry_i(char* tablename, Int_t runmin, Int_t runmax, Int_t* val, char* comment="");
    Int_t AddOneEntry(char* tablename, Int_t runmin, Int_t runmax, Double_t val, char* comment="");
    Int_t CopyEntry(char* tablename, Int_t run, Int_t runmin, Int_t runmax, char* comment="");

    void AddShift(char* name, char * username, char* date, char* shift, char* job);
    void AddNewShift(char* date, char* shift, char* job);
    void ClearShift(char* date, char* shift, char* job);
    
    Double_t* GetEntry_d(const char* tablename, Int_t run);
    Float_t* GetEntry_f(const char* tablename, Int_t run);
    Int_t* GetEntry_i(const char* tablename, Int_t run);
    
    Double_t GetEntry_d(const char* tablename, Int_t run, Int_t col);
    Float_t GetEntry_f(const char* tablename, Int_t run, Int_t col);
    Int_t GetEntry_i(const char* tablename, Int_t run, Int_t col);
    TString GetEntry_c(const char* tablename, Int_t run, Int_t col);
    
    void GetEntry(const char* tablename, Int_t run, const char* filename);
    
    TSQLServer* GetServer(void) { return fServer ; }
    
    ClassDef(TDVCSDB,1) // DVCS DataBase Class
      
      }; // End of TDVCSDB class definition

#endif
      





