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

void Experto::consultarJurados()
{
   int i, contadorExperto;
   /*
      i es un iterador.
      contadorExperto será para validar un mensaje especial en caso que no hayan jurados internos y/o externos
      En ambos casos, si el contador es 0, significa que no hay jurado interno o externo. Se evalua individualmente
   */ 

   system( "CLS()");
   cout << "\nJurados internos: " << std::endl;
   contadorExperto = 0;

   if( sector == INTERNO )
   {
      cout << nombre << std::endl;
      contadorExperto++;  
   }
   if( contadorExperto == 0 )    // Si el contador es 0, no hay jurados internos
   {
      cout << "\nActualmente no hay ningun jurado interno" << std::endl;
   }

   cout << '\n';
   cout << "\nJurados externos: " << std::endl;
   contadorExperto = 0;
   
   if( sector == EXTERNO )
   {
      cout << nombre << std::endl;
      contadorExperto++;
   }

   if( contadorExperto == 0 )
   {
      cout << "\nActualmente no hay ningun jurado externo" << std::endl;
   }
   
   cout << '\n';
}
