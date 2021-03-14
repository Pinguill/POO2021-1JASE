#ifndef EXPERTO_H
#define EXPERTO_H

#include <vector>
#include <string>

using std::vector;
using std::string;

vector <string> nombre;

class Experto{
   private:
      bool sector;
      string nombre;
      int trabajosDirigidos;

   public:
      Experto();
      Experto( bool, string, int );
      void getExperto();
};

#endif