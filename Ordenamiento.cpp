#include <iostream>

using namespace std;

class Arreglo{
	int tamanio;
	int *elementos;
	//Metodos
	public:
		Arreglo(int);
		void operator = (Arreglo);
		void cargar();
		int burbuja();
		int insercion();
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
void operator = (Arreglo A){
	this->tamanio=A.tamanio;
	for(int k=0;k<tamanio;k++){
		this->elemento[k]=A.elemento[k];
	}
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
int Arreglo::insercion(){
	int j=1,k,aux;
	while(j<tamanio){
		k=j-1;
		aux = elementos[j];
		while(k>=0&&elementos[k]>elementos[j]){
			elementos[j]=elementos[k];
			k--;
		}
		elementos[k+1]=aux;
		j++;
	}
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
	Arreglo A(n), B(n);
	cout<<"Digite los elementos del arreglo: ";
	A.cargar();
	B=A;
	cout<<"Burbuja"<<endl;
	cout<<"Numero de operaciones: "<<B.burbuja()<<endl;
	B.mostrar();
	B=A;
	cout<<"Insercion"<<endl;
	cout<<"Numero de operaciones: "<<B.insercion()<<endl;
	B.mostrar();
	B=A;
	cout<<"Burbuja"<<endl;
	cout<<"Numero de operaciones: "<<B.burbuja()<<endl;
	B.mostrar();
	B=A;
	cout<<"Burbuja"<<endl;
	cout<<"Numero de operaciones: "<<B.burbuja()<<endl;
	B.mostrar();
}
