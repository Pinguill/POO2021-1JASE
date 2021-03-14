#ifndef CRITERIOS_H
#define CRITERIOS_H

#include <vector>
#include <iostream>
using std::vector;
using std::string;

vector <string> identificador;
vector <string> textoPresentado;
vector <float> ponderado;
vector <string> mensajeJurado;
vector <float> notaCriterio;

class Criterio{
   private:
      string identificador;
      string textoPresentado;
      float ponderado;
      string mensajeJurado;
      string notaCriterio;
   public:
      Criterio();
      Criterio( string, string, float, string );
      void llenarCriterio();
      void escribirMensaje();
};

#endif