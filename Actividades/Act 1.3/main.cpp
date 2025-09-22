#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
  vector<string> meses = {"Jan", "Feb", "Mar", "Aprl", "May", "Jun",
                          "Jul", "Aug", "Sep", "Oct",  "Nov", "Dec"};

  int mesinicio, diaInicio, mesfin, diaFin;
  cin >> mesinicio;
  cin >> diaInicio;
  cin >> mesfin;
  cin >> diaFin;

  // Asegurarse no poner -31 de febrero
  if (mesinicio < 1 || mesfin < 1 || mesinicio > 12 || mesfin > 12 ||
      mesinicio > mesfin || diaInicio < 1 || diaInicio > 31 || diaFin < 1 ||
      diaFin > 31) {
    cerr << "Rango de fechas inválido\n";
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
      const string &l = lineas[j]; 
      size_t posicionDeMes = l.find(meses[i]);
      if (posicionDeMes != string::npos) {
        // los días están en los 2 caracteres siguientes al mes + espacio
        int dia = stoi(l.substr(posicionDeMes + 4, 2));
        if ((i + 1 == mesinicio && dia < diaInicio) ||
            (i + 1 == mesfin && dia > diaFin))
          continue;

        month_lines.push_back(l);
      }
    }

    // linea original usando funcion sort del vector... Pero no se puede usar el sort del vector :''V
    //    sort(month_lines.begin(), month_lines.end()); 
    mergeSort(month_lines, 0, month_lines.size() - 1);

    for (size_t j = 0; j < month_lines.size(); j++) {
      const string &l = month_lines[j]; // l es la línea j-ésima de month_lines
      cout << l << '\n';
    }
  }

  return 0;
}
