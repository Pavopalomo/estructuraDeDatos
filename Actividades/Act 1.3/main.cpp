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

  if (mesinicio < 1 || mesfin < 1 || mesinicio > 12 || mesfin > 12 ||
      mesinicio > mesfin) {
    cerr << "Rango de meses inválido (1 <= inicio <= fin <= 12)\n";
    return 1;
  }
  ifstream file("bitacora.txt");

  if (!file.is_open()) {
    cerr << "Error: no se pudo abrir el archivo bitacora.txt\n";
    return 1;
  }

  vector<string> lineas;
  string linea;

  while (getline(file, linea))
    lineas.push_back(linea);
  file.close();

  for (int i = mesinicio - 1; i <= mesfin - 1; ++i) {
    vector<string> month_lines;
    for (size_t j = 0; j < lineas.size(); j++) {
      const string &l = lineas[j]; // aquí l es solo un alias a lineas[j]
      if (l.find(days[i]) != string::npos) {
        month_lines.push_back(l);
      }
    }

    sort(month_lines.begin(), month_lines.end()); // sort por mes
    for (size_t j = 0; j < month_lines.size(); j++) {
      const string &l = month_lines[j]; // l es la línea j-ésima de month_lines
      cout << l << '\n';
    }
  }

  return 0;
}
