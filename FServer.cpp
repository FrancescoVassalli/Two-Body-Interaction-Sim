#include "FServer.h"
#include "FSubsystem.h"
using namespace std;

Fun4AllServer *Fun4AllServer::__instance = nullptr;

Fun4AllServer *Fun4AllServer::instance()
{
  if (__instance)
  {
    return __instance;
  }
  __instance = new Fun4AllServer();
  return __instance;
}

Fun4AllServer::Fun4AllServer(const std::string &name)
  : unregistersubsystem(0)
  , runnumber(0)
  , eventnumber(0)
{
  return;
}

Fun4AllServer::~Fun4AllServer()
{
  Reset();
 //delete each subsystem
 //delete each top node
 __instance = nullptr;
 return;
}

void Fun4AllServer::InitAll()
{
  //tbd
}

int Fun4AllServer::registerSubsystem(SubsysReco *subsystem)
{
  Fun4AllServer *se = Fun4AllServer::instance();
  if (Verbosity() >= VERBOSITY_SOME)
  {
    cout << "Registering Subsystem " << subsystem->Name() << endl;
  }
  Subsystems.push_back(subsystem);
  return 0;
}

int Fun4AllServer::unregisterSubsystem(SubsysReco *subsystem)
{
  //tbd
  unregistersubsystem = 1;
  return 0;
}

SubsysReco *
Fun4AllServer::getSubsysReco(const string &name)
{
  //tbd
  return 0;
}
