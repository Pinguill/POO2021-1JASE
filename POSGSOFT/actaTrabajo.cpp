#include <iostream>
#include "actaTrabajo.h"
#include "conjuntoLista.h"

using std::cout;
using std::cin;
using std::getline;

ActaTrabajo::ActaTrabajo()
{
}

ActaTrabajo::ActaTrabajo( int numero, string fecha, string autor, string nombreTrabajo, trabajo tipoTrabajo, 
    string periodo, string director,  string codirector, string jurado1, string jurado2, 
    estado estadoTrabajo, aceptacion estadoAceptacion )
{
    // Asignar valores 
    this -> numero = numero;
    this-> fecha = fecha;
    this -> autor = autor;
    this -> nombreTrabajo = nombreTrabajo;
    this -> tipoTrabajo = tipoTrabajo;
    this -> periodo = periodo;
    this -> director = director;
    this -> codirector = codirector;
    this -> jurado1 = jurado1;
    this -> jurado2 = jurado2;
    this -> estadoTrabajo = estadoTrabajo;
    this -> estadoAceptacion = estadoAceptacion;
}

// Destructor, lo dejaremos vacío, para indicar que el acta esté cerrada de forma efectiva, lo haremos en el main 
ActaTrabajo::~ActaTrabajo(){
}

trabajo ActaTrabajo::getTipoTrabajo(){
   return this->tipoTrabajo;
}

aceptacion ActaTrabajo::getEstadoAceptacion(){
   return this->estadoAceptacion;
}

string ActaTrabajo::getNombreTrabajo(){
   return this->nombreTrabajo;
}

int ActaTrabajo::getNumeroActa(){
   return this->numero;
}

estado ActaTrabajo::getEstadoTrabajo(){
   return this->estadoTrabajo;
}

void ActaTrabajo::setEstadoTrabajo( estado estadoTrabajo ){
   this->estadoTrabajo = estadoTrabajo;
}


/*
void ActaTrabajo::cerrarActa()
{
   int actaEscogida, i = 0;
   system( "CLS()" );
   cout << "!--Cerrar acta---!\n";
   cout << "Ingrese el numero de acta: ";
   cin >> actaEscogida;
   if( actasCreadas.size() >= i ){
      cout << "El tamanio:" << actasCreadas.size();
      for( i = 0; i < actasCreadas.size(); i++){
         if (  numero == actaEscogida ){
             estadoTrabajo = CERRADA;
            cout << "Se ha cerrado el acta\n";
         }
      }
   }else{
      cout << "No hay suficientes actas";
   }
   system( "PAUSE()" );
}
*/
void ActaTrabajo::calificarCriterios()
{
}
int ActaTrabajo::calificarNotaFinal()
{
   return 0;
}
void ActaTrabajo::addComentario()
{
}

void ActaTrabajo::mostrarActa(){
   system( "CLS()" );
   cout << "!--- Actas ---!\n";
   cout << "Numero acta: " << numero << "\n";
   cout << "Fecha: " <<  fecha << "\n";
   cout << "Autor: " <<  autor << "\n";
   cout << "Nombre trabajo: " <<  nombreTrabajo << "\n";

   if(  tipoTrabajo == APLICADO ){
      cout << "Tipo trabajo: Aplicado\n";
   }else{
      cout << "Tipo trabajo: Investigacion\n";
   }
   
   cout << "Periodo: " <<  periodo << "\n";
   cout << "Nota final: " <<  notaFinal << "\n";
   cout << "Director: " <<  director << "\n";
   cout << "Codirector: " <<  codirector << "\n";
   cout << "Jurado 1: " <<  jurado1 << "\n";
   cout << "Jurado 2: " <<  jurado2 << "\n";

   if(  estadoTrabajo == ABIERTA ){
      cout << "Estado Trabajo: Abierta\n";
   }else{
      cout << "Estado Trabajo: Cerrada\n";
   }
   if(  estadoAceptacion == ACEPTADO ){
      cout << "Estado aceptacion: Aceptado\n";
   }else if(  estadoAceptacion == RECHAZADO ){
      cout << "Estado aceptacion: Rechazado\n";
   }else{
      cout << "Estado aceptacion: Pendiente\n";
   }
   cout << endl;
   system("PAUSE()");
}

string ActaTrabajo::getDirector()
{
   return this->director;
}

string ActaTrabajo::getJuradoUno()
{
   return this->jurado1;
}

string ActaTrabajo::getJuradoDos()
{
   return this->jurado2;
}