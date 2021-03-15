#ifndef ACTA_H
#define ACTA_H
#include <iostream>

using std::string;


enum class aceptacion   // Enum para saber la calificacion final del acta ( no calificacion puntual )
{
   ACEPTADO,
   RECHAZADO,
   PENDIENTE 
};

enum class estado   // Enum para el estado del acta
{
    ABIERTA,
    CERRADA
};

enum class trabajo  // Enum para el tipo de trabajo
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
        float notaFinal;
        string director;
        bool existeCodirector;
        string codirector;
        string jurado1;
        string jurado2;    
        estado estadoTrabajo;   // Hace referencia a si el acta está abierta o cerrada
        aceptacion estadoAceptacion;    // Significa si está aprobado, rechazado o pendiente
        
    public:
        ActaTrabajo();
        ActaTrabajo( int, string, string, string, trabajo, string, float, string, string, string, estado, aceptacion );
        ActaTrabajo( int, string, string, string, trabajo, string, float, string, string, string, string, estado, aceptacion );
        void crearActa();   
        void cerrarActa();
        void calificarCriterios();  
        int calificarNotaFinal();
        void addComentario();    // Añade comentarios en caso de que los jurados lo deseen     

};
#endif