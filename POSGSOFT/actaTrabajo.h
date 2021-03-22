#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <vector>
#include <ctime>
#include <iostream>
#include "criteriosCalificacion.h"

using std::string;
using std::vector;
using std::time_t;


enum aceptacion   // Enum para saber la calificacion final del acta ( no calificacion puntual )
{
   ACEPTADO,
   RECHAZADO,
   PENDIENTE 
};

enum estado   // Enum para el estado del acta
{
    ABIERTA,
    CERRADA
};

enum trabajo  // Enum para el tipo de trabajo
{
    APLICADO,
    INVESTIGACION
};

class ActaTrabajo
{
    private:
        int numero;     // Este sera el numero del acta, manejado como un código
        string fecha;
        string autor;   
        string nombreTrabajo;   
        trabajo tipoTrabajo;
        string periodo;     // Se refiere al año y semestre
        float notaFinal = 0;
        string director;
        bool existeCodirector;
        string codirector;
        string jurado1;
        string jurado2;    
        estado estadoTrabajo;   // Hace referencia a si el acta está abierta o cerrada
        aceptacion estadoAceptacion;    // Significa si está aprobado, rechazado o pendiente
        vector <Criterio> conjuntoCriterio;
        string observacionAdicional;
    public:
        ActaTrabajo();
        ActaTrabajo( int, string, string, string, trabajo, string, string, string, string, string, estado, aceptacion );
        ~ActaTrabajo(); // Destructor para eliminar un acta, elimina TODOS los objetos después de cerrar el programa
        void eliminarActa();  
        void mostrarActa();
        trabajo getTipoTrabajo();
        aceptacion getEstadoAceptacion();
        string getNombreTrabajo();
        int getNumeroActa();
        estado getEstadoTrabajo();
        string getDirector();
        void setEstadoTrabajo( estado );
        string getJuradoUno();
        string getJuradoDos();
        string getIdentificador( int );
        void setNota( float, float, int );
        void setComentario( string, int ); 
        void calcularNotaFinal();
        float getNotaFinal();
        void setEstadoAceptacion( aceptacion );
        void setObservacion( string );
        string getAutor();
        string getPeriodo();
        string getCodirector();
        float getNotaCriterio( int );
        float getPonderado( int );
        string getObservacion();
        string getComentario( int );
};

#endif