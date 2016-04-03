#ifndef PSULIONAPP_H
#define PSULIONAPP_H

#include "MooseApp.h"

class PsulionApp;

template<>
InputParameters validParams<PsulionApp>();

class PsulionApp : public MooseApp
{
public:
  PsulionApp(InputParameters parameters);
  virtual ~PsulionApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* PSULIONAPP_H */
