#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "experto.h"
#include "actaTrabajo.h"
#include "criteriosCalificacion.h"
#include <vector>
#include <cctype>
 #include <algorithm>

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
      void mostrarActas(); // No tiene validaciones
      void mostrarPersona();  // No tiene validaciones
      void mostrarCriterio(); // No tiene validaciones
      void crearActa(); // Falta validar cuando el usuario pone un valor string en vez de int en menús
      void consultarTipoTrabajo();  //Validaciones hechas
      void consultarEstadoAceptacion();   // Validaciones hechas
      void registrarExperto();   //  Falta validar cuando el usuario pone un valor string en vez de int en menús
      void consultarJurados();   // Validaciones hechas
      void cerrarActa();   // Validaciones hechas
      void consultarTrabajoProfesor(); //  Falta validar cuando el usuario pone un valor string en vez de int en menús
};

#endif