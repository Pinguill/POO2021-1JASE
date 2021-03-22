#ifndef CRITERIOS_H
#define CRITERIOS_H

#include <vector>
#include <iostream>
#include <string>
#include "experto.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

class Criterio{
   private:
      string identificador;
      float ponderado;
      string mensajeJurado;
      float notaCriterio;
   public:
      Criterio();
      Criterio( string, float, string, float );
      string mostrarIdentificador();
      void setNota( float );
      void setComentario( string );
      float getNotaCriterio();
      float getPonderado();
};

#endif