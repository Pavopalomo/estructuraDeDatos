#include <iostream>

using namespace std;
/*Ordenamiento iterativos*/

//ordenaIntercambio
int ordenaIntercambio(int arr[], int ls){
    int aux = 0, count = 0;
    for(int i = 0; i<ls;i++){
        for(int j=i+1; j <= ls;j++){
            if(arr[i]>arr[j])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
            count++;
        }
    }
    
    return count;
}//O(n^2)

//Bubble Sort
int ordenaBurbuja(int arr[],int ls){
    int aux = 0, comp = 0, count =0;
    bool check = true;
    for(int i = 0; i<ls && check;i++){
        check = false;
        for(int j=0; j < ls-i;j++){
            if(arr[j]>arr[j+1])
            {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                check = true;
            }
            count++;
        }
    }  

    return count;
}//O(n^2)

/*Ordenamientos Recursivos*/
int merge(int arr[], int li, int ls){
    int liT=li, len=ls-li+1;
    int arrTemp[len];
    int med=(li+ls)/2 + 1, medC=med, count=0, i=0;

    while(li < medC && med <= ls){
        if(arr[li]>arr[med]){
            arrTemp[i] = arr[med];
            med++;
        }
        else{
            arrTemp[i] = arr[li];
            li++;
        }
        count++;
        i++;
        
    }
    

    while(li<medC){
        arrTemp[i] = arr[li];
        i++;
        li++;
    }
    
    while(med<=ls){
        arrTemp[i] = arr[med];
        i++;
        med++;
    }
    
    for(int j = liT, k=0; j<=ls;j++, k++){
        arr[j] = arrTemp[k];
    }
    
    
    return count;    
}//O(n)

int ordenaMerge(int arr[], int li, int ls){
    if(li >= ls) return 0;
    return ordenaMerge(arr, li,(li+ls)/2) + ordenaMerge(arr, (li+ls)/2+1, ls) + merge(arr, li, ls);
    
}//O(n log n)

int main(){
    int data=0, busq=0;
    cin>>data;
    int arrSwap[data], arrBubble[data], arrMerge[data];
    for(int i = 0;i<data;i++){
        cin >> arrSwap[i];
        arrBubble[i] = arrSwap[i];
        arrMerge[i] = arrSwap[i];
    }

    cout<<ordenaIntercambio(arrBubble, data-1)<<" "
        <<ordenaBurbuja(arrSwap, data-1)<<" "
        <<ordenaMerge(arrMerge, 0, data-1)<<" "<<endl;

    return 0;
}
