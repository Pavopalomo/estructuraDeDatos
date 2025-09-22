#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dayToInt(string day){//Regresa el numero de mes
  int i = 0;
   vector<string> days = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct",  "Nov", "Dec"};
  for(i = 0;i < 12; i++){
    if(day == days.at(i)){
      return i;
    }
  }
  return -1;
}//(O(12))

void merge(vector<string>& bitOrd, int li, int ls) {
  int liT = li, len = ls - li + 1;
  vector<string> arrTemp;
  int med = (li + ls) / 2 + 1, medC = med, i = 0;


  while (li < medC && med <= ls) {
    int subli = dayToInt(bitOrd.at(li).substr(0,3));
    int submed = dayToInt(bitOrd.at(med).substr(0,3));
    if (subli > submed)
    {
      arrTemp.push_back(bitOrd.at(med));
      med++;
    }
    else if(subli == submed)
    {
      int intli = stoi(bitOrd.at(li).substr(4,6));
      int intmed = stoi(bitOrd.at(med).substr(4,6));

      if(intli > intmed)
      {
        arrTemp.push_back(bitOrd.at(med));
        med++;
      }
      else 
      {
        arrTemp.push_back(bitOrd.at(li));
        li++;
      }
    }
    else
    {
      arrTemp.push_back(bitOrd.at(li));
      li++;
    }

    i++;
  }


    while(li<medC){
        arrTemp.push_back(bitOrd.at(li));
        i++;
        li++;
    }
    
    while(med<=ls){
        arrTemp.push_back(bitOrd.at(med));
        i++;
        med++;
    }
    
    for(int j = liT, k=0; j<=ls;j++, k++){
        bitOrd.at(j) = arrTemp.at(k);
    }
    
       
}//O(n)

void ordenaMerge(vector<string>& bitOrd, int li, int ls){
    if(li >= ls) return;
    ordenaMerge(bitOrd, li,(li+ls)/2);
    ordenaMerge(bitOrd, (li+ls)/2+1, ls);
    return merge(bitOrd, li, ls);
    
}//O(n log n)


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
    ordenaMerge(month_lines, 0, month_lines.size() - 1);

    ofstream sorted("sorted.txt");//Crea el archivo llamado sorted.txt
    if (!sorted){//Si no se crea el archivo
      cerr << "Error al crear el archivo";
      return 1;
    }

  for (const auto &l : bitOrd) {//escribe todo el documento ordenado
      sorted << l<<endl;
    }
    sorted.close();


    for (size_t j = 0; j < month_lines.size(); j++) {
      const string &l = month_lines[j]; // l es la línea j-ésima de month_lines
      cout << l << '\n';
    }
  }

  return 0;
}
