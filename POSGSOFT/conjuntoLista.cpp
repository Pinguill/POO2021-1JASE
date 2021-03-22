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

void Universidad::crearActa()
{
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
    
    while( 1 )
    {
        // Implementamos un mini-menu para establecer el tipo de trabajo 
        cout << "\nCual es el tipo de trabajo?\n";      
        cout << "\n0. Aplicado\n1. Investigacion\n";
        cout << " "; 

        /*
            Aquí el entra a while si el valor dado no es numerico, 
            no saldrá del while hasta que el usuario escriba un número
        */
        while( !( cin >> opcTipoTrabajo ) )
        {
            cout << "\nPor favor ingrese un valor valido (numerico): ";
            cin.clear();
            cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');
        }

        if( opcTipoTrabajo == 1 )
        {
            tipoTrabajo = trabajo::INVESTIGACION;
            contadorTrabajoInvestigacion++; 
            break;
        }

        else if( opcTipoTrabajo == 0 )
        {
            tipoTrabajo = trabajo::APLICADO;
            contadorTrabajoAplicado++; 
            break;   
        }

        else
        {
            cout << "\n\tValor invalido\n";
            cout << endl;
        }
    }

    cin.ignore(100,'\n');
    cout << "\nDirector: "; getline(cin, director);

    while( 1 )
    {
        cout << "\nHay codirector?";
        cout << "\n0. No\n1. Si\n";
        cout << " "; 

        while( !( cin >> existenciaCodirector ) )
        {
            cout << "\nPor favor, ingrese un valor valido (numerico): ";
            cin.clear();
            cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n' );
        }

        // Verifica si existe codirector o no, si no existe lo asigna como NA.
        if( existenciaCodirector == 0 )   
        {
            cin.ignore( 100, '\n' );
            existeCodirector = true;
            codirector = "NA";
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
            cout << "\n\tValor invalido, intente de nuevo.\n";
            cout << endl;
        }
    }
    
    cout << "\nJurado 1: "; getline(cin, jurado1);
    cout << "\nJurado 2: "; getline(cin, jurado2);
    cout << "\nPeriodo: "; getline(cin, periodo);
    cout << "\n\nImportante: El numero del acta es: " << numero << std::endl;

    cout << "\n\n";
    estadoAceptacion = aceptacion::PENDIENTE;
    estadoTrabajo = estado::ABIERTA;
    ActaTrabajo newActa( numero, fecha, autor, nombreTrabajo, tipoTrabajo, periodo, director, codirector, jurado1, jurado2, estadoTrabajo, estadoAceptacion );
    this->vectorActasTrabajos.push_back( newActa );

    system( "PAUSE()" );
    system( "CLS()" );
}

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
        for( i = 0; i < vectorActasTrabajos.size(); i++ )
        {
            if(  vectorActasTrabajos[i].getTipoTrabajo() == trabajo::APLICADO )
            {
                cout <<  vectorActasTrabajos[i].getNombreTrabajo() << std::endl;
            }
        }
    }
    // Validacion en caso de que no se hayan creado trabajos aplicados
    else
    {
        cout << "\nNo se ha desarrollado ningun trabajo aplicado" << std::endl;
    }

    cout << '\n';

    if( contadorTrabajoInvestigacion  > 0 )
    {
        cout << "\nSe han desarrollado " << contadorTrabajoInvestigacion << ", los cuales son:\n";

        // Si no hay trabajos de investigación, no entra a ciclo
        for( i = 0; i < vectorActasTrabajos.size(); i++ )
        {
            if(  vectorActasTrabajos[i].getTipoTrabajo() == trabajo::INVESTIGACION )
            {
                cout <<  vectorActasTrabajos[i].getNombreTrabajo() << std::endl;
            }
        }
    }
    
    // Validacion en caso de que no hayan trabajos de investigación
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
   int (*space)(int) = std::isspace;    //Funcion que determina el caracter de "espacio"
   
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
            cout << "\n\tLo sentimos! Ese nombre de usuario ya existe\n" << std::endl;
            findError++;
            break;
         }
      }

       if( std::find_if( user.begin(),user.end(), space ) != user.end() )
       {
          cout << "\n\tLo sentimos! El usuario no puede incluir espacios\n" << endl;
          findError++;
       }

      // Aquí miramos si el usuario es muy largo o muy corto
      if( user.size() > 16 || user.size() < 4 )  
      {
         cout << "\n\tLo sentimos! Tu nombre de usuario no cumple con los parametros.\n" << endl;
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
         cout << "\n\tLo sentimos! La contrasenia no cumple con los parametros.";
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
      
      while( !( cin >> opcSector ) )
      {
          cout << "\nPor favor, ingrese un valor valido (numerico): ";
          cin.clear();
          cin.ignore( std::numeric_limits< std::streamsize > ::max(), '\n' );
      }

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
         cout << "\n\tValor invalido, intente de nuevo" << endl;
         cout << endl;
      }
   }

   registro = REGISTRADO;

   // Aui podriamos poner el sleep
   Experto newjurado( user, password, sector, nombre );
   vectorPersonas.push_back ( newjurado );
   cout << "\n\nFelicitaciones: Has sido registrado satisfactoriamente\n\n" << std::endl;;
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

// Validacion en caso de que el número esté mal añadida
void Universidad::cerrarActa()
{
   int actaEscogida, i, verificarNumero = 0;

   /* 
    actaEscogida es el número de acta que indica el usuario
    i  es el iterador
    verificarNumero sirve de contador para verificar que si el acta existe o no, inicia en 0
   */

   system( "CLS()" );
   cout << "!--Cerrar acta---!\n";
   cout << "Ingrese el numero de acta: ";
   cin >> actaEscogida;

   // Verifica si el vector de actas no está vacío
   if( !vectorActasTrabajos.empty() )
   {
      for( i = 0; i <= vectorActasTrabajos.size(); i++ ) 
      {
         if( vectorActasTrabajos[i].getNumeroActa() == actaEscogida )
        {
            vectorActasTrabajos[i].setEstadoTrabajo( CERRADA );
            cout << "\nSe ha cerrado el acta satisfactoriamente\n";
            verificarNumero++;
            if( vectorActasTrabajos[i].getNotaFinal() <= 35 ){
               vectorActasTrabajos[i].setEstadoAceptacion( aceptacion::RECHAZADO );
            }
        }

        // Si verificarNumero = 0, significa que el acta no fue encontrada y por ende, no existe
        else if( i == vectorActasTrabajos.size() && verificarNumero == 0)
        {
            cout << "\nError: Numero de acta inexistente\n";
        }
      }
    }
    else
    {
        cout << "No hay actas creadas\n";
    }
    cout << std::endl;
    system( "PAUSE()" );
}

void Universidad::consultarTrabajoProfesor()
{
    int i, decisionUser, verificarProfesor = 0, contadorProfesor = 0;
    string profesor;
    
    /*
        i es el iterador para recorrer el vector
        decisionUser funciona para saber cuando el usuario desea salir de este apartado
        profesor almacena el nombre de profesor a verificar

        verificarProfesor sirve para determinar si hay o no trabajos con el nombre de ese profesor,
        es decir, cada vez que encuentre al profesor e imprima el nombre del trabajo, se suma 1 al 
        contador, por ende, si se mantiene en 0 no encontró nada.

        contadorProfesor cuenta el numero de trabajos de los que ha dirigido un profesor

        Implementamos un do-while para que el usuario pueda ingresar el numero 
        de profesores que desee
    */
    do{
        system("CLS()");

        // Verificamos si está vacía, si lo está sale del do-while
        if( vectorActasTrabajos.empty() )
        {
            cout << "\nLo sentimos! No hay actas creadas\n" << endl;
            break;
        }

        cin.ignore( 30, '\n' );
        cout << "\nDigite el nombre del profesor del cual quiere conocer los trabajos que ha dirigido: ";
        getline( cin, profesor );
        cout << endl;

        // Recorremos el vector de actas para verificar si el profesor está
        for( i = 0; i <= vectorActasTrabajos.size(); i++ )
        {
            if( vectorActasTrabajos[i].getDirector() == profesor )
            {
                // Imprime los el nombre de las actas si concuerda con el nombre de profesor
                cout << vectorActasTrabajos[i].getNombreTrabajo() << endl;
                contadorProfesor++;
                verificarProfesor++;
            }

            else if( i == vectorActasTrabajos.size() && verificarProfesor == 0 )
            {
                cout << "\nLo Sentimos! Profesor inexistente.\n";
            }
        }

        cout << endl;
        if( verificarProfesor > 0 )
        {
            cout << profesor << " ha dirigido " << contadorProfesor << " trabajos\n";
        }
        cout << endl;

        // Valida que el usuario solo pueda digitar entre 0 y 1
        while( 1 )
        {
            system("PAUSE()");
            system("CLS()");
            // Mini menú para saber si desean continuar con buscando
            cout << "\nDeseas buscar a otro profesor?";
            cout << "\n0.No\n1.Si\n";
            cout << " ";

            while( !( cin >> decisionUser ) )
            {
                cout << "\nPor favor, ingrese un valor valido (numerico): ";
                cin.clear();
                cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');
            }

            cout << std::endl;

            if( decisionUser == 1 || decisionUser == 0 )
            {
                break;
            }        
            else
            {
                cout << "\n\tOpcion no valida, intente de nuevo\n";
                cout << endl;
            }
            
        }
        
    } while( decisionUser != 0 );   // Si es 0, sale de este apartado

    system( "PAUSE()" );
}

void Universidad::consultarTrabajosJurado()
{
    int i, decisionUser, contadorJurado = 0;
    string jurado;

    do{
        system("CLS()");

        // Verificamos si está vacía, si lo está sale del do-while
        if( vectorActasTrabajos.empty() )
        {
            cout << "\nLo sentimos! No hay actas creadas\n" << endl;
            break;
        }

        cin.ignore( 1000, '\n' );
        cout << "\nDigite el nombre del jurado del cual quiere conocer los trabajos que ha dirigido: ";
        getline( cin, jurado );
        cout << endl;

        // Recorremos el vector de actas para verificar si el jurado está
        for( i = 0; i < vectorActasTrabajos.size(); i ++)
        {
            if( vectorActasTrabajos[i].getJuradoUno() == jurado || vectorActasTrabajos[i].getJuradoDos() == jurado )
            {
                // Imprime los el nombre de las actas si concuerda con el nombre de profesor
                cout << vectorActasTrabajos[i].getNombreTrabajo() << endl;
                contadorJurado++;
            }
        }
        if( contadorJurado == 0 )
        {
            cout << "\nLo Sentimos! Profesor inexistente.\n";
        }
        cout << endl; 

        // Valida que el usuario solo pueda digitar entre 0 y 1
        while( 1 )
        {
            system("PAUSE()");
            system("CLS()");
            // Mini menú para saber si desean continuar con buscando
            cout << "\nDeseas buscar a otro profesor?";
            cout << "\n0.No\n1.Si\n";
            cout << " ";

            while( !( cin >> decisionUser ) )
            {
                cout << "\nPor favor, ingrese un valor valido (numerico): ";
                cin.clear();
                cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');
            }

            cout << std::endl;

            if( decisionUser == 1 || decisionUser == 0 )
            {
                break;
            }        
            else
            {
                cout << "\n\tOpcion no valida, intente de nuevo\n";
                cout << endl;
            }  
        }
        
    } while( decisionUser != 0 );   // Si es 0, sale de este apartado

    system( "PAUSE()" );
}

void Universidad::diligenciarActa(){
   int i, codigoSelect, tipo, x, error;
   float nota1, nota2, notaFinal;
   string comentario;
   system("CLS()");
   cout << "!--- Diligenciar Acta ---! \n";
   cout << "Ingrese el codigo del acta: \n";
   cin >> codigoSelect;
   for( i = 0; i < vectorActasTrabajos.size(); i++){
      if ( vectorActasTrabajos[i].getNumeroActa() == codigoSelect ){
         for ( tipo = 0; tipo < 8; tipo++){
            cout << tipo + 1 << ". "<< vectorActasTrabajos[i].getIdentificador( tipo ) << "\n";
            while( 1 ){
               error = 0;
               cout << "Ingrese la nota del jurado 1 (0.0 - 5.0): \n";
               cin >> nota1;
               if( nota1 < 0 || nota1 > 5 ){
                  cout << "\n\tLo sentimos! La nota se excede de los rangos.\n";
                  error++;
               }
               if( error == 0 ){
                  break;
               }
            }
            while( 1 ){
               error = 0;
               cin.ignore( 100, '\n' );
               cout << "Ingrese la nota del jurado 2 (0.0 - 5.0): \n";
               cin >> nota2;
               if( nota2 < 0 || nota2 > 5 ){
                  cout << "\n\tLo sentimos! La nota se excede de los rangos.\n";
                  error++;
               }
               if( error == 0 ){
                  break;
               }
            }
            vectorActasTrabajos[i].setNota( nota1, nota2, tipo );
            cout << "Ingrese el comentraio del criterio: \n";
            cin.ignore( 100, '\n' );
            getline( cin, comentario );
            vectorActasTrabajos[i].setComentario( comentario, tipo );
            cout << "\n";
            x = i;
            system( "CLS()" );
         }
      }
   }
   vectorActasTrabajos[x].calcularNotaFinal();
   notaFinal = vectorActasTrabajos[x].getNotaFinal();
   if( notaFinal > 3.5 ){
      vectorActasTrabajos[x].setEstadoAceptacion( aceptacion::ACEPTADO );
   }
   cout << "\n!--- Diligenciado completo ---!\n";
   system("PAUSE()");
}
