#include <iostream>

using namespace std;
/*Ordenamiento iterativos*/

//Intercambio
void intercambio(int arr[], int ls){
    int aux = 0;
    for(int i = 0; i<ls-1;i++){
        for(int j=i; j < ls;j++){
            if(arr[i]>arr[j])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    for(int i = 0; i<ls;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
    
}

//Bubble Sort
void bubbleSort(int arr[],int ls){
    int aux = 0;
    bool check = true;
    for(int i = 0; i<ls-1 && check;i++){
        check = false;
        for(int j=0; j < ls-1-i;j++){
            if(arr[j]>arr[j+1])
            {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                check = true;
            }
        }
    }
    for(int i = 0; i<ls;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}

//seleccionDirecta
void seleccionDirecta(int arr[],int ls){
    int aux = 0;
    int aux1 =0;
    for(int i = 0; i<ls-1 ;i++){
        aux=i;
        for(int j=i+1; j < ls;j++){
            if(arr[aux]>arr[j])
            {
                aux = j;         
            }
        }
        if(i!=aux){
            aux1 = arr[i];
            arr[i] = arr[aux];
            arr[aux] =aux1;
        }
    }
    for(int i = 0; i<ls;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}

//Insertion Sort
void insertionSort(int arr[], int ls){
    int aux = 0,j;
    for(int i = 0; i<ls-1;i++){
        aux=arr[i];
        for(j=i; j > 0 && aux < arr[j-1];j--){
            arr[j]=arr[j-1];
        }
        arr[j]=aux;
    }
    for(int i = 0; i<ls;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main(){
    int arr[10];
    int li=0;
    int ls=10;
    for(int i = 0;i<10;i++){
        cin >> arr[i];
    }

    
    intercambio(arr,ls);
    bubbleSort(arr,ls);
    seleccionDirecta(arr,ls);
    insertionSort(arr,ls);

    return 0;
}