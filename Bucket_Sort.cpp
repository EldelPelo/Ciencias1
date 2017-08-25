#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void ordenamiento_cubetas(int arreglo[], int tamArreglo, int mayor){
    vector<int> cubetas[10], temporal;
    int elemento;
    int potencia = log10(mayor)+1;
    for(int i=1; i<=pow(10,potencia); i*=10){
        for(int j=0; j<tamArreglo; j++){
            elemento = arreglo[j];
            cubetas[(elemento/i)%10].push_back(elemento);
        }
        for(int i=0;i<10;i++){
            for(int j=0; j<cubetas[i].size();j++){
                elemento = cubetas[i][j];
                temporal.push_back(elemento);
            }
            cubetas[i].clear();
        }
        for(int i=0; i<tamArreglo; i++){
            arreglo[i]=temporal[i];
        }
        temporal.clear();
    }
}
int hallarMayor(int a[], int tamanio){
    int mayor = a[0];
    for(int i=0;i<tamanio;i++){
        if(mayor<a[i]){
            mayor = a[i];
        }
    }
    return mayor;
}
int main(){
    int a[] = {29,25,3,100,9,37,21,43,99,67,45,81,10}, n = 13, mayor;
    mayor= hallarMayor(a,n);
    ordenamiento_cubetas(a,n,mayor);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
