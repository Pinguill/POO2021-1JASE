#include "conjuntoLista.h"

Universidad::Universidad(){
}

void Universidad::mostrarActas(){
   system( "CLS()" );
   int i;
   for ( i = 0; i < vectorActasTrabajos.size(); i++){
      vectorActasTrabajos[i].mostrarActa();
   }
}

void Universidad::crearActa()   {
    char* fecha;
    string autor, nombreTrabajo, director, codirector, jurado1, jurado2, periodo;
    int i = 0, numero = 1000; // Contador del numero de acta
    time_t now = time( 0 );
    char* dt = ctime( &now ); // Dt = day time, pasa la hora/dia actual a un char
    int opcTipoTrabajo;
    int existenciaCodirector;
    trabajo tipoTrabajo;
    aceptacion estadoAceptacion;
    estado estadoTrabajo;
    bool existeCodirector;
    fecha = dt;
    numero++;

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
            cin.ignore( 100, '\n' );
            existeCodirector = true;
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
    cout << "\nImportante: El numero del acta es: " << numero << std::endl;

    cout << '\n';
    estadoAceptacion = aceptacion::PENDIENTE;
    estadoTrabajo = estado::ABIERTA;
    ActaTrabajo newActa( numero, fecha, autor, nombreTrabajo, tipoTrabajo, periodo, director, codirector, jurado1, jurado2, estadoTrabajo, estadoAceptacion );
    this->vectorActasTrabajos.push_back( newActa );
    system( "PAUSE()" );
    system( "CLS()" );
}

//sin completar aun
void Universidad::consultarTipoTrabajo(){
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
            for( i = 0; i < vectorActasTrabajos.size(); i++ )
            {
                if(  vectorActasTrabajos[i].getTipoTrabajo() == trabajo::APLICADO )
                {
                    cout <<  vectorActasTrabajos[i].getTipoTrabajo() << std::endl;
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
            for( i = 0; i < vectorActasTrabajos.size(); i++ )
            {
                if(  vectorActasTrabajos[i].getTipoTrabajo() == trabajo::INVESTIGACION )
                {
                    cout <<  vectorActasTrabajos[i].getTipoTrabajo() << std::endl;
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

void Universidad::consultarEstadoAceptacion(){
    system( "CLS()");
    int i, contadorEspecial;    
    /* 
        ContadorEspecial sirve para notificar mensaje especial en caso de que 
        no hayan actas pendientes o rechazadas
    */

    cout << "\nActas Pendientes:\n";
    contadorEspecial = 0;
    for( i = 0; i < vectorActasTrabajos.size(); i++ )
    {
        if(  vectorActasTrabajos[i].getEstadoAceptacion() == aceptacion::PENDIENTE )
        {
            cout << "\n" <<  vectorActasTrabajos[i].getNombreTrabajo();
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
    for( i = 0; i < vectorActasTrabajos.size(); i++ )
    {
        if(  vectorActasTrabajos[i].getEstadoAceptacion() == aceptacion::RECHAZADO )
        {
            cout << "\n" <<  vectorActasTrabajos[i].getNombreTrabajo();
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

void Universidad::registrarExperto(){
   int i, opcSector, findError; // i = iterador para validar el nombre de usuario
   string user, password, nombre;
   sectorExperto sector;
   ingreso registro;
   system("CLS()");
   cin.ignore( 40, '\n' );
   cout << "Nombre completo: "; getline( cin, nombre );
 
   // Verificamos que el nombre de usuario no exista, se usa ciclo infinito hasta que ingrese uno válido
   while( 1 )
   {  
      /*
         findError suma 1 si encuetra 1 error, si findError es 0 al final, significa que la el nombre
         de usuario no le pertenece a otro usuario y cumple con el tamaño de la misma.
      */
      findError = 0;
      cout << "\nImportante: El nombre de usuario debe de tener mas de 4 caracteres y menos de 16";
      cout << "\nNombre de Usuario: "; getline( cin, user );

      for( i = 0; i < vectorPersonas.size(); i++ ) 
      {
         // Aquí miramos si el usuario ya existe
         if( user == vectorPersonas[i].getUsuario() )
         {
            cout << "\nLo sentimos! Ese nombre de usuario ya existe" << std::endl;
            findError++;
            break;
         }
         // Aquí miramos si el usuario es muy largo o muy corto
      }

      if( user.size() > 16 || user.size() < 4 )  
      {
         cout << "\nLo sentimos! Tu nombre de usuario no cumple con los parametros. ";
         findError++;
      }

      if( findError == 0 ){
         break;
      }
   }
   
   // Usamos otro ciclo infinito para la creación de contraseña
   while ( 1 )
   {
      findError = 0;
      cout << "\n\nImportante: Tu contrasenia debe de tener mas de 5 letras, pero menos de 20" << std::endl;
      cout << "Contrasenia: "; getline( cin, password );

      // Si es muy extensa o muy corta, el usuario debe repetirla
      if( password.size() < 6 || password.size() > 20 )
      {
         cout << "\n\nLo sentimos! La contraseña no cumple con los parametros.";
         findError++;
      }

      
      //findError suma 1 si encuetra 1 error, si findError es 0 al final, significa que la contraseña
      //cumple con el tamaño de la misma.
      
      if( findError == 0 )
      {
         break;
      }
   }

   // Bucle para ingresar opción correcta
   while( 1 )
   {
      //Aquí preguntamos si el jurado es interno o externo.
      cout << "\n\nEres profesor de la Universidad?\n";
      cout << "0.No\n1.Si" << std::endl;
      cout << " ";
      cin >> opcSector;

      if( opcSector == 0 )
      {
         sector = EXTERNO;
         break;
      }
      else if ( opcSector == 1) 
      {
         sector = INTERNO;
         break;
      }
      else
      {
         cout << "\nOpcion incorrecta, intente de nuevo" << std::endl;
      }
   }

   registro = REGISTRADO;

   // Aui podriamos poner el sleep
   Experto newjurado( user, password, sector, nombre );
   vectorPersonas.push_back (newjurado );
   cout << "\n\nFelicitaciones: Has sido registrado satisfactoriamente\n" << std::endl;;
   system( "Pause()" );
   system( "CLS()" );
}

void Universidad::consultarJurados(){
   system( "CLS()" );
   int i;
   for ( i = 0; i < vectorPersonas.size(); i++){
      vectorPersonas[i].consultarJurados();
   }
   system("PAUSE()");
}

void Universidad::cerrarActa()
{
   int actaEscogida, i = 0;
   system( "CLS()" );
   cout << "!--Cerrar acta---!\n";
   cout << "Ingrese el numero de acta: ";
   cin >> actaEscogida;
   if( vectorActasTrabajos.empty() == false ){
      for( i = 0; i < vectorActasTrabajos.size(); i++){
         if( vectorActasTrabajos[i].getNumeroActa() == actaEscogida ){
            vectorActasTrabajos[i].setEstadoTrabajo( CERRADA );
            cout << "Se ha cerrado el acta\n";
         }
      }
   }else{
      cout << "No hay actas creadas\n";
   }
   system( "PAUSE()" );
}