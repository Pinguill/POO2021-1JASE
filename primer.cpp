#include <iostream>

using namespace std;
const float IVA = 1.19;

float proceso(){
   float valor, result;
   cout<<"Ingrese el valor que quiere agregarle el iva:\n";
   cin >> valor;
   result = valor * IVA;
   return result;
}

int main(){
   float result;
   result = proceso ();
   cout << "El valor del producto con IVA es: " <<result<< "\n";
   return 0;
}