#include "conjuntoLista.h"

Universidad::Universidad(){
}

void Universidad::mostrarActas(){
   system( "CLS()" );
   int i;
   
   // Miramos si no está vacía
   if( vectorActasTrabajos.empty() )
   {
      // Recorre el vector e imprime
      for ( i = 0; i < vectorActasTrabajos.size(); i++){
         vectorActasTrabajos[i].mostrarActa();
      }
   }
   // Si está vacía, arroja un mensaje especial
   else
   {
       cout << "\nLo sentimos! No hay actas creadas\n" << endl;
   }
   system( "PAUSE()");
}

void Universidad::crearActa()
{
    char* fecha;
    string autor, nombreTrabajo, director, codirector, jurado1, jurado2, periodo;
    int i = 0, numero = 1000; // Contador del numero de acta
    time_t now = time( 0 );
    char* dt = ctime( &now ); // Dt = day time, pasa la hora/dia actual a un char
    int opcTipoTrabajo; // Opción dada en el menú para mirar el tipo de trabajo (aplicado - investigacion)
    int opcIngresoJurado1;  // opcion del usuario para saber si registrar o no al jurado1
    int opcIngresoJurado2; // opcion del usuario para saber si registrar o no al jurado2
    int existenciaCodirector; // Opción dada en el menú para rectificar si hay o no codirecto
    trabajo tipoTrabajo;
    aceptacion estadoAceptacion;    // Pendiente-Rechazado-Aceptado
    estado estadoTrabajo;   // Abierto - Cerrado
    fecha = dt;
    numero++;  // Número del acta incrementa en 1 cada vez que se crea una

    system( "CLS()" );
    cout << "\n!---Ingrese los siguientes datos---!\n";
    cin.ignore(100,'\n');
    cout << "\nNombre del autor: "; getline(cin, autor) ;
    cout << "\nNombre del trabajo: "; getline(cin, nombreTrabajo);

    // Hacemos un bucle infinito hasta que el usuario digite los datos satisfactoriamente  
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

        // Asigna valores si el numero ingresado es correcto ( 1 - 0 ) y sale del bucle
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

        // Si el número no es valido, arroja mensaje y vuelve a pedir el numero
        else   
        {
            cout << "\n\tValor invalido\n";
            cout << endl;
        }
    }

    cin.ignore(100,'\n');
    cout << "\nDirector: "; getline(cin, director);

    // Bucle infinito hasta que los datos pedidos sean correctos
    while( 1 )
    {
        cout << "\nHay codirector?";
        cout << "\n0. No\n1. Si\n";
        cout << " "; 

        // Bucle infinito hasta que el valor ingresado sea correcto
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
            codirector = "NA";
            break;           
        }

        else if( existenciaCodirector == 1 )  
        {
            cin.ignore( 100, '\n' );
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
    cout << "\nYa te has registrado? ";
    cout << "\n0.No\n1.Si\n";

    // Entra en bucle hasta que ingrese un valor valido
    while( 1 )
    {
        // Bucle hasta que el usuario ingrese un valor valido
        while( !( cin >> opcIngresoJurado1 ) )
        {
            cout << "\nIngrese un valor valido: ";
            cin.clear();
            cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n' );
        }

        // Mira la opcion y mira si es 0 o 1, caso contrario, vuele al inicio del ciclo
        if( opcIngresoJurado1 == 0 )
        {
            registrarExperto();
            break;
        }
        else if( opcIngresoJurado1 == 1 )
        {
            break;
        }
        else
        {
            cout << "\n\tValor invalido";
        }
    }

    cout << endl;

    cin.ignore( 30, '\n' );
    cout << "\nJurado 2: "; getline(cin, jurado2);
    cout << "\nYa te has registrado? ";
    cout << "\n0.No\n1.Si\n";

    // Entra en bucle hasta que ingrese un valor valido
    while( 1 )
    {
        while( !( cin >> opcIngresoJurado2 ) )
        {
            cout << "\nIngrese un valor valido: ";
            cin.clear();
            cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n' );
        }

        // Mira la opcion y mira si es 0 o 1, caso contrario, vuele al inicio del ciclo
        if( opcIngresoJurado2 == 0 )
        {
            registrarExperto();
            break;
        }
        else if( opcIngresoJurado2 == 1 )
        {
            break;
        }
        else
        {
            cout << "\n\tValor invalido";
        }
    }

    cout << endl;

    cin.ignore( 30, '\n' );
    cout << "\nPeriodo: "; getline(cin, periodo);
    cout << "\n\nImportante: El numero del acta es: " << numero << std::endl;

    cout << "\n\n";

    // Ponemos al acta en estado pendiente y abierta
    estadoAceptacion = aceptacion::PENDIENTE;
    estadoTrabajo = estado::ABIERTA;
    ActaTrabajo newActa( numero, fecha, autor, nombreTrabajo, tipoTrabajo, periodo, director, codirector, jurado1, jurado2, estadoTrabajo, estadoAceptacion );
    this->vectorActasTrabajos.push_back( newActa ); // Aquí la agregamos al vecto de actastrabajos

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

    // Recorremos el vector de actas trabajos 
    for( i = 0; i < vectorActasTrabajos.size(); i++ )
    {
        // Miramos cuales son pendientes e imprimimos
        if(  vectorActasTrabajos[i].getEstadoAceptacion() == aceptacion::PENDIENTE )
        {
            cout << "\n" <<  vectorActasTrabajos[i].getNombreTrabajo();
            contadorEspecial++; // Sumamos +1 al contador
        }
    }

    // Si el contador es 0, es por que no hay actas pendientes
    if( contadorEspecial == 0 ) 
    {
        cout << "No hay ningun acta pendiente momentaneamente.\n";
    }

    cout << '\n';
    cout << "\nActas Rechazadas:\n";
    contadorEspecial = 0;   // Reseteamos el contador a 0
    for( i = 0; i < vectorActasTrabajos.size(); i++ )
    {
        // Recorremos el vector de actas trabajos  e imprimimos las rechazadas
        if(  vectorActasTrabajos[i].getEstadoAceptacion() == aceptacion::RECHAZADO )
        {
            cout << "\n" <<  vectorActasTrabajos[i].getNombreTrabajo();
            contadorEspecial++; // Sumamos +1 al contador
        }
    }
    // Si el contador es 0, es por que no hay actas pendientes
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
   sectorExperto sector;    // Hace referencia a si el jurado es profesor interno o externo

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
       
       /*
            fin_if se va a encargar de buscar espacios, el nombre de usuario no puede tener especios
            En caso de tenerlo, imprime mensaje y sumamos +1 a findError
       */

       if( std::find_if( user.begin(),user.end(), space ) != user.end() )
       {
          cout << "\n\tLo sentimos! El usuario no puede incluir espacios\n" << endl;
          findError++;
       }

      // Aquí miramos si el usuario es muy largo o muy corto
      if( user.size() > 16 || user.size() < 4 )  
      {
         cout << "\n\tLo sentimos! Tu nombre de usuario no cumple con los parametros.\n" << endl;
         findError++;   // Si hay error encontrado sumamos +1 al contador
      }
      
      // Si findError es 0, no hubo problemas en la creación del usuario
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
      
      // Entra en bucle hasta que ingrese un valor valido
      while( !( cin >> opcSector ) )
      {
          cout << "\nPor favor, ingrese un valor valido (numerico): ";
          cin.clear();
          cin.ignore( std::numeric_limits< std::streamsize > ::max(), '\n' );
      }
      // Aquí asignamos el tipo de sector y sale del bucle si el número concuerda
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
      // Si no es valido, vuelve al inicio el bucle
      else
      {
         cout << "\n\tValor invalido, intente de nuevo" << endl;
         cout << endl;
      }
   }
   
   // Ingresamos los datos al vector de vectorPersonas
   Experto newjurado( user, password, sector, nombre );
   vectorPersonas.push_back ( newjurado );
   cout << "\n\nFelicitaciones: Has sido registrado satisfactoriamente\n\n" << std::endl;;
   system( "Pause()" );
   system( "CLS()" );
}

void Universidad::consultarJurados(){
   int i, contadorInternos = 0, contadorExternos = 0;
   vector <string> juradosInternos;
   vector <string> juradosExternos;

   /*
    i es el iterador
    contadorInterno y contadorExterno sirven para verificar si no hay jurados internos y externos respectivamente
    juradosInternos almacena todos los juradosInternos
    juradosExernos almacena todos los juradosExternos
   */

   system("CLS()");

   // Verificamos que no esté vacío
   if( !( vectorPersonas.empty() ) )
   {
       // Recorremos el vector
      for ( i = 0; i < vectorPersonas.size(); i++)
      {
         if( vectorPersonas[i].consultarJurados() )
         {
            // Si el metodo anterior retorna true, añadimos el nombre al vector juradosInternos
            juradosInternos.push_back( vectorPersonas[i].getNombre() );   // Si es true, 
         }
         else
         {
            // Si el metodo anterior retorna false, añadimos el nombre al vector juradosExternos
            juradosExternos.push_back( vectorPersonas[i].getNombre() );
         }
      }

      // Imprimimos los jurados internos
      cout << "\nJurados Internos:\n" << endl;
      for( i = 0; i < juradosInternos.size(); i++ )
      {
          cout << juradosInternos[i] << endl;
          contadorInternos++;  // Sumamos +1 al contador cada vez que imprima uno 
      }
      if( contadorInternos == 0 )
      {
        // Si el contador es 0, significa que no hay jurados internos
        cout << "\nNo hay jurados internos momentaneamente\n";
      }

      cout << endl;

      // Imprimimos los jurados externos
      cout << "Jurados externos:\n" << endl;
      for( i = 0; i < juradosExternos.size(); i++ )
      {
          cout << juradosExternos[i] << endl;
          contadorExternos++; // Sumamos +1 al contador cada vez que imprima uno 
      }
      if( contadorExternos == 0 )
      {
        // Si el contador es 0, significa que no hay jurados externos
        cout << "\nNo hay jurados externos momentaneamente\n";
      }
   }
   // Si está vacía, imprimimos un mensaje especial 
   else{
       cout << "\nLo sentimos! No hay actas creadas\n" << endl;
   }

   cout << endl;
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
   cout << "\nIngrese el numero de acta: ";

   // Entra en bucle hasta que ingrese un valor correcto
   while( !( cin >> actaEscogida ) )
   {
       cout << "\nIngrese un valor valido (numerico): ";
       cin.clear();
       cin.ignore( std::numeric_limits < std::streamsize > ::max() );
   }

   // Verifica si el vector de actas no está vacío
   if( !( vectorActasTrabajos.empty() ) )
   {
       // Recorremos el vector
      for( i = 0; i <= vectorActasTrabajos.size(); i++ ) 
      {
          // Verificamos en numero del acta con las ya registradas
         if( vectorActasTrabajos[i].getNumeroActa() == actaEscogida )
        {
            // Cambiamos el estado a cerrada y eliminadas
            vectorActasTrabajos[i].setEstadoTrabajo( CERRADA );
            cout << "\nSe ha cerrado el acta satisfactoriamente\n";
            verificarNumero++;

            // Si la nota final es menor a 3.5, es rechazado, si es mayor o igual, aceptado 
            if( vectorActasTrabajos[i].getNotaFinal() < 35 ){
               vectorActasTrabajos[i].setEstadoAceptacion( aceptacion::RECHAZADO );
            }
            else{
               vectorActasTrabajos[i].setEstadoAceptacion( aceptacion::ACEPTADO ); 
            }
        }

        // Si verificarNumero = 0, significa que el acta no fue encontrada y por ende, no existe
        else if( i == vectorActasTrabajos.size() && verificarNumero == 0)
        {
            cout << "\n\tError: Numero de acta inexistente\n";
        }
      }
    }

    // Si está vacío, imprimimos mensaje especial
    else    
    {
        cout << "\nLo sentimos! No hay actas creadas\n";
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
        for( i = 0; i < vectorActasTrabajos.size(); i++ )
        {
            // Comparamos cada acta y miramos el nombre de directo, se compara con el nombre ingresado
            if( vectorActasTrabajos[i].getDirector() == profesor )
            {
                // Imprime el nombre de las actas si concuerda con el nombre de profesor
                cout << vectorActasTrabajos[i].getNombreTrabajo() << endl;
                contadorProfesor++;
                verificarProfesor++;
            }

            // Si verificarProfesor = 0, no fue encontrado el profesor
            else if( i == vectorActasTrabajos.size() && verificarProfesor == 0 )
            {
                cout << "\nLo Sentimos! Profesor inexistente.\n";
            }
        }

        cout << endl;

        // Si verificarProfesor > 0, entra e imprime el número de trabajos que ha dirigido 
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

            // Verificamos que el usuario ingrese si o si un integer
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
            //Si el numero es diferente a 0 o 1, entra en bucle infinito hasta que ingrese uno de ellos        
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

    /*
        i = iterador
        decisionUser se encargará de ser la opcion elegida en un menú abajo
        contadorJurado para rectificar que el jurado haya o no haya sido encontradoo
        jurado almacena el nombre del jurado escrito por el usuario
    */

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
        if( contadorJurado == 0 )   // Si es 0 es porque no hay ningun jurado
        {
            cout << "\nLo Sentimos! Jurado inexistente.\n";
        }
        cout << endl; 

        // Valida que el usuario solo pueda digitar entre 0 y 1
        while( 1 )
        {
            system("PAUSE()");
            system("CLS()");
            // Mini menú para saber si desean continuar con buscando
            cout << "\nDeseas buscar a otro jurado?";
            cout << "\n0.No\n1.Si\n";
            cout << " ";

            // Verificamos que el usuario ingrese un valor numerico
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
            // Si es diferente a 0 o 1, entra a bucle infinito hasta que ingrese uno de ellos
            else
            {
                cout << "\n\tOpcion no valida, intente de nuevo\n";
                cout << endl;
            }  
        }
        
    } while( decisionUser != 0 );   // Si es 0, sale de este apartado

    system( "PAUSE()" );
}

void Universidad::consultarListaJurados()
{
    vector <string> jurados;
    int i;

    /*
        i = iterador
        jurados es un string que almacenará todos los jurados con sus repetidos
    */

    system("CLS()");

    // Si no está vacío el vector de actas trabajos (almacena actas), continúa
    if( !( vectorActasTrabajos.empty() ) )
    {
        for( i = 0; i < vectorActasTrabajos.size(); i++ )   
        {
            // Incluimos en el vector de jurados todos los jurados que hayan en las actas
            jurados.push_back( vectorActasTrabajos[i].getJuradoUno() );
            jurados.push_back( vectorActasTrabajos[i].getJuradoDos() );
        }

        // Sort organizará la vector de jurados (A-Z)
        std::sort( jurados.begin(), jurados.end() );    

        // Erase y Unique se van a encargar de eliminar y seleccionar repetidos respectivamente    
        jurados.erase( std::unique( jurados.begin(), jurados.end() ), jurados.end() );

        for( i = 0; i < jurados.size(); i++ )
        {
            cout << jurados[i] << endl; //En este vector, solo están los nombres únicos
        }
        
        cout << endl;
    }
    // Si está vacío, imprime mensaje especial y termina este apartado
    else
    {
        cout << "\nLo sentimos! No hay actas creadas\n" << endl;
    }

    system("PAUSE()");
}

void Universidad::diligenciarActa(){
   int i, codigoSelect, tipo, x, error;
   float nota1, nota2, notaFinal;
   string comentario;

   system("CLS()");
   cout << "!--- Diligenciar Acta ---! \n";
   cout << "\nIngrese el codigo del acta: \n";

   // Miramos que el valor ingresado sea un integer
   while( !( cin >> codigoSelect ) ) 
   {
       cout << "Ingrese un valor valido (numerico): ";
       cin.clear();
       cin.ignore( std::numeric_limits < std::streamsize > ::max() );
   }

   for( i = 0; i < vectorActasTrabajos.size(); i++){
      if ( vectorActasTrabajos[i].getNumeroActa() == codigoSelect ){
         for ( tipo = 0; tipo < 8; tipo++){
             cout << endl;
            cout << tipo + 1 << ". "<< vectorActasTrabajos[i].getIdentificador( tipo ) << "\n";

            while( 1 ){
               error = 0;
               cout << "Ingrese la nota del jurado 1 (0.0 - 5.0): \n";
               while( !( cin >> nota1 ) )

               {
                   cout << "\nIngrese un valor valido (numerico): ";
                   cin.clear();
                   cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n' );
               }

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

               while( !( cin >> nota2 ) )
               {
                   cout << "\nIngrese un valor valido (numerico): ";
                   cin.clear();
                   cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n' );                   
               }

               if( nota2 < 0 || nota2 > 5 ){
                  cout << "\n\tLo sentimos! La nota se excede de los rangos.\n";
                  error++;
               }
               if( error == 0 ){
                  break;
               }
            }
            vectorActasTrabajos[i].setNota( nota1, nota2, tipo );
            cout << "\nIngrese el comentraio del criterio: \n";
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

void Universidad::diligenciarObservaciones(){ //Se encarga de guardar una observacion extra si se solicita
   int codigoSelect, i, error = 0;
   string observacion;
   system("CLS()");
   cout << "!--- Diligenciar Observaciones ---! \n";
   cout << "Ingrese el codigo del acta: \n";
   cin >> codigoSelect;
   for( i = 0; i < vectorActasTrabajos.size(); i++){
      if ( vectorActasTrabajos[i].getNumeroActa() == codigoSelect ){
         cout << "Ingrese el dato de observacion extra: \n";
         cin.ignore( 100, '\n' );
         getline( cin, observacion );
         vectorActasTrabajos[i].setObservacion( observacion );
         error++;
      }
   }
   if( error == 0 ){
      cout << endl << "No se encontro ningun acta." << endl;
   }
   system("PAUSE()");
}

// Busca si existe el numero de acta y si lo encuentra y esta abierta la acta se elimina
void Universidad::eliminarActa(){
   int codigoSelect, i, error = 0;
   system("CLS()");
   cout << "!--- Eliminar Acta ---! \n";
   cout << "Ingrese el codigo del acta: \n";
   cin >> codigoSelect;
   for( i = 0; i < vectorActasTrabajos.size(); i++){
      if ( vectorActasTrabajos[i].getNumeroActa() == codigoSelect ){
         if( vectorActasTrabajos[i].getEstadoTrabajo() == ABIERTA ){
            vectorActasTrabajos.erase( vectorActasTrabajos.begin() + i - 1  );
            cout << "Se ha eliminado el acta con exito.\n";
         }else{
            cout << "El acta se encuentra cerrada.\n";
         }
         error++;
      }
   }
   if( error == 0 ){
      cout << endl << "No se encontro ningun acta." << endl;
   }
   system("PAUSE()");
}

// Se encarga de guardar en un archivo .txt los datos del acta
void Universidad::crearTxt(){
   string nombreArchivo;
   int codigoSelect, i, j, error = 0;

   system("CLS()");
   cout << "!--- Creacion txt ---! \n";
   cout << "Ingrese el codigo del acta: \n";
   cin >> codigoSelect;
   for( i = 0; i < vectorActasTrabajos.size(); i++){
      if ( vectorActasTrabajos[i].getNumeroActa() == codigoSelect ){
         cout << "Ingrese el nombre del archivo a crear: \n";
         cin.ignore( 100, '\n' );
         cin >> nombreArchivo;
         ofstream archivoActa( nombreArchivo );
         archivoActa << this->vectorActasTrabajos[i].getNumeroActa() << "         " << this->vectorActasTrabajos[i].getNumeroActa() << endl;
         archivoActa << "         ACTA DE EVALUACION DE TRABAJO DE GRADO" << endl;
         archivoActa << "         " << this->vectorActasTrabajos[i].getNombreTrabajo() << endl;
         archivoActa << "Autor: "<< this->vectorActasTrabajos[i].getAutor() << endl;
         archivoActa << "Periodo: "<< this->vectorActasTrabajos[i].getPeriodo() << endl;
         archivoActa << "Director: "<< this->vectorActasTrabajos[i].getDirector() << endl;
         archivoActa << "Co-Director: "<< this->vectorActasTrabajos[i].getCodirector() << endl;
         archivoActa << "Jurado 1: "<< this->vectorActasTrabajos[i].getJuradoUno() << endl;
         archivoActa << "Jurado 2: "<< this->vectorActasTrabajos[i].getJuradoDos() << endl;
         
         for( j = 0; j < 8; j++){
            archivoActa << j + 1 << ". "<< this->vectorActasTrabajos[i].getIdentificador( j ) << "\n";
            archivoActa << "Calificacion Parcial: " << this->vectorActasTrabajos[i].getNotaCriterio( j ) << "            Ponderacion: " << this->vectorActasTrabajos[i].getPonderado( j ) << "%" <<endl;
            archivoActa << "Observaciones: " << this->vectorActasTrabajos[i].getComentario( j ) << endl;
            archivoActa << "-------------------------------------------------------------------------------" << endl;
            archivoActa << "-------------------------------------------------------------------------------" << endl;
         }
         archivoActa << "Observaciones adicionales: " << this->vectorActasTrabajos[i].getObservacion();
         cout << endl << "Archivo creado con exito." << endl;
         error++;
      }
   }
   if( error == 0 ){
      cout << endl << "No se encontro ningun acta." << endl;
   }
   system("PAUSE()");
}