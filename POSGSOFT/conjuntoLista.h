#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "experto.h"
#include "actaTrabajo.h"
#include "criteriosCalificacion.h"
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;

class Universidad{
private:
   int contadorTrabajoAplicado = 0; 
   int contadorTrabajoInvestigacion= 0;
   vector <Experto> vectorPersonas;
   vector <ActaTrabajo> vectorActasTrabajos;
   vector <Criterio> vectorCriterios;
public:
   Universidad();
   void mostrarActas();
   void mostrarPersona();
   void mostrarCriterio();
   void crearActa();
   void consultarTipoTrabajo();
   void consultarEstadoAceptacion();
   void registrarExperto();
   void consultarJurados();
   void cerrarActa();
};

#endif