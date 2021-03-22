#include "criteriosCalificacion.h"


Criterio::Criterio(){
}

Criterio::Criterio( string identificador, float ponderado, string mensajeJurado, float notaCriterio  )
{
   this -> identificador = identificador;
   this -> ponderado = ponderado;
   this -> mensajeJurado = mensajeJurado;
   this -> notaCriterio = notaCriterio;
}

string Criterio::mostrarIdentificador(){
   return this->identificador;
}

void Criterio::setNota( float nota ){
   float result;
   result = nota * (this->ponderado / 100);
   this->notaCriterio = result;
}

string Criterio::getComentario(){
   return this->mensajeJurado;
}

void Criterio::setComentario( string comentario ){
   this->mensajeJurado = comentario;
}

float Criterio::getNotaCriterio(){
   return this->notaCriterio;
}

float Criterio::getPonderado(){
   return this->ponderado;
}
