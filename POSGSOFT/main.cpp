#include <iostream>
#include "menu.h"
#include "actaTrabajo.h"
#include "criteriosCalificacion.h"

int main(){
   ActaTrabajo acta;
   int opc;
   do{
      opc = menu();
      switch ( opc ){
      case 1:
         acta.crearActa();
         break;
      case 2:
         acta.mostrarActa();
         break;
      case 3:
         break;
      case 4:
         break;
      case 5:
         break;
      default:
         break;
      }
   } while ( opc != 0 );
   
   return 0;
}