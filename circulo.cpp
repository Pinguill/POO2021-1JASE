#include <iostream>
#include <stdlib.h>
#include <math.h>

class Circulo{
   private:
      float radio;
      float PI = 3.1416;
   public:
      Circulo();
      Circulo( float radio );
      void calcularArea();
      void calcularPerimetro();
      float getRadio();
      void setRadio( float radio );
};

class Rectangulo{
   private:
      float largo, ancho;
   public:
      Rectangulo();
      Rectangulo( float, float ); 
      void calcularPerimetro();
      void calcularArea();
};

class Triangulo{
   private:
      float a, b, c;
   public:
      Triangulo();
      Triangulo( float, float, float );
      void calcularArea();
      void calcularPerimetro();
};

Triangulo::Triangulo(){
   this->a = 0;
   this->b = 0;
   this->c = 0;
}

Triangulo::Triangulo( float a, float b, float c ){
   this->a = a;
   this->b = b;
   this->c = c;
}

void Triangulo::calcularArea(){
   float area;
   area = ( a * b ) / 2;
   std::cout << "El area del triangulo es: " << area << std::endl;
}

void Triangulo::calcularPerimetro(){
   float perimetro;
   perimetro = a + b + c;
   std::cout << "El perimetro del triangulo es: " << perimetro << std::endl;
}

Rectangulo::Rectangulo(){
   this->largo = 0;
   this->ancho = 0;
}

Rectangulo::Rectangulo( float largo, float ancho ){
   this->largo = largo;
   this->ancho = ancho;
}

void Rectangulo::calcularPerimetro(){
   float perimetro;
   perimetro = (2 * this->largo) + (2 * this->ancho);
   std::cout << "El perimetro del rectangulo es: " << perimetro << std::endl;
}

void Rectangulo::calcularArea(){
   float area;
   area = this->largo * this->ancho;
   std::cout << "El area del rectangulo es: " << area << std::endl;
}

Circulo::Circulo(){
   this->radio = 0;
}

Circulo::Circulo( float radio ){
   this->radio = radio;
   std::cout<< "Si creo el circulo con radio: "<< radio <<"\n";
}

void Circulo::calcularArea(){
   float area;
   area = this->PI * pow( radio, 2 );
   std::cout<< "El area del circulo es: "<< area <<"\n";
}

void Circulo::calcularPerimetro(){
   float perimetro;
   perimetro = 2 * this->PI * this->radio;
   std::cout << "El perimetro del circulo es: "<< perimetro <<"\n";
}

float Circulo::getRadio(){
   return this->radio;
}

void Circulo::setRadio( float radio ){
   this->radio = radio;
}

void menu(){
   int opc, contCirculo = 0, contRectangulo = 0, contTriangulo = 0;
   float valorRadio, valorLargo, valorAncho, a, b, c;
   const int tam = 10;
   Circulo arrayCirculo[ tam ];
   Rectangulo arrayRectangulo[ tam ];
   Triangulo arrayTriangulo[ tam ];
   do{
      std::cout << "Que figura quiere elegir?\n1. Circulo\n2. Rectangulo\n3. Triangulo\n0. Salir\n";
      std::cin >> opc;
      switch( opc ){
         case 1:
            std::cout << "Ingrese el valor del radio: \n";
            std::cin >> valorRadio;
            arrayCirculo[ contCirculo++ ] = Circulo( valorRadio );
            break;
         case 2:
            std::cout << "Ingrese el valor del largo: \n";
            std::cin >> valorLargo;
            std::cout << "Ingrese el valor del largo: \n";
            std::cin >> valorAncho;
            arrayRectangulo[ contRectangulo++ ] = Rectangulo( valorLargo, valorAncho );
            break;
         case 3:
            std::cout << "Ingrese el valor de a: \n";
            std::cin >> a;
            std::cout << "Ingrese el valor de b: \n";
            std::cin >> b;
            std::cout << "Ingrese el valor de c: \n";
            std::cin >> c;
            arrayTriangulo[ contTriangulo++ ] = Triangulo( a, b, c );
            break;
         default:
            break;
      }
   } while( opc != 0 );
}

int main(){
   menu();
   return 0;
}