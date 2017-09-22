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
	private int m, n;
	NodoLinea *cabFila, *cabCol;
	public:
		Matriz(int,int);
		void agregar(int,int,int);
		void cargar();//Fila, Columna, Valor.Si Fila=-1 Terminar
		void mostrar();
		Matriz operator + (Matriz);
		void operator = (Matirz);
};
Matriz::Matriz(int m, int n){
	this->m=m;
	this->n=n;
	cabFila=cabCol=NULL;
}
void Matriz::agregar(int,int,int){
	if(cabFila==NULL&&cabCol==NULL){
		
	}
}
void Matriz::cargar(){
	
}
void Matriz::mostrar(){
	
}
Matriz Matriz::operator + (Matriz A){
	
}
void Matriz::operator = (Matriz A){
	
}
int main(){
	
}
