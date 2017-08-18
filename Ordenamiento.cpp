#include <iostream>

using namespace std;

class Arreglo{
	int tamanio;
	int *elementos;
	//Metodos
	public:
		Arreglo(int);
		void cargar();
		int burbuja();
		void insercion();
		void shell();
		void quicksort();
		void mergesort();
		void cubetas();
		void mostrar();
};
Arreglo::Arreglo(int tamanio){
	this->tamanio = tamanio;
	elementos = new int [tamanio];
}
void Arreglo::cargar(){
	for(int k=0;k<tamanio;k++){
		cout<<"Ingresando el elemento "<<k+1<<": "<<endl;
		cin>>elementos[k];
	}
}
int Arreglo::burbuja(){
	int aux,op=0;
	for(int i=0;i<tamanio;i++){
		for(int j=i+1;j<tamanio;j++){
			op++;
			if(elementos[i]>elementos[j]){
				aux = elementos[i];
				elementos[i] = elementos[j];
				elementos[j] = aux;
			}
		}
	}
	return op;
}
void Arreglo::mostrar(){
	for(int k=0;k<tamanio;k++){
		cout<<elementos[k]<<" ";
	}
}
int main(){
	int n;
	cout<<"Ingresar tamaño del arreglo: ";
	cin>>n;
	Arreglo A(n);
	cout<<"Digite los elementos del arreglo: ";
	A.cargar();
	cout<<"Burbuja"<<endl;
	cout<<"Numero de operaciones: "<<A.burbuja()<<endl;
	A.mostrar();
}
