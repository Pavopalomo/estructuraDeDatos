#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> days = {"Jan", "Feb", "Mar", "Aprl", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct",  "Nov", "Dec"};
  int mesinicio, mesfin;
  //  cout << "Da el mes de inicio en numero (enero = 1): ";
  cin >> mesinicio;
  // cout << "Da el mes de fin en numero (diciembre = 12): ";
  cin >> mesfin;

  ifstream file("bitacora.txt");

  if (!file.is_open()) {
    cerr << "Error: no se pudo abrir el archivo bitacora.txt\n";
    return 1;
  }

  vector<string> lineas;
  string linea;

  // Leer todas las líneas del archivo
  while (getline(file, linea)) {
    // Para cada mes en el rango [mesinicio, mesfin]
    for (int i = mesinicio - 1; i < mesfin; i++) {
      if (linea.find(days[i]) != string::npos) {
        lineas.push_back(linea);
        break; // evitar duplicar si hay coincidencia múltiple
      }
    }
  }

  file.close();

  // Ordenar las líneas (equivalente a sort en bash)
  sort(lineas.begin(), lineas.end());

  // Imprimir resultados
  for (const auto &l : lineas) {
    cout << l << "\n";
  }

  return 0;
}
