#include "criteriosCalificacion.h"

Criterio::Criterio(){
}

Criterio::Criterio( string identificador, string textoPresentado, float ponderado, string mensajeJurado, float notaCriterio  ){
   this -> identificador = identificador;
   this -> textoPresentado = textoPresentado;
   this -> ponderado = ponderado;
   this -> mensajeJurado = mensajeJurado;
   this -> notaCriterio = notaCriterio;
}