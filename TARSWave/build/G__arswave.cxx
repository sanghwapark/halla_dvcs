// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__arswave
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "TARSBase.h"
#include "TARSArray.h"
#include "TARSConst.h"
#include "TARSParameters.h"
#include "TARSCalibration.h"
#include "TARSBlock.h"
#include "TARSWave.h"
#include "TDVCSDB.h"
#include "TDoubleArray.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TDoubleArray(void *p = 0);
   static void *newArray_TDoubleArray(Long_t size, void *p);
   static void delete_TDoubleArray(void *p);
   static void deleteArray_TDoubleArray(void *p);
   static void destruct_TDoubleArray(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDoubleArray*)
   {
      ::TDoubleArray *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TDoubleArray >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TDoubleArray", ::TDoubleArray::Class_Version(), "TDoubleArray.h", 17,
                  typeid(::TDoubleArray), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TDoubleArray::Dictionary, isa_proxy, 4,
                  sizeof(::TDoubleArray) );
      instance.SetNew(&new_TDoubleArray);
      instance.SetNewArray(&newArray_TDoubleArray);
      instance.SetDelete(&delete_TDoubleArray);
      instance.SetDeleteArray(&deleteArray_TDoubleArray);
      instance.SetDestructor(&destruct_TDoubleArray);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDoubleArray*)
   {
      return GenerateInitInstanceLocal((::TDoubleArray*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDoubleArray*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TARSParameters(void *p = 0);
   static void *newArray_TARSParameters(Long_t size, void *p);
   static void delete_TARSParameters(void *p);
   static void deleteArray_TARSParameters(void *p);
   static void destruct_TARSParameters(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TARSParameters*)
   {
      ::TARSParameters *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TARSParameters >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TARSParameters", ::TARSParameters::Class_Version(), "TARSParameters.h", 28,
                  typeid(::TARSParameters), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TARSParameters::Dictionary, isa_proxy, 4,
                  sizeof(::TARSParameters) );
      instance.SetNew(&new_TARSParameters);
      instance.SetNewArray(&newArray_TARSParameters);
      instance.SetDelete(&delete_TARSParameters);
      instance.SetDeleteArray(&deleteArray_TARSParameters);
      instance.SetDestructor(&destruct_TARSParameters);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TARSParameters*)
   {
      return GenerateInitInstanceLocal((::TARSParameters*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TARSParameters*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TARSConst(void *p = 0);
   static void *newArray_TARSConst(Long_t size, void *p);
   static void delete_TARSConst(void *p);
   static void deleteArray_TARSConst(void *p);
   static void destruct_TARSConst(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TARSConst*)
   {
      ::TARSConst *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TARSConst >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TARSConst", ::TARSConst::Class_Version(), "TARSConst.h", 22,
                  typeid(::TARSConst), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TARSConst::Dictionary, isa_proxy, 4,
                  sizeof(::TARSConst) );
      instance.SetNew(&new_TARSConst);
      instance.SetNewArray(&newArray_TARSConst);
      instance.SetDelete(&delete_TARSConst);
      instance.SetDeleteArray(&deleteArray_TARSConst);
      instance.SetDestructor(&destruct_TARSConst);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TARSConst*)
   {
      return GenerateInitInstanceLocal((::TARSConst*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TARSConst*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TARSCalibration(void *p = 0);
   static void *newArray_TARSCalibration(Long_t size, void *p);
   static void delete_TARSCalibration(void *p);
   static void deleteArray_TARSCalibration(void *p);
   static void destruct_TARSCalibration(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TARSCalibration*)
   {
      ::TARSCalibration *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TARSCalibration >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TARSCalibration", ::TARSCalibration::Class_Version(), "TARSCalibration.h", 17,
                  typeid(::TARSCalibration), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TARSCalibration::Dictionary, isa_proxy, 4,
                  sizeof(::TARSCalibration) );
      instance.SetNew(&new_TARSCalibration);
      instance.SetNewArray(&newArray_TARSCalibration);
      instance.SetDelete(&delete_TARSCalibration);
      instance.SetDeleteArray(&deleteArray_TARSCalibration);
      instance.SetDestructor(&destruct_TARSCalibration);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TARSCalibration*)
   {
      return GenerateInitInstanceLocal((::TARSCalibration*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TARSCalibration*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TARSBase(void *p = 0);
   static void *newArray_TARSBase(Long_t size, void *p);
   static void delete_TARSBase(void *p);
   static void deleteArray_TARSBase(void *p);
   static void destruct_TARSBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TARSBase*)
   {
      ::TARSBase *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TARSBase >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TARSBase", ::TARSBase::Class_Version(), "TARSBase.h", 24,
                  typeid(::TARSBase), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TARSBase::Dictionary, isa_proxy, 4,
                  sizeof(::TARSBase) );
      instance.SetNew(&new_TARSBase);
      instance.SetNewArray(&newArray_TARSBase);
      instance.SetDelete(&delete_TARSBase);
      instance.SetDeleteArray(&deleteArray_TARSBase);
      instance.SetDestructor(&destruct_TARSBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TARSBase*)
   {
      return GenerateInitInstanceLocal((::TARSBase*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TARSBase*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TARSWave(void *p = 0);
   static void *newArray_TARSWave(Long_t size, void *p);
   static void delete_TARSWave(void *p);
   static void deleteArray_TARSWave(void *p);
   static void destruct_TARSWave(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TARSWave*)
   {
      ::TARSWave *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TARSWave >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TARSWave", ::TARSWave::Class_Version(), "TARSWave.h", 43,
                  typeid(::TARSWave), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TARSWave::Dictionary, isa_proxy, 4,
                  sizeof(::TARSWave) );
      instance.SetNew(&new_TARSWave);
      instance.SetNewArray(&newArray_TARSWave);
      instance.SetDelete(&delete_TARSWave);
      instance.SetDeleteArray(&deleteArray_TARSWave);
      instance.SetDestructor(&destruct_TARSWave);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TARSWave*)
   {
      return GenerateInitInstanceLocal((::TARSWave*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TARSWave*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TARSArray(void *p = 0);
   static void *newArray_TARSArray(Long_t size, void *p);
   static void delete_TARSArray(void *p);
   static void deleteArray_TARSArray(void *p);
   static void destruct_TARSArray(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TARSArray*)
   {
      ::TARSArray *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TARSArray >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TARSArray", ::TARSArray::Class_Version(), "TARSArray.h", 29,
                  typeid(::TARSArray), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TARSArray::Dictionary, isa_proxy, 4,
                  sizeof(::TARSArray) );
      instance.SetNew(&new_TARSArray);
      instance.SetNewArray(&newArray_TARSArray);
      instance.SetDelete(&delete_TARSArray);
      instance.SetDeleteArray(&deleteArray_TARSArray);
      instance.SetDestructor(&destruct_TARSArray);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TARSArray*)
   {
      return GenerateInitInstanceLocal((::TARSArray*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TARSArray*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TARSBlock(void *p = 0);
   static void *newArray_TARSBlock(Long_t size, void *p);
   static void delete_TARSBlock(void *p);
   static void deleteArray_TARSBlock(void *p);
   static void destruct_TARSBlock(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TARSBlock*)
   {
      ::TARSBlock *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TARSBlock >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TARSBlock", ::TARSBlock::Class_Version(), "TARSBlock.h", 25,
                  typeid(::TARSBlock), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TARSBlock::Dictionary, isa_proxy, 4,
                  sizeof(::TARSBlock) );
      instance.SetNew(&new_TARSBlock);
      instance.SetNewArray(&newArray_TARSBlock);
      instance.SetDelete(&delete_TARSBlock);
      instance.SetDeleteArray(&deleteArray_TARSBlock);
      instance.SetDestructor(&destruct_TARSBlock);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TARSBlock*)
   {
      return GenerateInitInstanceLocal((::TARSBlock*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TARSBlock*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TDoubleArray::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TDoubleArray::Class_Name()
{
   return "TDoubleArray";
}

//______________________________________________________________________________
const char *TDoubleArray::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDoubleArray*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TDoubleArray::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDoubleArray*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TDoubleArray::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDoubleArray*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TDoubleArray::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDoubleArray*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TARSParameters::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TARSParameters::Class_Name()
{
   return "TARSParameters";
}

//______________________________________________________________________________
const char *TARSParameters::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSParameters*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TARSParameters::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSParameters*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TARSParameters::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSParameters*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TARSParameters::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSParameters*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TARSConst::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TARSConst::Class_Name()
{
   return "TARSConst";
}

//______________________________________________________________________________
const char *TARSConst::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSConst*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TARSConst::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSConst*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TARSConst::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSConst*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TARSConst::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSConst*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TARSCalibration::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TARSCalibration::Class_Name()
{
   return "TARSCalibration";
}

//______________________________________________________________________________
const char *TARSCalibration::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSCalibration*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TARSCalibration::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSCalibration*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TARSCalibration::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSCalibration*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TARSCalibration::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSCalibration*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TARSBase::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TARSBase::Class_Name()
{
   return "TARSBase";
}

//______________________________________________________________________________
const char *TARSBase::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSBase*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TARSBase::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSBase*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TARSBase::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSBase*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TARSBase::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSBase*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TARSWave::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TARSWave::Class_Name()
{
   return "TARSWave";
}

//______________________________________________________________________________
const char *TARSWave::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSWave*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TARSWave::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSWave*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TARSWave::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSWave*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TARSWave::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSWave*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TARSArray::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TARSArray::Class_Name()
{
   return "TARSArray";
}

//______________________________________________________________________________
const char *TARSArray::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSArray*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TARSArray::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSArray*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TARSArray::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSArray*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TARSArray::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSArray*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TARSBlock::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TARSBlock::Class_Name()
{
   return "TARSBlock";
}

//______________________________________________________________________________
const char *TARSBlock::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSBlock*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TARSBlock::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TARSBlock*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TARSBlock::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSBlock*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TARSBlock::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TARSBlock*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TDoubleArray::Streamer(TBuffer &R__b)
{
   // Stream an object of class TDoubleArray.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TDoubleArray::Class(),this);
   } else {
      R__b.WriteClassBuffer(TDoubleArray::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TDoubleArray(void *p) {
      return  p ? new(p) ::TDoubleArray : new ::TDoubleArray;
   }
   static void *newArray_TDoubleArray(Long_t nElements, void *p) {
      return p ? new(p) ::TDoubleArray[nElements] : new ::TDoubleArray[nElements];
   }
   // Wrapper around operator delete
   static void delete_TDoubleArray(void *p) {
      delete ((::TDoubleArray*)p);
   }
   static void deleteArray_TDoubleArray(void *p) {
      delete [] ((::TDoubleArray*)p);
   }
   static void destruct_TDoubleArray(void *p) {
      typedef ::TDoubleArray current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TDoubleArray

//______________________________________________________________________________
void TARSParameters::Streamer(TBuffer &R__b)
{
   // Stream an object of class TARSParameters.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TARSParameters::Class(),this);
   } else {
      R__b.WriteClassBuffer(TARSParameters::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TARSParameters(void *p) {
      return  p ? new(p) ::TARSParameters : new ::TARSParameters;
   }
   static void *newArray_TARSParameters(Long_t nElements, void *p) {
      return p ? new(p) ::TARSParameters[nElements] : new ::TARSParameters[nElements];
   }
   // Wrapper around operator delete
   static void delete_TARSParameters(void *p) {
      delete ((::TARSParameters*)p);
   }
   static void deleteArray_TARSParameters(void *p) {
      delete [] ((::TARSParameters*)p);
   }
   static void destruct_TARSParameters(void *p) {
      typedef ::TARSParameters current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TARSParameters

//______________________________________________________________________________
void TARSConst::Streamer(TBuffer &R__b)
{
   // Stream an object of class TARSConst.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TARSConst::Class(),this);
   } else {
      R__b.WriteClassBuffer(TARSConst::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TARSConst(void *p) {
      return  p ? new(p) ::TARSConst : new ::TARSConst;
   }
   static void *newArray_TARSConst(Long_t nElements, void *p) {
      return p ? new(p) ::TARSConst[nElements] : new ::TARSConst[nElements];
   }
   // Wrapper around operator delete
   static void delete_TARSConst(void *p) {
      delete ((::TARSConst*)p);
   }
   static void deleteArray_TARSConst(void *p) {
      delete [] ((::TARSConst*)p);
   }
   static void destruct_TARSConst(void *p) {
      typedef ::TARSConst current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TARSConst

//______________________________________________________________________________
void TARSCalibration::Streamer(TBuffer &R__b)
{
   // Stream an object of class TARSCalibration.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TARSCalibration::Class(),this);
   } else {
      R__b.WriteClassBuffer(TARSCalibration::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TARSCalibration(void *p) {
      return  p ? new(p) ::TARSCalibration : new ::TARSCalibration;
   }
   static void *newArray_TARSCalibration(Long_t nElements, void *p) {
      return p ? new(p) ::TARSCalibration[nElements] : new ::TARSCalibration[nElements];
   }
   // Wrapper around operator delete
   static void delete_TARSCalibration(void *p) {
      delete ((::TARSCalibration*)p);
   }
   static void deleteArray_TARSCalibration(void *p) {
      delete [] ((::TARSCalibration*)p);
   }
   static void destruct_TARSCalibration(void *p) {
      typedef ::TARSCalibration current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TARSCalibration

//______________________________________________________________________________
void TARSBase::Streamer(TBuffer &R__b)
{
   // Stream an object of class TARSBase.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TARSBase::Class(),this);
   } else {
      R__b.WriteClassBuffer(TARSBase::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TARSBase(void *p) {
      return  p ? new(p) ::TARSBase : new ::TARSBase;
   }
   static void *newArray_TARSBase(Long_t nElements, void *p) {
      return p ? new(p) ::TARSBase[nElements] : new ::TARSBase[nElements];
   }
   // Wrapper around operator delete
   static void delete_TARSBase(void *p) {
      delete ((::TARSBase*)p);
   }
   static void deleteArray_TARSBase(void *p) {
      delete [] ((::TARSBase*)p);
   }
   static void destruct_TARSBase(void *p) {
      typedef ::TARSBase current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TARSBase

//______________________________________________________________________________
void TARSWave::Streamer(TBuffer &R__b)
{
   // Stream an object of class TARSWave.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TARSWave::Class(),this);
   } else {
      R__b.WriteClassBuffer(TARSWave::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TARSWave(void *p) {
      return  p ? new(p) ::TARSWave : new ::TARSWave;
   }
   static void *newArray_TARSWave(Long_t nElements, void *p) {
      return p ? new(p) ::TARSWave[nElements] : new ::TARSWave[nElements];
   }
   // Wrapper around operator delete
   static void delete_TARSWave(void *p) {
      delete ((::TARSWave*)p);
   }
   static void deleteArray_TARSWave(void *p) {
      delete [] ((::TARSWave*)p);
   }
   static void destruct_TARSWave(void *p) {
      typedef ::TARSWave current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TARSWave

//______________________________________________________________________________
void TARSArray::Streamer(TBuffer &R__b)
{
   // Stream an object of class TARSArray.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TARSArray::Class(),this);
   } else {
      R__b.WriteClassBuffer(TARSArray::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TARSArray(void *p) {
      return  p ? new(p) ::TARSArray : new ::TARSArray;
   }
   static void *newArray_TARSArray(Long_t nElements, void *p) {
      return p ? new(p) ::TARSArray[nElements] : new ::TARSArray[nElements];
   }
   // Wrapper around operator delete
   static void delete_TARSArray(void *p) {
      delete ((::TARSArray*)p);
   }
   static void deleteArray_TARSArray(void *p) {
      delete [] ((::TARSArray*)p);
   }
   static void destruct_TARSArray(void *p) {
      typedef ::TARSArray current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TARSArray

//______________________________________________________________________________
void TARSBlock::Streamer(TBuffer &R__b)
{
   // Stream an object of class TARSBlock.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TARSBlock::Class(),this);
   } else {
      R__b.WriteClassBuffer(TARSBlock::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TARSBlock(void *p) {
      return  p ? new(p) ::TARSBlock : new ::TARSBlock;
   }
   static void *newArray_TARSBlock(Long_t nElements, void *p) {
      return p ? new(p) ::TARSBlock[nElements] : new ::TARSBlock[nElements];
   }
   // Wrapper around operator delete
   static void delete_TARSBlock(void *p) {
      delete ((::TARSBlock*)p);
   }
   static void deleteArray_TARSBlock(void *p) {
      delete [] ((::TARSBlock*)p);
   }
   static void destruct_TARSBlock(void *p) {
      typedef ::TARSBlock current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TARSBlock

namespace {
  void TriggerDictionaryInitialization_libarswave_Impl() {
    static const char* headers[] = {
"TARSBase.h",
"TARSArray.h",
"TARSConst.h",
"TARSParameters.h",
"TARSCalibration.h",
"TARSBlock.h",
"TARSWave.h",
"TDVCSDB.h",
"TDoubleArray.h",
0
    };
    static const char* includePaths[] = {
"/home/sanghwa/work/tools/root/include",
"/home/sanghwa/work/jeffersonlab/hallc/nps/offline/TARSWave/include",
"/home/sanghwa/work/jeffersonlab/hallc/nps/offline/TARSWave",
"/home/sanghwa/work/tools/root/include/",
"/home/sanghwa/work/jeffersonlab/hallc/nps/offline/TARSWave/build/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libarswave dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TDoubleArray.h")))  __attribute__((annotate("$clingAutoload$TARSBase.h")))  TDoubleArray;
class __attribute__((annotate("$clingAutoload$TARSParameters.h")))  __attribute__((annotate("$clingAutoload$TARSBase.h")))  TARSParameters;
class __attribute__((annotate("$clingAutoload$TARSConst.h")))  __attribute__((annotate("$clingAutoload$TARSBase.h")))  TARSConst;
class __attribute__((annotate("$clingAutoload$TARSCalibration.h")))  __attribute__((annotate("$clingAutoload$TARSBase.h")))  TARSCalibration;
class __attribute__((annotate(R"ATTRDUMP(ARS Base Class)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TARSBase.h")))  TARSBase;
class __attribute__((annotate("$clingAutoload$TARSWave.h")))  __attribute__((annotate("$clingAutoload$TARSArray.h")))  TARSWave;
class __attribute__((annotate(R"ATTRDUMP(ARS Array Class)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TARSArray.h")))  TARSArray;
class __attribute__((annotate(R"ATTRDUMP(DVCS ARSrimeter Block Class)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TARSBlock.h")))  TARSBlock;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libarswave dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TARSBase.h"
#include "TARSArray.h"
#include "TARSConst.h"
#include "TARSParameters.h"
#include "TARSCalibration.h"
#include "TARSBlock.h"
#include "TARSWave.h"
#include "TDVCSDB.h"
#include "TDoubleArray.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TARSArray", payloadCode, "@",
"TARSBase", payloadCode, "@",
"TARSBlock", payloadCode, "@",
"TARSCalibration", payloadCode, "@",
"TARSConst", payloadCode, "@",
"TARSParameters", payloadCode, "@",
"TARSWave", payloadCode, "@",
"TDoubleArray", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libarswave",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libarswave_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libarswave_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libarswave() {
  TriggerDictionaryInitialization_libarswave_Impl();
}
