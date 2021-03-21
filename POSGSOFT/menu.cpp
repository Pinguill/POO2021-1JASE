#include "menu.h"

int menu(){
   int opcion;

   system("CLS()");
   cout << "\n!---Menu actas---!\n"<< endl;
   cout << "1. Agregar acta" << endl;
   cout << "2. Mostrar actas" << endl;
   cout << "3. Ingreso jurado" << endl;
   cout << "4. Crear criterios de calificacion" << endl;
   cout << "5. Cerar acta" << endl;
   cout << "6. Informacion adicional" << endl;
   cout << "0. Salir\n" << endl;
   cout << "Digita el numero: ";

   while( !( cin >> opcion ) )
   {
      cout << "\nPor favor ingrese un valor valido (numerico): ";
      cin.clear();
      cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n' );
   }

   return opcion;
}

int menu2()
{
   int opcion2;

   system("CLS()");
   cout << "\n!---Menu Informacion---!\n" << endl;
   cout << "1. Actas Aplicadas e Investigativas desarrolladas" << endl;
   cout << "2. Actas Pendientes y Rechazadas " << endl;
   cout << "3. Jurados externos e internos" << endl;
   cout << "4. Trabajos dirigidos por profesor" << endl;
   cout << "5. Trabajos en los que ha participado un jurado " << endl;
   cout << "0. Salir\n" << endl;
   cout << "Digita el numero: ";

   while( !( cin >> opcion2 ) )
   {
      cout << "\nPor favor ingrese un valor valido (numerico): ";
      cin.clear();
      cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n' );
   }

   return opcion2;
}