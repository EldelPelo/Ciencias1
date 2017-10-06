#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *izq;
	Nodo *der;
};

class ArbolBinario{
	Nodo *raiz;
	//Metodos
	public:
		ArbolBinario();
		Nodo *agregar(Nodo *, int dato);
		int eliminar();
		void mostrarPreorden(Nodo *);
		void mostrarPosorden(Nodo *);
		void mostrarInorden(Nodo *);
		void mostrarNiveles();
		int profundidad();
		Nodo *buscar(Nodo *, int);
		Nodo *getRaiz();
		void setRaiz(Nodo *);
};
ArbolBinario::ArbolBinario(){
	raiz = NULL;
}
Nodo *ArbolBinario::getRaiz(){
	return raiz;
}
void ArbolBinario::setRaiz(Nodo *raiz){
	this->raiz = raiz;
}
Nodo * ArbolBinario::agregar(Nodo *raiz, int dato){
	if(raiz){
		int rama = rand()%2;
		if(rama == 0){
			raiz->izq=agregar(raiz->izq, dato);
		}else{
			raiz->der=agregar(raiz->der, dato);
		}
	}else{
		raiz = new Nodo;
		raiz->dato=dato;
		raiz->izq=NULL;
		raiz->der=NULL;
	}
	return raiz;
}
void ArbolBinario::mostrarPreorden(Nodo *raiz){
	if(raiz){
		cout<<raiz->dato<<" ";
		mostrarPreorden(raiz->izq);
		mostrarPreorden(raiz->der);
	}
}
void ArbolBinario::mostrarInorden(Nodo *raiz){
	if(raiz){
		mostrarPreorden(raiz->izq);
		cout<<raiz->dato<<" ";
		mostrarPreorden(raiz->der);
	}
}
void ArbolBinario::mostrarPosorden(Nodo *raiz){
	if(raiz){
		mostrarPreorden(raiz->izq);
		mostrarPreorden(raiz->der);
		cout<<raiz->dato<<" ";
	}
}
Nodo *ArbolBinario::buscar(Nodo *raiz, int elemento){
	if(raiz->dato==elemento){
		return raiz;
	}else{
		if(raiz->izq){
			buscar(raiz->izq,elemento);
		}
		else{
			buscar(raiz->der,elemento);
		}
	}
} 
char menu();
int main(){
	srand(time(NULL));
	int dato;
	char opcion;
	Nodo *raiz;
	Nodo *encontrado;
	ArbolBinario arbol;
	raiz = arbol.getRaiz();
	do{
		opcion=menu();
		switch(opcion){
			case'a':
			case'A':
				cout<<"\nIngrese el dato: ";
				cin>>dato;
				raiz = arbol.getRaiz();
				arbol.setRaiz(arbol.agregar(raiz, dato));
				break;
			case'p':
			case'P':
				cout<<"Preorden\n";
				raiz = arbol.getRaiz();
				arbol.mostrarPreorden(raiz);
				break;
			case'o':
			case'O':
				cout<<"Posorden\n";
				raiz = arbol.getRaiz();
				arbol.mostrarPosorden(raiz);
				break;
			case'i':
			case'I':
				cout<<"Inorden\n";
				raiz = arbol.getRaiz();
				arbol.mostrarInorden(raiz);
				break;
			case'b':
			case'B':
				cout<<"\nIngrese dato a buscar: ";
				cin>>dato;
				raiz = arbol.getRaiz();
				encontrado = arbol.buscar(raiz,dato);
				if(encontrado){
					cout<<"Enocontrado el elemento: "<<encontrado->dato<<"\n";
				}else{
					cout<<"No encontrado.\n";
				}
				break;	
		}
	}while(opcion!='s'&&opcion!='S');
	return 0;
}
char menu(){
	char opcion;
	cout<<"(A)gregar\n";
	cout<<"(E)liminar)\n";
	cout<<"(P)reorden)\n";
	cout<<"P(o)srden\n";
	cout<<"(I)norden)\n";
	cout<<"(N)iveles\n";
	cout<<"Pro(f)undidad\n";
	cout<<"(B)uscar\n";
	cout<<"Ingrese opcion: ";
	cin>>opcion;
	return opcion;
}
