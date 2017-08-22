#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ordenamiento_cubetas(int arreglo[], int tamanio){
    int tam;
    vector<int> cubetas[10];
    vector<int> posicion;
    int elemento,cubeta;
    //LLenando cubetas
    for(int i=0;i<tamanio;i++){
        elemento = arreglo[i];
        cubeta = elemento/10;
        cubetas[cubeta].push_back(elemento);
    }

    cout<<"Cubetas llenas"<<endl;
    //Ordenando cubetas
    for(int i=0;i<10;i++){
        sort(cubetas[i].begin(),cubetas[i].end());
    }
    cout<<"Cubetas ordenadas"<<endl;
    //Mostrar ordenado
    for(int i=0;i<10;i++){
        for(int j=0; j<=cubetas[i].size()-1;j++){
            elemento = cubetas[i][j];
            cout<<elemento<<" ";
        }
        cout<<" \n";
    }
    cout<<"Mostrando cubetas"<<endl;
}
int main() {
    int i, a[] = {29,25,3,49,9,37,21,43,99,67,45,81,10}, n = 13;
    ordenamiento_cubetas(a,n);
    return 1;
}
