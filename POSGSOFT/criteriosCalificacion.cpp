#include "criteriosCalificacion.h"

Criterio::Criterio(){
}

Criterio::Criterio( string identificador, string textoPresentado, float ponderado, string mensajeJurado, float notaCriterio  )
{
   this -> identificador = identificador;
   this -> textoPresentado = textoPresentado;
   this -> ponderado = ponderado;
   this -> mensajeJurado = mensajeJurado;
   this -> notaCriterio = notaCriterio;
}


void Criterio::llenarCriterio()
{
   cin.ignore( 30, '\n' );
   cout << "\nTítulo de criterio: "; getline( cin, identificador );

   // Este está en duda, no sé bien si sea descripción
   cin.ignore( 30, '\n' );
   cout << "\n\nDescripción del criterio: "; getline( cin, textoPresentado );

   cout << "\nPonderación: "; 
   cin >> ponderado;

}

void Criterio::calificarCriterio()
{
   cout << "Nota pertinente: "; cin >> notaCriterio;
}

void Criterio::escribirMensaje()
{
   cin.ignore( 40, '\n' );
   cout << "Digite la observacion: "; getline( cin, mensajeJurado ); 
}

void Criterio::imprimirMensaje()
{
   cout << mensajeJurado;
}

// Este puede estar incluído en el main
void Criterio::consultarListaCriterios()
{
   int i;
   for( i = 0; i < listaCriterios.size(); i++ )
   {
      cout << listaCriterios[i].identificador << std::endl;
   }
}