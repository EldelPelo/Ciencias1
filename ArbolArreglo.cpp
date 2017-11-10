//Arbol binario como arreglo
#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	int izq,der;
};

class ArbolBinOrd{
	int tamanio;
	Nodo *nodo;
	//Metodos
	public:
		ArbolBinOrd(int);
		int getRaiz();
		void setRaiz(int);
		int nuevo();//Crea un nodo
		void libre(int);//Libera una posicion
		int agregar(int,int);
		void mostrarInorden(int);
		void mostrarPreorden(int);
		void mostrarPosorden(int);
		void mostrarNiveles(int);
		int buscar(int);//Retorna posicion elemento;
		int contarNodos(int);
		int contarHojas(int);
};
ArbolBinOrd::ArbolBinOrd(int tamanio){
	int i;
	this->tamanio = tamanio;
	nodo = new Nodo[tamanio];
	nodo[0].izq=-1;
	nodo[0].der=1;
	for(i=1;i<tamanio-1;i++){
		nodo[i].der=i+1;
	}
	nodo[i].der=-1;
};
int ArbolBinOrd::getRaiz(){
	return nodo[0].izq;
}
void ArbolBinOrd::setRaiz(int raiz){
	nodo[0].izq=raiz;
}
int ArbolBinOrd::nuevo(){
	int k= nodo[0].der;
	nodo[0].der=nodo[nodo[0].der].der;
	return k;
}
void ArbolBinOrd::libre(int k){
	nodo[k].der=nodo[0].der;
	nodo[0].der=k;
}
int ArbolBinOrd::agregar(int raiz,int dato){
	if(raiz!=-1){
		if(nodo[raiz].dato>dato){
			nodo[raiz].izq=agregar(nodo[raiz].izq,dato);
		}else{
			nodo[raiz].der=agregar(nodo[raiz].der,dato);
		}	
	}else{
		raiz = nuevo();
		nodo[raiz].dato = dato;
		nodo[raiz].izq = -1;
		nodo[raiz].der = -1;
	}
	return raiz;

}
void ArbolBinOrd::mostrarInorden(int raiz){
	if(raiz!=-1){
		mostrarInorden(nodo[raiz].izq);
		cout<<nodo[raiz].dato<<" ";
		mostrarInorden(nodo[raiz].der);
	}
}
char menu(){
	char opcion;
	cout<<"\n(A)gregar\n";
	cout<<"(E)liminar\n";
	cout<<"(P)rofundidad\n";
	cout<<"(B)uscar\n";
	cout<<"(I)norden\n";
	cin>>opcion;
	return opcion;
}
int main(){
	char opcion;
	ArbolBinOrd arbol(50);
	int raiz;
	int elemento;
	do{
		opcion=menu();
		switch(opcion){
			case'a':
			case'A':
				raiz = arbol.getRaiz();
				cout<<"\nElemento: ";
				cin>>elemento;
				arbol.agregar(raiz,elemento);
				break;
			case'i':
			case'I':
				raiz = arbol.getRaiz();
				arbol.mostrarInorden(raiz);
				break;
		}
	}while(opcion!='s'&&opcion!='S');
}
