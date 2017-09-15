#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
};
class ListaDinamica{
	 protected: Nodo *cab;
	//Metodos
	public:
		ListaDinamica();
		void agregar(int);
		void mostrar();
		void ordenar();
		bool vacia();
};
ListaDinamica::ListaDinamica(){
	cab=NULL;
}
void ListaDinamica::agregar(int dato){
	Nodo *p=new Nodo;
	(*p).dato=dato;
	(*p).sig=cab;
	cab=p;
}
void ListaDinamica::mostrar(){
	Nodo *p=cab;
	while(p!=NULL){//while(p)
		cout<<(*p).dato<<" ";
		p = (*p).sig;
	}
}
void ListaDinamica::ordenar(){
	Nodo *p=cab;
	Nodo *q=cab->sig;
	Nodo *temp;
	while((*p).sig!=NULL){
		while((*q).sig!=NULL){
			if((*p).dato>(*q).dato){
				temp = q;
				p = q;
				q = temp;
				cout<<"O ";
			}
			q=(*q).sig;
		}
		p=(*p).sig;
	}
}
bool ListaDinamica::vacia(){
	if(cab==NULL){
		return false;
	}
	return true;
}
class Cola: public ListaDinamica{
	private:
		Nodo *fin;
	public:
		Cola();
		void agregar(int);
		int eliminar();
};
Cola::Cola(){
	cab=fin=NULL;
}
void Cola::agregar(int dato){
	Nodo *p = new Nodo;
	p->dato=dato;
	p->sig=NULL;
	if(!cab){
		cab=p;
	}else{
		fin->sig = p;
	}
	fin=p;
}
int Cola::eliminar(){
	int dato = cab->dato;
	Nodo *p = cab;
	cab = cab->sig;
	delete p;
	return dato;
}
class Pila: public ListaDinamica{
	public:
		int eliminar();	
};
char menu();
int main(){
	ListaDinamica lista;
	char opcion;
	int dato;
	do{
		opcion = menu();
		switch(opcion){
			case 'A':
			case 'a':
				cout<<"Ingrese el dato que desea agregar: ";
				cin>>dato;
				lista.agregar(dato);
				break;
			case 'E':
			case 'e':
				cout<<"El elemento se ha eliminado\n";
				break;
			case 'O':
			case 'o':
				cout<<"La lista ha sido ordenada\n";
				lista.ordenar();
				break;
			case 'M':
			case 'm':
				cout<<"Lista dinamica: ";
				lista.mostrar();
				break;
			case 'S':
			case 's':
				break;
		}
	}while(opcion!='s' && opcion!='S');
}
char menu(){
	char opcion;
	cout<<"\n MENU \n";
	cout<<"(A)gregar\n";
	cout<<"(E)liminar\n";
	cout<<"(O)rdenar\n";
	cout<<"(M)ostrar\n";
	cout<<"(S)alir\n";
	cout<<"Ingrese la opcion que desea: ";
	cin>>opcion;
	return opcion;
}
