#include <iostream>
#include "menu.h"

int main(){
   int opc;
   do{
      opc = menu();
   } while ( opc != 0 );
   
   return 0;
}