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

// Destructor, lo dejaremos vacío, para indicar que el acta esté cerrada de forma efectiva, lo haremos en el main 
ActaTrabajo::~ActaTrabajo(){
}

void ActaTrabajo::crearActa()   
{
    int i = 0, contNumero = 1000; // Contador del numero de acta
    time_t now = time( 0 );
    char* dt = ctime( &now ); // Dt = day time, pasa la hora/dia actual a un char
    int opcTipoTrabajo;
    int existenciaCodirector;
    fecha = dt;
    numero = contNumero;
    contNumero++;

    system( "CLS()" );
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
            contadorTrabajoAplicado++;
            break;
        }

        else if( opcTipoTrabajo == 1 )  
        {
            tipoTrabajo = trabajo::INVESTIGACION;
            contadorTrabajoInvestigacion++; 
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
    cout << "\n0. No\n1. Si\n";

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
    
    cin.ignore( 30, '\n' );
    cout << "\nJurado 1: "; getline(cin, jurado1);
    cout << "\nJurado 2: "; getline(cin, jurado2);
    cout << "\nPeriodo: "; getline(cin, periodo);
    cout << "\nImportante: El numero del acta es: " << numero << std::endl;

    cout << '\n';
    estadoAceptacion = aceptacion::PENDIENTE;
    estadoTrabajo = estado::ABIERTA;
    ActaTrabajo newActa( numero, fecha, autor, nombreTrabajo, tipoTrabajo, periodo, notaFinal, director, codirector, jurado1, jurado2, estadoTrabajo, estadoAceptacion );
    actasCreadas.push_back( newActa );
    system( "PAUSE()" );
    system( "CLS()" );
}

void ActaTrabajo::cerrarActa()
{
}
void ActaTrabajo::calificarCriterios()
{
}
int ActaTrabajo::calificarNotaFinal()
{
}
void ActaTrabajo::addComentario()
{
}

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

void ActaTrabajo::consultarTipoTrabajo()
{
    system( "CLS()");
    int i;

    /*
    En los dos procesos miramos las actas y comparamos cada una si es aplicado o investigación para imprimirlar
    en conjunto, es decir, primero imprime cuantas y cuales hay de trabajos aplicados y después de investigación
    */

   if( contadorTrabajoAplicado > 0 )
   {
        cout << "\nSe han desarrollado " << contadorTrabajoAplicado << ", los cuales son:\n";

        // Si no hay trabajos aplicados no entra a ciclo
        if( contadorTrabajoAplicado > 0 )
        {
            for( i = 0; i < actasCreadas.size(); i++ )
            {
                if( actasCreadas[i].tipoTrabajo == trabajo::APLICADO )
                {
                    cout << actasCreadas[i].tipoTrabajo << std::endl;
                }
            }
        }
   }
   else
   {
       cout << "\nNo se ha desarrollado ningun trabajo aplicado" << std::endl;
    }

    cout << '\n';

    if( contadorTrabajoInvestigacion  > 0 )
    {
        cout << "\nSe han desarrollado " << contadorTrabajoInvestigacion << ", los cuales son:\n";

        // Si no hay trabajos de investigación, no entra a ciclo
        if( contadorTrabajoInvestigacion > 0 )
        {
            for( i = 0; i < actasCreadas.size(); i++ )
            {
                if( actasCreadas[i].tipoTrabajo == trabajo::INVESTIGACION )
                {
                    cout << actasCreadas[i].tipoTrabajo << std::endl;
                }
            }
        }
    }
    else
    {
        cout << "\nNo se ha desarrollado ningun trabajo de investigacion\n" << std::endl;
    }
    cout << std::endl;
    system("PAUSE()");
}


void ActaTrabajo::consultarEstadoAceptacion()
{
    system( "CLS()");
    int i, contadorEspecial;    
    /* 
        ContadorEspecial sirve para notificar mensaje especial en caso de que 
        no hayan actas pendientes o rechazadas
    */

    cout << "\nActas Pendientes:\n";
    contadorEspecial = 0;
    for( i = 0; i < actasCreadas.size(); i++ )
    {
        if( actasCreadas[i].estadoAceptacion == aceptacion::PENDIENTE )
        {
            cout << "\n" << actasCreadas[i].nombreTrabajo;
            contadorEspecial++;
        }
    }

    if( contadorEspecial == 0 )
    {
        cout << "No hay ningun acta pendiente momentaneamente.\n";
    }

    cout << '\n';
    cout << "\nActas Rechazadas:\n";
    contadorEspecial = 0;
    for( i = 0; i < actasCreadas.size(); i++ )
    {
        if( actasCreadas[i].estadoAceptacion == aceptacion::RECHAZADO )
        {
            cout << "\n" << actasCreadas[i].nombreTrabajo;
            contadorEspecial++;
        }
    }
    if( contadorEspecial == 0 )
    {
        cout << "No hay ningun acta rechazada momentaneamente.\n";
    }

    cout << std::endl;
    system("PAUSE()");
}

void ActaTrabajo::eliminarActa()
{
}