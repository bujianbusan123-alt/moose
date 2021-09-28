//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "firstappTestApp.h"
#include "firstappApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
firstappTestApp::validParams()
{
  InputParameters params = firstappApp::validParams();
  return params;
}

firstappTestApp::firstappTestApp(InputParameters parameters) : MooseApp(parameters)
{
  firstappTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

firstappTestApp::~firstappTestApp() {}

void
firstappTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  firstappApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"firstappTestApp"});
    Registry::registerActionsTo(af, {"firstappTestApp"});
  }
}

void
firstappTestApp::registerApps()
{
  registerApp(firstappApp);
  registerApp(firstappTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
firstappTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  firstappTestApp::registerAll(f, af, s);
}
extern "C" void
firstappTestApp__registerApps()
{
  firstappTestApp::registerApps();
}
