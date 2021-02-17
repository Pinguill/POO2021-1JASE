#include <iostream>

using namespace std;

void tomaDatos(){
   int edad;
   char sexo;
   float altura;
   cout << "Ingrese su edad: ";
   cin >> edad;
   cout << "Ingrese su sexo: ";
   cin >> sexo;
   cout << "Ingrese su altura: ";
   cin >> altura;
   cout << "Su edad es: " <<edad<< ", su sexo es: " <<sexo<< ", su altura es: " <<altura<< "\n";
   return;
}

int main(){
   tomaDatos();
   return 0;
}