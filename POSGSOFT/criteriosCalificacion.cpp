#include "criteriosCalificacion.h"
#include "experto.h"

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
   system("CLS()");
   cout << "\nTítulo de criterio: "; getline( cin, identificador );

   // Este está en duda, no sé bien si sea descripción
   cout << "\n\nDescripción del criterio: "; getline( cin, textoPresentado );

   cout << "\nPonderación: "; 
   cin >> ponderado;

}

void Criterio::calificarCriterio()
{

   string usuario, pw;
   int salirIngreso, i;

   /*
      usuario y pw servirán para almacenar datos de nombre usuario y contraseña del jurado
      salirIngreso será para salir del bucle, es decir, salir del bucle significa que o
      accedió a su cuenta o no ingresó y falló la operación.
   */

   system("CLS()");
   cout << "\nNecesitamos verificar que tenga permiso para modificar el acta.\n" << endl;

   do
   {
      cout << "Nombre de Usuario: "; getline( cin, usuario );
      cout << "Contraseña: "; getline( cin, pw );

      // PREGUNTAR A PROFESORA AQUI, TENGO DUDA DE CÓMO INCLUIR LA CLASE
 
   } while( salirIngreso != 0 );

   cout << "Nota pertinente: "; cin >> notaCriterio;

   system("PAUSE()");
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