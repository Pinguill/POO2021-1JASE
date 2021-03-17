#ifndef EXPERTO_H
#define EXPERTO_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;


enum ingreso   // Verifica si el experto se ha registrado
{
   REGISTRADO,
   NO_REGISTRADO
};

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
      int trabajosDirigidos;
      ingreso registro;
      vector <Experto> expertosCreados;   

   public:
      Experto();
      Experto( string, string, sectorExperto, string );
      void registrarExperto();
      void consultarJurados(); // Consulta jurados externos e internos
      void getExperto();
};

#endif