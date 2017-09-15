	//Listas doblemente enlazadas.
#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *ant;
	Nodo *sig;
};
class ListaDoble{
	Nodo *cab,*fin;
	//Metodos
	ListaDoble();
	void agregar(int);
	int eliminar();
	void eliminar(int);
	void mostrar();
	Nodo *buscar(int);
	bool vacia();
};
ListaDoble::ListaDoble(){
	cab=fin=NULL;
}
void ListaDoble::agregar(int dato){
	Nodo *p = new Nodo;
	p->dato = dato;
	p->sig = cab;
	if(cab){
		cab->ant=p;
	}else{
		fin=p;
	}
	p->ant=NULL;
	cab=p;
}
/*int ListaDoble::eiminar(){
}*/
void ListaDoble::eliminar(int dato){
	Nodo *p=cab,*s,*a;
	while(p){
		if(p->dato==dato){
			if(!p->ant){
				cab=p->sig;
				delete p;
			}else if(!p->sig){
				ant = p->ant;
				delete p;
			}else{
				a=p->ant;
				s=s->sig;
				a->sig=s;
				s->ant=a;
				delete p;
			}	
		}else{
			p=p->sig;
		}
	}	
}
void ListaDoble::mostrar(){
	Nodo *p=cab;
	while(p){
		cout<<p->dato<<" ";
		p = p->sig;
	}
}
Nodo *ListaDoble::buscar(int dato){
	Nodo *p=cab;
	while(p){
		if(p->dato==dato){
			return p;
		}else{
			p=p->sig;
		}
	}
	return p;	
}
bool ListaDoble::vacia(){
	if(cab==NULL){
		return false;
	}
	return true;	
}
int main(){
	
}
