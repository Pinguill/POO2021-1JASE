#include "experto.h"

Experto::Experto(){
}

Experto::Experto( string user, string password, sectorExperto sector, string nombre ){
   this -> sector = sector;
   this -> nombre = nombre;
   this -> trabajosDirigidos = trabajosDirigidos;
}

void Experto::registrarExperto()
{
   int i, opcSector; // i = iterador para validar el nombre de usuario

   cout << "Nombre completo: "; getline( cin, nombre );
   cin.ignore( 60, '\n' );

   // Verificamos que el nombre de usuario no exista, se usa ciclo infinito hasta que ingrese uno válido
   while( 1 )
   {
      cout << "\n\nImportante: El nombre de usuario debe de tener mas de 4 caracteres y menos de 16";
      cin.ignore( 16, '\n' );
      cout << "\nNombre de Usuario: "; getline( cin, user );

      for( i = 0; expertosCreados.size(); i++ ) 
      {
         // Aquí miramos si el usuario ya existe
         if( user == expertosCreados[i].user )
         {
            cout << "\nLo sentimos! Ese nombre de usuario ya existe";
         }
         // Aquí miramos si el usuario es muy largo o muy corto
         else if( user.size() > 16 || user.size() < 4 )  
         {
            cout << "\nLo sentimos! Tu nombre de usuario no cumple con los parametros. ";
         }
         // Finalmente, si todo va bien, sale del bucle
         else{
            break;
         }
      }
   }
   
   // Usamos otro ciclo infinito para la creación de contraseña
   while ( 1 )
   {
      cout << "\n\nImportante: Tu contraseña debe de tener mas de 5 letras, pero menos de 20";
      cin.ignore( 20, '\n' );
      cout << "\nContraseña: "; getline( cin, password );

      // Si es muy extensa o muy corta, el usuario debe repetirla
      if( password.size() < 6 || password.size() > 20 )
      {
         cout << "\n\nLo sentimos! La contraseña no cumple con los parametros.";
      }
      else{
         break;
      }
   }

   //Aquí preguntamos si el jurado es interno o externo.
   cout << "\n\nEres profesor de la Universidad?\n";
   cout << "0.No\n1.Si";
   cin >> opcSector;

   if( opcSector == 0 )
   {
      sector = sectorExperto::EXTERNO;
   }
   else{
      sector = sectorExperto::INTERNO;
   }
   
   registro = ingreso::REGISTRADO;

   cout << "\n\nFelicitaciones: Has sido registrado satisfactoriamente";
   system( "Pause()" );
   system( "CLS()" );
}

void Experto::consultarJurados()
{
   int i; // Iterador 

   cout << "\nJurados internos: " << std::endl;
   for( i = 0; i < expertosCreados.size(); i++ )
   {
      if( expertosCreados[i].sector == sectorExperto::INTERNO )
      {
         cout << expertosCreados[i].sector << std::endl;
      }
   }

   cout << "\nJurados externos: " << std::endl;
   for( i = 0; i < expertosCreados.size(); i++ )
   {
      if( expertosCreados[i].sector == sectorExperto::INTERNO )
      {
         cout << expertosCreados[i].sector << std::endl;
      }
   }

}
