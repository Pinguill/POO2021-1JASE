#include "menu.h"

int menu(){
   int opcion;
   
   cout << "\n!---Menu actas---!\n"<< endl;
   cout << "1. Agregar acta" << endl;
   cout << "2. Mostrar actas" << endl;
   cout << "3. Ingreso jurado" << endl;
   cout << "4. Crear criterios de calificacion" << endl;
   cout << "0. Salir\n" << endl;
   cout << "Digita el numero: ";
   cin >> opcion;
   cout << endl;
   
   return opcion;
}