#include <iostream>
#include <string>
using namespace std;

int busqSecuencial(int *arreglo, int numero, int longitud) {

  // int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
  for (int i = 0; i <= longitud; i++) {
    if (arreglo[i] == numero) {
      return i;
    }
  }
  return -1;
}

int main() {

  // int arreglo[4] = {
  //     1,
  //     2,
  //     3,
  //     4,
  // };
  int longitud;
  int numero;
  // int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

  cout << "Numero a buscar" << endl;
  cin >> numero;
  cout << "longitud del arreglo" << endl;
  cin >> longitud;

  int arreglo[longitud];

  for (int i = 0; i <= longitud - 1; i++) {
    cout << "ingresa posicion numero " << i << ": ";
    cin >> arreglo[i];
  }

  cout << "Se encuentra en la posicion: ";
  cout << busqSecuencial(arreglo, numero, longitud) << endl;

  // cout <<"oal chabo"<< endl ;
  return 0;
}
