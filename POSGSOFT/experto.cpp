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

string Experto::getUsuario(){
   return this->user;
}

string Experto::getPass(){
   return this->password;
}

string Experto::getNombre(){
   return this->nombre;
}

int Experto::consultarJurados()
{
   bool esInterno;

   if( sector == INTERNO ) // Primero miramos del sector Interno
   {
      return true;   // Si es interno, devolvemos true
   }
   else
   {
      return false;
   }
}
