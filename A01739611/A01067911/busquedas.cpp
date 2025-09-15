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

int busqBinaria(int *arreglo, int item, int longitud) {
  int minimo = 0;
  // int maximo = ;

  while (minimo <= longitud - 1) {
    int medio = (minimo + longitud);
    int auxiliar = arreglo[medio];
                if (auxiliar == item) {
                        return medio;
                
                }
                if (auxiliar > item) {
                        longitud = medio - 1;
                
                }
                else {
                minimo = medio + 1; 
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
        int arreglo[5] = {1,2,3,4,5};
  // int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

  cout << "Numero a buscar en el arreglo: {1,2,3,4,5}" << endl;
  cin >> numero;
  // cout << "longitud del arreglo" << endl;
  // cin >> longitud;

  // int arreglo[longitud];

  // for (int i = 0; i <= longitud - 1; i++) {
  //   cout << "ingresa posicion numero " << i << ": ";
  //   cin >> arreglo[i];
  // }

        cout << busqBinaria(arreglo, numero, 5);
  //cout << "Se encuentra en la posicion: ";
  //cout << busqSecuencial(arreglo, numero, longitud) << endl;

  // cout <<"oal chabo"<< endl ;
  return 0;
}
