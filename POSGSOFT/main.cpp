#include <iostream>
#include "menu.h"
#include "experto.h"
#include "actaTrabajo.h"
#include "criteriosCalificacion.h"

int main(){
   system( "CLS()" );
   ActaTrabajo acta;
   Experto jurado;
   int opc, opc2;

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
         jurado.registrarExperto();
         break;
      case 4:
         break;
      case 5:
         do{
            opc2 = menu2();

            switch( opc2 )
            {
            case 1:
               acta.consultarTipoTrabajo();
               break;
            case 6:
               acta.consultarEstadoAceptacion();
               break;
            case 7:
               jurado.consultarJurados();
               break;
            case 0:
               break;
            default:
               cout << "\nNo disponible" << endl;
               break;
            }
         } while( opc2 != 0 );
         break;
      default:
         break;
      }
   } while ( opc != 0 );
   
   return 0;
}