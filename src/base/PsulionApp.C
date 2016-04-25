#include "PsulionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

//
// Incompressible
//

// Kernels
#include "INSMass.h"
#include "INSMomentum.h"

// BCs

// AuxKernels

// DiracKernels
#include "VelocityDirac.h"

// Postprocessors

template<>
InputParameters validParams<PsulionApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

PsulionApp::PsulionApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  PsulionApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  PsulionApp::associateSyntax(_syntax, _action_factory);
}

PsulionApp::~PsulionApp()
{
}

// External entry point for dynamic application loading
extern "C" void PsulionApp__registerApps() { PsulionApp::registerApps(); }
void
PsulionApp::registerApps()
{
  registerApp(PsulionApp);
}

// External entry point for dynamic object registration
extern "C" void PsulionApp__registerObjects(Factory & factory) { PsulionApp::registerObjects(factory); }
void
PsulionApp::registerObjects(Factory & factory)
{
registerKernel(VelocityDirac);
}

// External entry point for dynamic syntax association
extern "C" void PsulionApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { PsulionApp::associateSyntax(syntax, action_factory); }
void
PsulionApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
