#include <iostream>
#include <math.h>
using namespace std;
bool primo1(int n, int &);
bool primo2(int n, int &);
bool primo3(int n, int &);
bool primo4(int n, int &);
int main(){
	int n,op;
	cout<<"Ingrese un numero: ";
	cin>>n;
	cout<<"PRIMER METODO"<<endl;
	if(primo1(n,op))
		cout<<n<<" es primo"<<endl;
	else
		cout<<n<<" no es primo"<<endl;
	cout<<"Realizo: "<<op<<" modulos"<<endl;
	cout<<"SEGUNDO METODO"<<endl;
	if(primo2(n,op))
		cout<<n<<" es primo"<<endl;
	else
		cout<<n<<" no es primo"<<endl;
	cout<<"Realizo: "<<op<<" modulos"<<endl;
	cout<<"TERCER METODO"<<endl;
	if(primo3(n,op))
		cout<<n<<" es primo"<<endl;
	else
		cout<<n<<" no es primo"<<endl;
	cout<<"Realizo: "<<op<<" modulos"<<endl;
	cout<<"CUARTO METODO"<<endl;
	if(primo4(n,op))
		cout<<n<<" es primo"<<endl;
	else
		cout<<n<<" no es primo"<<endl;
	cout<<"Realizo: "<<op<<" modulos"<<endl;
	return 1;
}
bool primo1(int n, int &operaciones){
	int contDiv=0;
	operaciones = 0;
	for(int k=1;k<=n;k++){
		operaciones++;
		if(n%k==0)
			contDiv++;
	}
	return contDiv==2;
}
bool primo2(int n, int &operaciones){
	int k=2;
	operaciones = 0;
	bool primo = true;
	while(primo && k<n){
		operaciones++;
		if(n%k==0)
			primo = false;
		else
			k++;
	}
	return primo && n!=1;
}
bool primo3(int n, int &operaciones){
	int k=2;
	int mitad = n/2;
	operaciones = 0;
	bool primo = true;
	while(primo && k<mitad){
		operaciones++;
		if(n%k==0){
			primo = false;
		}else{
			k=(2*k)-1;
		}
	}
	return primo && n!=1;
}
bool primo4(int n, int &operaciones){
	int k=2;
	int raiz = sqrt(n);
	operaciones = 0;
	bool primo = true;
	while(primo && k<raiz){
		operaciones++;
		if(n%k==0){
			primo = false;
		}else{
			k=(2*k)-1;
		}
	}
	return primo && n!=1;
}
