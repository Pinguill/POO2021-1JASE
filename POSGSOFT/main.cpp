#include <iostream>
#include "menu.h"
#include "experto.h"
#include "actaTrabajo.h"
#include "criteriosCalificacion.h"
#include "conjuntoLista.h"

int main(){
   system( "CLS()" );
   Universidad archivo;

   int opc, opc2;

   do{
      opc = menu();

      switch ( opc )
      {
      case 1:
         archivo.crearActa();
         break;
      case 2:
         archivo.mostrarActas();
         break;
      case 3:
         archivo.registrarExperto();
         break;
      case 4:
         archivo.cerrarActa();
         break;
      case 5:
         archivo.diligenciarActa();
         break;
      case 6:
         archivo.diligenciarObservaciones();
         break;
      case 7:
         archivo.eliminarActa();
         break;
      case 8:
         archivo.crearTxt();
         break;
      case 9:
         do{
            opc2 = menu2();

            switch( opc2 )
            {
            case 1:
               archivo.consultarTipoTrabajo();
               break;
            case 2:
               archivo.consultarEstadoAceptacion();
               break;
            case 3:
               archivo.consultarJurados();
               break;
            case 4:
               archivo.consultarTrabajoProfesor();
               break;
            case 5:
               archivo.consultarTrabajosJurado();
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