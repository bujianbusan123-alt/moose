#include "firstappApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
firstappApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

firstappApp::firstappApp(InputParameters parameters) : MooseApp(parameters)
{
  firstappApp::registerAll(_factory, _action_factory, _syntax);
}

firstappApp::~firstappApp() {}

void
firstappApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"firstappApp"});
  Registry::registerActionsTo(af, {"firstappApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
firstappApp::registerApps()
{
  registerApp(firstappApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
firstappApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  firstappApp::registerAll(f, af, s);
}
extern "C" void
firstappApp__registerApps()
{
  firstappApp::registerApps();
}
