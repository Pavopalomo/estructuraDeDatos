// Ordenamiento de arrays mediante diversos metodos
// Juan Jose Moreno Arenas: A01739611
// Gabriel Alejandro Palomino Lopez: A0

#include <iostream>

using namespace std;
/*Ordenamiento iterativos*/

// ordenaIntercambio
int ordenaIntercambio(int arr[], int ls) {
  int aux = 0, count = 0;
  for (int i = 0; i < ls; i++) {
    for (int j = i + 1; j <= ls; j++) {
      if (arr[i] > arr[j]) {
        aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
      }
      count++;
    }
  }

  return count;
}

// Bubble Sort
int ordenaBurbuja(int arr[], int ls) {
  int aux = 0, comp = 0, count = 0;
  bool check = true;
  for (int i = 0; i < ls && check; i++) {
    check = false;
    for (int j = 0; j < ls - i; j++) {
      if (arr[j] > arr[j + 1]) {
        aux = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = aux;
        check = true;
      }
      count++;
    }
  }

  return count;
}

// seleccionDirecta
void seleccionDirecta(int arr[], int ls) {
  int aux = 0, count = 0;
  int aux1 = 0;
  for (int i = 0; i < ls - 1; i++) {
    aux = i;
    for (int j = i + 1; j < ls; j++) {
      if (arr[aux] > arr[j]) {
        aux = j;
      }
      count++;
    }
    if (i != aux) {
      aux1 = arr[i];
      arr[i] = arr[aux];
      arr[aux] = aux1;
    }
  }
}

// Insertion Sort
void insertionSort(int arr[], int ls) {
  int aux = 0, j, count = 0;
  for (int i = 0; i < ls - 1; i++) {
    aux = arr[i];
    for (j = i; j > 0 && aux < arr[j - 1]; j--) {
      arr[j] = arr[j - 1];
    }
    count++;
    arr[j] = aux;
  }
}

int merge(int arr[], int li, int ls) {
  int liT = li, len = ls - li + 1;
  int arrTemp[len];
  int med = (li + ls) / 2 + 1, medC = med, count = 0, i = 0;

  while (li < medC && med <= ls) {
    if (arr[li] > arr[med]) {
      arrTemp[i] = arr[med];
      med++;
    } else {
      arrTemp[i] = arr[li];
      li++;
    }
    count++;
    i++;
  }

  while (li < medC) {
    arrTemp[i] = arr[li];
    i++;
    li++;
  }

  while (med <= ls) {
    arrTemp[i] = arr[med];
    i++;
    med++;
  }

  for (int j = liT, k = 0; j <= ls; j++, k++) {
    arr[j] = arrTemp[k];
  }

  return count;
}

int ordenaMerge(int arr[], int li, int ls) {
  if (li >= ls)
    return 0;
  return ordenaMerge(arr, li, (li + ls) / 2) +
         ordenaMerge(arr, (li + ls) / 2 + 1, ls) + merge(arr, li, ls);
}

// Algoritmos de busqueda
//

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
  int contador;

  while (minimo <= longitud - 1) {
    contador = contador + 1;
    int medio = (minimo + longitud);
    int auxiliar = arreglo[medio];
    if (auxiliar == item) {
      return medio;
    }
    if (auxiliar > item) {
      longitud = medio - 1;

    } else {
      minimo = medio + 1;
    }
  }

  cout << contador;
  return -1;
}

int main() {

  int data = 0, busq = 0;
  cin >> data; // data = n o longitud del arreglo
  int arrSwap[data], arrBubble[data], arrMerge[data];
  for (int i = 0; i < data; i++) {
    cin >> arrSwap[i];
    arrBubble[i] = arrSwap[i];
    arrMerge[i] = arrSwap[i];
  }

  cout << ordenaIntercambio(arrBubble, data - 1) << " "
       << ordenaBurbuja(arrSwap, data - 1) << " "
       << ordenaMerge(arrMerge, 0, data - 1) << " " << endl;

//cout << merge(arrMerge, 0, data -1);
        //insertionSort(arrMerge, data -1);
  // testeo busqueda
  //     int longitud
  // int numero;
  //int arreglo[data];
  //cout << "Numero a buscar en el arreglo" << endl;
  //cin >> numero;

  //for (int i = 0; i <= longitud - 1; i++) {
  //  cout << "ingresa posicion numero " << i << ": ";
  //  cin >> arreglo[i];
  //}

  //cout << busqBinaria(arreglo, numero, 5);

  return 0;
}
