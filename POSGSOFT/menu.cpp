#include "menu.h"

int menu(){
   int opcion;
   std::cout << "!---Menu actas---!\n"<< std::endl;
   std::cout << "1. Agregar acta" << std::endl;
   std::cout << "2. Mostrar actas" << std::endl;
   std::cout << "0. Salir\n" << std::endl;
   std::cout << "Digita el numero: ";
   std::cin >> opcion;
   return opcion;
}