#include "actaTrabajo.h"

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

    Criterio criterio1 ( "Desarrollo y profundidad en el tratamiento del tema",20,"",0.0 );
    Criterio criterio2 ( "Desafio academico y cientifico del tema",15,"",0.0 );;
    Criterio criterio3 ( "Cumplimiento de objetivos propuestos",10,"",0.0 );;
    Criterio criterio4 ( "Creatividad e innovacion de las soluciones y desarrollos propuestos",10,"",0.0 );;
    Criterio criterio5 ( "Validez de los resultados y conclusiones",10,"",0.0 );;
    Criterio criterio6 ( "Manejo y procesamiento de informacion y bibliografia",10,"",0.0 );;
    Criterio criterio7 ( "Calidad y presentacion del documento escrito",7.5,"",0.0 );;
    Criterio criterio8 ( "Presentacion oral",7.5,"",0.0 );;
    conjuntoCriterio.push_back(criterio1);
    conjuntoCriterio.push_back(criterio2);
    conjuntoCriterio.push_back(criterio3);
    conjuntoCriterio.push_back(criterio4);
    conjuntoCriterio.push_back(criterio5);
    conjuntoCriterio.push_back(criterio6);
    conjuntoCriterio.push_back(criterio7);
    conjuntoCriterio.push_back(criterio8);
}

// Destructor, lo dejaremos vacío, para indicar que el acta esté cerrada de forma efectiva, lo haremos en el main 
ActaTrabajo::~ActaTrabajo(){
}

void ActaTrabajo::calcularNotaFinal(){
   int i;
   float sumaNota = 0;
   for( i = 0; i < conjuntoCriterio.size(); i++){
      sumaNota += conjuntoCriterio[i].getNotaCriterio();
   }
   this->notaFinal = sumaNota;
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
string ActaTrabajo::getIdentificador( int tipo ){
   return conjuntoCriterio[tipo].mostrarIdentificador();
}

void ActaTrabajo::setNota( float nota1, float nota2, int tipo ){
   float nota;
   nota =(nota1 + nota2) / 2;
   conjuntoCriterio[tipo].setNota( nota );
}

void ActaTrabajo::setEstadoAceptacion( aceptacion estado ){
   this->estadoAceptacion = estado;
}

void ActaTrabajo::setComentario( string comentario, int tipo ){
   conjuntoCriterio[tipo].setComentario( comentario );
}

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