#ifndef CRITERIOS_H
#define CRITERIOS_H

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

class Criterio{
   private:
      string identificador;
      string textoPresentado;
      float ponderado;
      string mensajeJurado;
      float notaJurado1 = 0;
      float notaJurado2 = 0;
      float notaCriterio;
      vector <Criterio> listaCriterios;
      
   public:
      Criterio();
      Criterio( string, string, float, string, float );
      void llenarCriterio();
      void calificarCriterio();
      void escribirMensaje();
      void imprimirMensaje();
      void consultarListaCriterios();
};

#endif