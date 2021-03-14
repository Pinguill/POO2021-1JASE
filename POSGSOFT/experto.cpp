#include "experto.h"

Experto::Experto(){
}

Experto::Experto( bool sector, string nombre, int trabajosDirigidos ){
   this -> sector = sector;
   this -> nombre = nombre;
   this -> trabajosDirigidos = trabajosDirigidos;
}