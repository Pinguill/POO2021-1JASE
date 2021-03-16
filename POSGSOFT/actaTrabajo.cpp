#include <iostream>
#include "actaTrabajo.h"

using std::cout;
using std::cin;
using std::getline;

ActaTrabajo::ActaTrabajo()
{

}

/* Usamos este constructor cuando no hay codirector, !--- Se quita por ahora, si no se necesita despues se borra ---!
ActaTrabajo::ActaTrabajo( int numero, string fecha, string autor, string nombreTrabajo, trabajo tipoTrabajo, 
    string periodo, float notaFinal, string director, string jurado1, string jurado2, estado estadoTrabajo, 
    aceptacion estadoAceptacion )
{
    // Asignar valores 
    this -> numero = numero;
    this-> fecha = fecha;
    this -> autor = autor;
    this -> nombreTrabajo = nombreTrabajo;
    this -> tipoTrabajo = tipoTrabajo;
    this -> periodo = periodo;
    this -> notaFinal = notaFinal;
    this -> director = director;
    this -> jurado1;
    this -> jurado2;
    this -> estadoTrabajo = estadoTrabajo;
    this -> estadoAceptacion = estadoAceptacion;
}
*/

// Usamos este constructor cuando hay codirector
ActaTrabajo::ActaTrabajo( int numero, string fecha, string autor, string nombreTrabajo, trabajo tipoTrabajo, 
    string periodo, float notaFinal, string director,  string codirector, string jurado1, string jurado2, 
    estado estadoTrabajo, aceptacion estadoAceptacion )
{
    // Asignar valores 
    this -> numero = numero;
    this-> fecha = fecha;
    this -> autor = autor;
    this -> nombreTrabajo = nombreTrabajo;
    this -> tipoTrabajo = tipoTrabajo;
    this -> periodo = periodo;
    this -> notaFinal = notaFinal;
    this -> director = director;
    this -> codirector = codirector;
    this -> jurado1 = jurado1;
    this -> jurado2 = jurado2;
    this -> estadoTrabajo = estadoTrabajo;
    this -> estadoAceptacion = estadoAceptacion;
}

void ActaTrabajo::crearActa()   
{
    int i = 0, contNumero = 1000; //Contador del numero de acta
    time_t now = time( 0 );
    char* dt = ctime( &now ); // Dt = day time, pasa la hora/dia actual a un char
    int opcTipoTrabajo;
    int existenciaCodirector;
    fecha = dt;
    numero = contNumero;

    cout << "\n!---Ingrese los siguientes datos---!\n";
    cin.ignore(100,'\n');
    cout << "\nNombre del autor: "; getline(cin, autor) ;
    cout << "\nNombre del trabajo: "; getline(cin, nombreTrabajo);

    // Implementamos un mini-menu para establecer el tipo de trabajo 
    cout << "\nCual es el tipo de trabajo?\n";      
    cout << "\n0. Aplicado\n1. Investigacion\n";
    
    while( 1 )
    {
        cout << " "; cin >> opcTipoTrabajo;

        // Dependiendo de la elección se asigna un tipo de trabajo u otro.
        if( opcTipoTrabajo == 0 )   
        {
            tipoTrabajo = trabajo::APLICADO;
            break;
        }

        else if( opcTipoTrabajo == 1 )  
        {
            tipoTrabajo = trabajo::INVESTIGACION;
            break;
        }

        // Entra en ciclo infinito hasta que ingrese una de las opciones válidas
        else
        {
            cout << "\n\tERROR: Opcion no valida, intente de nuevo.\n";
        }
    }
    cin.ignore(100,'\n');
    cout << "\nDirector: "; getline(cin, director);
    
    cout << "\nHay codirector?";
    cout << "\n0. No\n1. Si";

    while( 1 )
    {
        cout << " "; cin >> existenciaCodirector;

        // Verifica si existe codirector o no
        if( existenciaCodirector == 0 )   
        {
            existeCodirector = false;
            break;
        }

        else if( existenciaCodirector == 1 )  
        {
            existeCodirector = true;
            cin.ignore(100,'\n');
            cout << "\nCodirector: "; getline(cin, codirector);
            break;
        }

        // Entra en ciclo infinito hasta que ingrese una de las opciones válidas
        else
        {
            cout << "\n\tERROR: Opcion no valida, intente de nuevo.\n";
        }
    }

    cout << "\nJurado 1: "; getline(cin, jurado1);
    cout << "\nJurado 2: "; getline(cin, jurado2);
    cout << "\nPeriodo: "; getline(cin, periodo);

    estadoAceptacion = aceptacion::PENDIENTE;
    estadoTrabajo = estado::ABIERTA;
    ActaTrabajo newActa( numero, fecha, autor, nombreTrabajo, tipoTrabajo, periodo, notaFinal, director, codirector, jurado1, jurado2, estadoTrabajo, estadoAceptacion );
    actasCreadas.push_back( newActa );
    system( "PAUSE()" );
}

void ActaTrabajo::cerrarActa()
{   
    estadoTrabajo = estado::CERRADA;
    // Aquí pondremos un sleep para hacer un efecto de espera mientras cierra.
    system( "PAUSE()" );
}

void calificarCriterios();
int calificarNotaFinal();
void addComentario();

void ActaTrabajo::mostrarActa(){
   int i;
   for ( i = 0; i < actasCreadas.size(); i++){
      cout << "!--- Acta numero " << i + 1 << " ---!\n";
      cout << "Numero acta: " << actasCreadas[i].numero << "\n";
      cout << "Fecha: " << actasCreadas[i].fecha << "\n";
      cout << "Autor: " << actasCreadas[i].autor << "\n";
      cout << "Nombre trabajo: " << actasCreadas[i].nombreTrabajo << "\n";
      if( actasCreadas[i].tipoTrabajo == APLICADO ){
         cout << "Tipo trabajo: Aplicado\n";
      }else{
         cout << "Tipo trabajo: Investigacion\n";
      }
      cout << "Periodo: " << actasCreadas[i].periodo << "\n";
      cout << "Nota final: " << actasCreadas[i].notaFinal << "\n";
      cout << "Director: " << actasCreadas[i].director << "\n";
      cout << "Codirector: " << actasCreadas[i].codirector << "\n";
      cout << "Jurado 1: " << actasCreadas[i].jurado1 << "\n";
      cout << "Jurado 2: " << actasCreadas[i].jurado2 << "\n";
      if( actasCreadas[i].estadoTrabajo == ABIERTA ){
         cout << "Estado Trabajo: Abierta\n";
      }else{
         cout << "Estado Trabajo: Cerrada\n";
      }
      if( actasCreadas[i].estadoAceptacion == ACEPTADO ){
         cout << "Estado aceptacion: Aceptado\n";
      }else if( actasCreadas[i].estadoAceptacion == RECHAZADO ){
         cout << "Estado aceptacion: Rechazado\n";
      }else{
         cout << "Estado aceptacion: Pendiente\n";
      }
   }
}