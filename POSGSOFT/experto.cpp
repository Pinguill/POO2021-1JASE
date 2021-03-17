#include "experto.h"

Experto::Experto(){
}

Experto::Experto( string user, string password, sectorExperto sector, string nombre )
{
   this -> user = user;
   this -> password = password;
   this -> sector = sector;
   this -> nombre = nombre;
}


void Experto::registrarExperto()
{
   int i, opcSector, findError; // i = iterador para validar el nombre de usuario

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

      for( i = 0; i < expertosCreados.size(); i++ ) 
      {
         // Aquí miramos si el usuario ya existe
         if( user == expertosCreados[i].user )
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

      /*
         findError suma 1 si encuetra 1 error, si findError es 0 al final, significa que la contraseña
         cumple con el tamaño de la misma.
      */
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
         sector = sectorExperto::INTERNO;
         break;
      }
      else if ( opcSector == 1) 
      {
         sector = sectorExperto::EXTERNO;
         break;
      }
      else
      {
         cout << "\nOpcion incorrecta, intente de nuevo" << std::endl;
      }
   }

   registro = ingreso::REGISTRADO;

   // Aui podriamos poner el sleep
   Experto newjurado( user, password, sector, nombre );
   expertosCreados.push_back (newjurado );
   cout << "\n\nFelicitaciones: Has sido registrado satisfactoriamente\n" << std::endl;;
   system( "Pause()" );
   system( "CLS()" );
}


void Experto::consultarJurados()
{
   int i, contadorExperto;
   /*
      i es un iterador.
      contadorExperto será para validar un mensaje especial en caso que no hayan jurados internos y/o externos
   */ 

   system( "CLS()");
   cout << "\nJurados internos: " << std::endl;
   contadorExperto = 0;

   for( i = 0; i < expertosCreados.size(); i++ )
   {
      if( expertosCreados[i].sector == INTERNO )
      {
         cout << expertosCreados[i].nombre << std::endl;
         contadorExperto++;  
      }
   }  
   if( contadorExperto == 0 )    // Si el contador es 0, no hay jurados internos
   {
      cout << "\nActualmente no hay ningun jurado interno" << std::endl;
   }

   cout << '\n';
   cout << "\nJurados externos: " << std::endl;
   contadorExperto = 0;

   for( i = 0; i < expertosCreados.size(); i++ )
   {
      if( expertosCreados[i].sector == EXTERNO )
      {
         cout << expertosCreados[i].nombre << std::endl;
         contadorExperto++;
      }
   }
   if( contadorExperto == 0 )
   {
      cout << "\nActualmente no hay ningun jurado externo" << std::endl;
   }
   
   cout << '\n';
   system("PAUSE()");
}
