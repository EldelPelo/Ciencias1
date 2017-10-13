#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <queue>
#include <math.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *izq;
	Nodo *der;
};

class ArbolBinario{
	protected:
		Nodo *raiz;
	//Metodos
	public:
		ArbolBinario();
		Nodo *agregar(Nodo *, int dato);
		int eliminar();
		void mostrarPreorden(Nodo *);
		void mostrarPosorden(Nodo *);
		void mostrarInorden(Nodo *);
		void mostrarNiveles(Nodo *);
		int profundidad(Nodo *);
		Nodo *buscar(Nodo *, int);
		Nodo *getRaiz();
		void setRaiz(Nodo *);
		int contarHojas();
		int contarNodos();
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
int ArbolBinario::eliminar(){
	Nodo *padre, *hijo;
	
	if(raiz){
		
	}
}
void ArbolBinario::mostrarPreorden(Nodo *raiz){
	if(raiz){
		cout<<raiz->dato<<" ";
		mostrarPreorden(raiz->izq);
		mostrarPreorden(raiz->der);
	}
}
void ArbolBinario::mostrarInorden(){
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
			return buscar(raiz->izq,elemento);
    	}
		if(raiz->der){
        	return buscar(raiz->der,elemento);
		}
    }
}
void agregarHijos(queue<Nodo *> &cola, Nodo *raiz){
    if(raiz->izq){
        cola.push(raiz->izq);
    }
    if(raiz->der){
        cola.push(raiz->der);
    }
}
void ArbolBinario::mostrarNiveles(Nodo *raiz){
    Nodo *p = raiz;
    Nodo *elementoCola;
    int numeroNodos;
    queue<Nodo*> niveles;
    niveles.push(raiz);
    while(!niveles.empty()){
        numeroNodos = niveles.size();
        while(numeroNodos > 0){
            elementoCola = niveles.front();
            agregarHijos(niveles, elementoCola);
            cout<<elementoCola->dato<<" ";
            niveles.pop();
            numeroNodos--;
        }
        cout<<"\n";
    }
}
int ArbolBinario::profundidad(Nodo *raiz){
    if(!raiz){
        return 0;
    }else{
        int proIzq = profundidad(raiz->izq);
        int proDer = profundidad(raiz->der);
        if(proIzq> proDer){
            return(proIzq+1);
        }else{
            return(proDer+1);
        }
    }
}
/*int ArbolBinario::contarHojas(){
	if(raiz->dato==elemento){
		return raiz;
	}else if(raiz->izq){
        return buscar(raiz->izq,elemento);
    }else if(raiz->der){
        return buscar(raiz->der,elemento);
    }else{
        return NULL;
    }
}*/
class ArbolBinOrd:public ArbolBinario{
	public:
		ArbolBinOrd();
		Nodo *agregar(Nodo *, int);
		Nodo *buscar(Nodo *, int);
		Nodo *buscarRe(int);
};

ArbolBinOrd::ArbolBinOrd(){
	raiz = NULL;
}
Nodo *ArbolBinOrd::agregar(Nodo *raiz , int dato){
	if(raiz){
		if(raiz->dato>dato){
			raiz->izq=agregar(raiz->izq, dato);
		}else if(raiz->dato<dato){
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
Nodo *ArbolBinOrd::buscar(Nodo *raiz,int dato){
	if(raiz){
		if(raiz->dato==dato){
			return raiz;
		}else if(raiz->dato>dato){
				return buscar(raiz->izq,dato);
	    }else if(raiz->der){
	        return buscar(raiz->der,dato);
		}
	}
	return raiz;
}
Nodo *ArbolBinOrd::buscarRe(int dato){
	Nodo *p=raiz;
	while(p){
		if(p->dato==dato){
			return p;
		}if(p->dato>dato){
			p=p->izq;
	    }else{
	        p=p->der;
		}
	}
	return p;
}
char menu();
int main(){
	srand(time(NULL));
	int dato;
	char opcion;
	Nodo *raiz;
	Nodo *encontrado;
	//ArbolBinario arbol;
	ArbolBinOrd arbol;
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
                cout<<"\n";
				break;
			case'o':
			case'O':
				cout<<"Posorden\n";
				raiz = arbol.getRaiz();
				arbol.mostrarPosorden(raiz);
				cout<<"\n";
				break;
			case'i':
			case'I':
				cout<<"Inorden\n";
				raiz = arbol.getRaiz();
				arbol.mostrarInorden(raiz);
				cout<<"\n";
				break;
            case'N':
            case'n':
                cout<<"Niveles\n";
                raiz = arbol.getRaiz();
                arbol.mostrarNiveles(raiz);
                break;
            case'f':
            case'F':
                cout<<"Profundidad\n";
                raiz = arbol.getRaiz();
                cout<<"P: "<<arbol.profundidad(raiz)<<endl;
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
			case'c':
			case'C':
				//cout<<"Numero de hojas: "<< arbol.contarHojas()<<endl;
				break;
		}
	}while(opcion!='s'&&opcion!='S');
	return 0;
}
char menu(){
	char opcion;
	cout<<"MENU ARBOLES";
	cout<<"(A)gregar\n";
	cout<<"(E)liminar\n";
	cout<<"(P)reorden\n";
	cout<<"P(o)srden\n";
	cout<<"(I)norden\n";
	cout<<"(N)iveles\n";
	cout<<"Pro(f)undidad\n";
	cout<<"(B)uscar\n";
	cout<<"(C)ontar hojas\n";
	cout<<"Ingrese opcion: ";
	cin>>opcion;
	return opcion;
}
