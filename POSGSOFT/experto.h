#ifndef EXPERTO_H
#define EXPERTO_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;



enum sectorExperto   // Indica si el jurado es profesor de universidad o no
{
   INTERNO,
   EXTERNO
};

class Experto{
   private:
      string user;
      string password;
      sectorExperto sector;   // Se refiere a si el jurado es interno o externo, lo cambié de Bool a Enum
      string nombre;
      int trabajosDirigidos = 0;

   public:
      Experto();
      Experto( string, string, sectorExperto, string );
      int consultarJurados(); // Consulta jurados externos e internos
      void getExperto();
      string getUsuario();
      string getPass();
      string getNombre();
};

#endif