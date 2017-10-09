#include <iostream>

using namespace std;

struct Nodo{
	float valor;
	int fila,col;
	Nodo *sigFila, *sigCol;
};
struct NodoLinea{
	int numero;
	Nodo *cabLinea;
	NodoLinea *sigLinea;
};
class Matriz{
	int m, n;
	NodoLinea *cabFila, *cabCol;
	public:
		Matriz(int,int);
		void agregar(int,int,int);
		void cargar();//Fila, Columna, Valor.Si Fila=-1 Terminar
		void mostrar();
		Matriz operator + (Matriz);
		void operator = (Matriz);
};
Matriz::Matriz(int m, int n){
	this->m=m;
	this->n=n;
	cabFila=cabCol=NULL;
}
void Matriz::agregar(int fil,int col,int num){
	if(cabFila==NULL&&cabCol==NULL){
		Nodo *p = new Nodo;
		NodoLinea *f = new NodoLinea;
		NodoLinea *c = new NodoLinea;
		p->fila = fil;
		p->col = col;
		p->valor = num;
		p->sigFila = NULL;
		p->sigCol = NULL;
		f->numero = fil;
		c->numero = col;
		f->cabLinea = p;
		c->cabLinea = p;
		f->sigLinea = NULL;
		c->sigLinea = NULL;
	}else{
        
	}
}
/*void Matriz::cargar(){

}
void Matriz::mostrar(){

}
Matriz Matriz::operator + (Matriz A){

}
void Matriz::operator = (Matriz A){

}*/
int main(){
    Matriz matriz(2,2);
    matriz.agregar(0,0,2);
    return 0;
}
