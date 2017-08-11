#include <iostream>
using namespace std;

double factorialIterativo(int n, int &);
double factorialRecursivo(int n, int &);

int main(){
	int n,op;
	cout<<"Ingrese un numero: ";
	cin>>n;
	cout<<"ITERATIVO"<<endl;
	cout<<"El factorial del numero es: "<<factorialIterativo(n,op)<<endl;
	cout<<"Realizo: "<<op<<" modulos"<<endl;
	cout<<"RECURSIVO"<<endl;
	cout<<"El factorial del numero es: "<<factorialRecursivo(n,op)<<endl;
	cout<<"Realizo: "<<op<<" modulos"<<endl;
	return 1;
}

double factorialIterativo(int n, int &operaciones){
	double factorial = 1;
	operaciones = 0;
	for(int k=1; k<=n; k++){
		operaciones++;
		factorial*=k;
	}
	return factorial;
}
double factorialRecursivo(int n, int &operaciones){
	double factorial;
	if(n>0){
		factorial = factorialRecursivo(n-1,operaciones);
		operaciones++;
		return factorial*n;
	}else{
		operaciones = 0;
		return 1;
	}
}
