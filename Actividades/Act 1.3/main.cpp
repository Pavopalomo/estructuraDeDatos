#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// aca viene el codigo que me dió chatgpt, ahí te encargo que lo cheques aca bn
// aca porfas
// Función para combinar dos sub-vectores ordenados
void merge(std::vector<std::string> &v, int left, int mid, int right) {
  std::vector<std::string> temp(right - left + 1);

  int i = left;    // inicio del primer subvector
  int j = mid + 1; // inicio del segundo subvector
  int k = 0;       // índice del vector temporal

  while (i <= mid && j <= right) {
    if (v[i] <= v[j])
      temp[k++] = v[i++];
    else
      temp[k++] = v[j++];
  }

  while (i <= mid)
    temp[k++] = v[i++];
  while (j <= right)
    temp[k++] = v[j++];

  for (int t = 0; t < k; ++t)
    v[left + t] = temp[t];
}

// Función recursiva de merge sort
void mergeSort(std::vector<std::string> &v, int left, int right) {
  if (left >= right)
    return;

  int mid = left + (right - left) / 2;
  mergeSort(v, left, mid);
  mergeSort(v, mid + 1, right);
  merge(v, left, mid, right);
}


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

    // linea original usando funcion sort del vector
    //    sort(month_lines.begin(), month_lines.end()); // sort por mes
    // aca chatgpt me dio esta linea igual checala porfa
    mergeSort(month_lines, 0, month_lines.size() - 1);

    for (size_t j = 0; j < month_lines.size(); j++) {
      const string &l = month_lines[j]; // l es la línea j-ésima de month_lines
      cout << l << '\n';
    }
  }

  return 0;
}
