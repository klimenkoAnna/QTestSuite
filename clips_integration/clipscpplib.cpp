#include <stdio.h>

#include "Clipscpp.h"

using namespace Clips;

/*
#ifndef Clips_WIN32_DLL
#if Clips_COMPILED_AS_C_PLUS_PLUS
#include "Clips.h"
#else
extern "C"
  {
   #include "Clips.h"
  }
#endif
#else
#include <windows.h>
extern "C"
{
#include "ClipsWin32.h"
}
#endif
*/

/*##################*/
/* Static Functions */
/*##################*/

#ifndef Clips_WIN32_DLL
static int ClipsCPPQuery(void *,char *);
static int ClipsCPPPrint(void *,char *,char *);
static int ClipsCPPGetc(void *,char *);
static int ClipsCPPUngetc(void *,int,char *);
static int ClipsCPPExit(void *,int);
#endif

/*#####################*/
/* ClipsCPPEnv Methods */
/*#####################*/

/***************/
/* ClipsCPPEnv */
/***************/
ClipsCPPEnv::ClipsCPPEnv()
  {
#ifndef Clips_WIN32_DLL
   theEnv = CreateEnvironment();

   SetEnvironmentContext(theEnv,this);
#else
   theEnv = __CreateEnvironment();
   /* TBD */
#endif
  }

/****************/
/* ~ClipsCPPEnv */
/****************/
ClipsCPPEnv::~ClipsCPPEnv()
  {
#ifndef Clips_WIN32_DLL
   DestroyEnvironment(theEnv);
#else
   __DestroyEnvironment(theEnv);
#endif
  }

/*********/
/* Clear */
/*********/
void ClipsCPPEnv::Clear()
  {
#ifndef Clips_WIN32_DLL
   EnvClear(theEnv);
#else
   __EnvClear(theEnv);
#endif
  }

/********/
/* Load */
/********/
int ClipsCPPEnv::Load(
  char *theFile)
  {
#ifndef Clips_WIN32_DLL
   return EnvLoad(theEnv,theFile);
#else
   return __EnvLoad(theEnv,theFile);
#endif
  }

/*********/
/* Reset */
/*********/
void ClipsCPPEnv::Reset()
  {
#ifndef Clips_WIN32_DLL
   EnvReset(theEnv);
#else
   __EnvReset(theEnv);
#endif
  }

/*******/
/* Run */
/*******/
long long ClipsCPPEnv::Run(
  long long runLimit)
  {
#ifndef Clips_WIN32_DLL
   return EnvRun(theEnv,runLimit);
#else
   return __EnvRun(theEnv,runLimit);
#endif
  }

#ifndef Clips_WIN32_DLL

/*********/
/* Watch */
/*********/
int ClipsCPPEnv::Watch(
  char *item)
  {
   return EnvWatch(theEnv,item);
  }

/***********/
/* Unwatch */
/***********/
int ClipsCPPEnv::Unwatch(
  char *item)
  {
   return EnvUnwatch(theEnv,item);
  }

/*************/
/* AddRouter */
/*************/
int ClipsCPPEnv::AddRouter(
  char *routerName,
  int priority,
  ClipsCPPRouter *router)
  {
   return EnvAddRouterWithContext(theEnv,routerName,priority,ClipsCPPQuery,
                                  ClipsCPPPrint,ClipsCPPGetc,ClipsCPPUngetc,
                                  ClipsCPPExit,router);
  }
  
/*########################*/
/* ClipsCPPRouter Methods */
/*########################*/

/*********/
/* Query */
/*********/
int ClipsCPPRouter::Query(
  ClipsCPPEnv *theCPPEnv,
  char *logicalName)
  { 
   return FALSE;
  }
  
/*********/
/* Print */
/*********/
int ClipsCPPRouter::Print(
  ClipsCPPEnv *theCPPEnv,
  char *logicalName,
  char *printString)
  {
   return FALSE;
  }
  
/********/
/* Getc */
/********/
int ClipsCPPRouter::Getc(
  ClipsCPPEnv *theCPPEnv,
  char *logicalName)
  {
   return -1;
  }
  
/**********/
/* Ungetc */
/**********/
int ClipsCPPRouter::Ungetc(
  ClipsCPPEnv *theCPPEnv,
  int character,
  char *logicalName)
  {
   return -1;
  }

/********/
/* Exit */
/********/
int ClipsCPPRouter::Exit(
  ClipsCPPEnv *theCPPEnv,
  int exitCode)
  {
   return FALSE;
  }
  
/*#########################*/
/* Static Router Functions */
/*#########################*/
  
/*****************/
/* ClipsCPPQuery */
/*****************/
static int ClipsCPPQuery(
  void *theEnv,
  char *logicalName)
  { 
   ClipsCPPRouter *theRouter = (ClipsCPPRouter *) GetEnvironmentRouterContext(theEnv);
   ClipsCPPEnv *theCPPEnv = (ClipsCPPEnv *) GetEnvironmentContext(theEnv);
   
   return(theRouter->Query(theCPPEnv,logicalName));
  }

/*****************/
/* ClipsCPPPrint */
/*****************/
static int ClipsCPPPrint(
  void *theEnv,
  char *logicalName,
  char *printString)
  { 
   ClipsCPPRouter *theRouter = (ClipsCPPRouter *) GetEnvironmentRouterContext(theEnv);
   ClipsCPPEnv *theCPPEnv = (ClipsCPPEnv *) GetEnvironmentContext(theEnv);
   
   return(theRouter->Print(theCPPEnv,logicalName,printString));
  }

/*****************/
/* ClipsCPPGetc */
/*****************/
static int ClipsCPPGetc(
  void *theEnv,
  char *logicalName)
  { 
   ClipsCPPRouter *theRouter = (ClipsCPPRouter *) GetEnvironmentRouterContext(theEnv);
   ClipsCPPEnv *theCPPEnv = (ClipsCPPEnv *) GetEnvironmentContext(theEnv);
   
   return(theRouter->Getc(theCPPEnv,logicalName));
  }
  
/*****************/
/* ClipsCPPUngetc */
/*****************/
static int ClipsCPPUngetc(
  void *theEnv,
  int character,
  char *logicalName)
  { 
   ClipsCPPRouter *theRouter = (ClipsCPPRouter *) GetEnvironmentRouterContext(theEnv);
   ClipsCPPEnv *theCPPEnv = (ClipsCPPEnv *) GetEnvironmentContext(theEnv);
   
   return(theRouter->Ungetc(theCPPEnv,character,logicalName));
  }
  
/*****************/
/* ClipsCPPExit */
/*****************/
static int ClipsCPPExit(
  void *theEnv,
  int exitCode)
  { 
   ClipsCPPRouter *theRouter = (ClipsCPPRouter *) GetEnvironmentRouterContext(theEnv);
   ClipsCPPEnv *theCPPEnv = (ClipsCPPEnv *) GetEnvironmentContext(theEnv);
   
   return(theRouter->Exit(theCPPEnv,exitCode));
  }

#endif
