#ifndef CONJUNTO_H
#define CONJUNTO_H

#include "experto.h"
#include "actaTrabajo.h"
#include "criteriosCalificacion.h"
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <fstream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::ofstream;

class Universidad{
   private:
      int contadorTrabajoAplicado = 0; 
      int contadorTrabajoInvestigacion= 0;
      vector <Experto> vectorPersonas;
      vector <ActaTrabajo> vectorActasTrabajos;

   public:
      Universidad();
      void mostrarActas(); 
      void mostrarPersona();  
      void mostrarCriterio(); 
      void crearActa(); 
      void consultarTipoTrabajo();  
      void consultarEstadoAceptacion();   
      void registrarExperto();   
      void consultarJurados();   // Consulta jurados externos e internos
      void cerrarActa();   
      void consultarTrabajoProfesor(); // Cuales y cuantos trabajos ha dirigido un profesor
      void consultarTrabajosJurado();
      void consultarListaJurados(); // Consultar lista de jurados en las actas sin repetir
      void diligenciarActa();
      void diligenciarObservaciones();
      void eliminarActa();
      void crearTxt();
};

#endif