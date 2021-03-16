#ifndef CRITERIOS_H
#define CRITERIOS_H

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;

class Criterio{
   private:
      string identificador;
      string textoPresentado;
      float ponderado;
      string mensajeJurado;
      float notaCriterio;
   public:
      Criterio();
      Criterio( string, string, float, string, float );
      void llenarCriterio();
      void escribirMensaje();
};

#endif