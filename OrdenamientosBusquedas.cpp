/*Menu|
|-Cargar
|
|-Busqueda|
|         |Secuencial
|         |Binaria iterativo
|         |Binaria recursivo
|         |Regresar
|
|-Ordenamiento|
|             |Burbuja
|             |Insercion
|             |Shell
|             |Quick
|             |Merge
|             |Cubetas
|             |Resumen
|             |Regresar
|
|-Salir
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Arreglo{
	int *elementos;
	//Metodos
	public:
	    int tamanio;
		Arreglo(int);
		void operator = (Arreglo);
		void cargar();
		int burbuja();
		int insercion();
        int shell();
        int quicksort(int[],int,int);
		int mergesort();
		int cubetas();
		void mostrar();
		int busquedaSecuencial(int,int&);
		int busquedaBIterativa(int,int&);
		int busquedaBRecursiva(int,int,int,int&);
};
Arreglo::Arreglo(int tamanio){
	this->tamanio = tamanio;
	elementos = new int [tamanio];
}
void Arreglo::operator = (Arreglo A){
	this->tamanio=A.tamanio;
	for(int k=0;k<tamanio;k++){
		this->elementos[k]=A.elementos[k];
	}
}
void Arreglo::cargar(){
	if(tamanio>20){
        srand(time(NULL));
		for(int k=0;k<tamanio;k++){
            elementos[k]=rand()%100 + 1;
        }
    }else{
        for(int k=0;k<tamanio;k++){
            cout<<"Ingresando el elemento "<<k+1<<": "<<endl;
            cin>>elementos[k];
        }
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
	int j=1,k,aux,op=0;
	while(j<tamanio){
		k=j-1;
		aux = elementos[j];
		op++;
		while(k>=0&&elementos[k]>aux){
			op++;
			elementos[k+1]=elementos[k];
			k--;
		}
		elementos[k+1]=aux;
		j++;
	}
	return op;
}
int Arreglo::shell(){
    int temp,op=0;
    for(int i=tamanio/2;i>0;i/=2){
        for(int j=i;j<tamanio;j++){
            for(int k=j-i;k>=0;k-=i){
                op++;
                if(elementos[k+i]<elementos[k]){
                    temp = elementos[k];
                    elementos[k]=elementos[k+i];
                    elementos[k+i]=temp;
                }
            }
        }
    }
    return op;
}
int Arreglo::quicksort(int A[], int izq, int der){
    int auxiliar, mitad, i, j,op=0;
    mitad =A[(izq+der)/2];
    do{
        while((A[i]<mitad) && (j<=der)){
            i++;
        }
        while((mitad<A[j]) && (j>izq)){
            j--;
        }
        op++;
        if(i<=j){
            auxiliar = A[i];
            A[i] = A[j];
            A[j] = auxiliar;
            i++;
            j--;
        }
    }while(i<=j);
    if(izq<j){
        quicksort(A,izq,j);
    }
    if(i<=der){
        quicksort(A,i,der);
    }
    return op;
}
int Arreglo::busquedaSecuencial(int elemento, int &op){
	int k=0;
	op=0;
	while(k<tamanio){
		op++;
		if(elementos[k]==elemento){
			return k;
		}
		k++;
	}
	return -1;
}
int Arreglo::busquedaBIterativa(int elemento, int &op){
	int ini=0, fin=tamanio-1,mitad;
	while(ini<=fin){
		mitad=(ini+fin)/2;
		op++;
		if(elementos[mitad]==elemento){
			return mitad;
		}
		if(elementos[mitad]>elemento){
			fin = mitad -1;
		}else{
			ini = mitad+1;
		}
	}
	return -1;
}
int Arreglo::busquedaBRecursiva(int elemento, int inicio, int final, int &op){
	int ini=inicio, fin=final,mitad;
	mitad=(ini+fin)/2;
	op++;
	if(elementos[mitad]==elemento){
		return mitad;
	}else if(elementos[mitad]>elemento){
		fin = mitad -1;
		busquedaBRecursiva(elemento, ini, fin, op);
	}else if(elementos[mitad]<elemento){
		ini = mitad+1;
		busquedaBRecursiva(elemento, ini, fin, op);
	}else{
		return -1;
	}
}
void Arreglo::mostrar(){
	for(int k=0;k<tamanio;k++){
		cout<<elementos[k]<<" ";
	}
	cout<<"\n";
}
char menuPrincipal(){
    char opcion;
    cout<<"\nMENU\n";
	cout<<"(C)argar\n";
	cout<<"(B)usqueda\n";
	cout<<"(O)rdenamiento\n";
    cout<<"(S)alir\n";
	cin>>opcion;
    return opcion;
}
char menuBusqueda(){
    char opcion;
    cout<<"\nMENU BUSQUEDA\n";
	cout<<"(S)ecuencial\n";
	cout<<"Binaria (I)terativa\n";
	cout<<"(B)inaria recursiva\n";
    cout<<"(R)egresar\n";
	cin>>opcion;
    return opcion;
}
char menuOrdenamiento(){
    char opcion;
    cout<<"\nMENU ORDENAMIENTO\n";
	cout<<"(B)urbuja\n";
	cout<<"(I)nsercion\n";
	cout<<"(S)hell\n";
	cout<<"(Q)uicksort\n";
	cout<<"(M)ergesort\n";
	cout<<"(C)ubetas\n";
    cout<<"(R)egresar\n";
	cin>>opcion;
    return opcion;
}
int main(){
	char opcion,opcionB,opcionO;
	int n,elementoB,op=0,posicion;
	cout<<"Ingresar tamaño del arreglo: ";
    cin>>n;
    Arreglo A(n), B(n);
	do{
        opcion=menuPrincipal();
        switch(opcion){
        case'c':
        case'C':
            if(A.tamanio>20){
                cout<<"El arreglo se cargara solo con numeros aleatorios\n";
            }
            A.cargar();
            break;
        case'b':
        case'B':
            do{
                opcionB=menuBusqueda();
                switch(opcionB){
                case's':
                case'S':
					cout<<"Ingrese el elemento a buscar: ";
					cin>>elementoB;
					posicion = A.busquedaSecuencial(elementoB,op);
					if(posicion!=-1){
						cout<<"\nNumero se encuentra en el arreglo en la posicion: "<<posicion<<".\n";
					}else{
						cout<<"\nNumero no se encuentra en el arreglo.\n";
					}
					cout<<"Realizo: "<<op<<" operaciones.\n";
                    break;
                case'i':
                case'I':
                	cout<<"Ingrese el elemento a buscar: ";
					cin>>elementoB;
					posicion = B.busquedaBIterativa(elementoB,op);
					if(posicion!=-1){
						cout<<"\nNumero se encuentra en el arreglo en la posicion: "<<posicion<<".\n";
					}else{
						cout<<"\nNumero no se encuentra en el arreglo.\n";
					}
					cout<<"Realizo: "<<op<<" operaciones.\n";
                    break;
                case'b':
                case'B':
                	cout<<"Ingrese el elemento a buscar: ";
					cin>>elementoB;
					posicion = B.busquedaBRecursiva(elementoB,0,B.tamanio-1,op);
					if(posicion!=-1){
						cout<<"\nNumero se encuentra en el arreglo en la posicion: "<<posicion<<".\n";
					}else{
						cout<<"\nNumero no se encuentra en el arreglo.\n";
					}
					cout<<"Realizo: "<<op<<" operaciones.\n";
                    break;
                    break;
                case'r':
                case'R':
                    break;
                default:
                    cout<<"Opcion invalida\n";
                    break;
                }
            }while(opcionB!='R'&&opcionB!='r');
            break;
        case'o':
        case'O':
            do{
                opcionO=menuOrdenamiento();
                switch(opcionO){
                case'b':
                case'B':
                    B=A;
                    cout<<"Burbuja"<<endl;
                    cout<<"Numero de operaciones: "<<B.burbuja()<<endl;
                    B.mostrar();
                    break;
                case'i':
                case'I':
                    B=A;
                    cout<<"Insercion"<<endl;
                    cout<<"Numero de operaciones: "<<B.insercion()<<endl;
                    B.mostrar();
                    break;
                case's':
                case'S':
                    B=A;
                    cout<<"Shell"<<endl;
                    cout<<"Numero de operaciones: "<<B.shell()<<endl;
                    B.mostrar();
                    break;
                case'q':
                case'Q':
                    B=A;
                    cout<<"Quicksort"<<endl;
                    //cout<<"Numero de operaciones: "<<B.quicksort()<<endl;
                    B.mostrar();
                    break;
                case'm':
                case'M':
                    B=A;
                    cout<<"Mergesort"<<endl;
                    cout<<"Numero de operaciones: "<<B.shell()<<endl;
                    B.mostrar();
                    break;
                case'c':
                case'C':
                    B=A;
                    cout<<"Cubetas"<<endl;
                    cout<<"Numero de operaciones: "<<B.shell()<<endl;
                    B.mostrar();
                    break;
                case'r':
                case'R':
                    break;
                default:
                    cout<<"Opcion invalida\n";
                    break;
                }
            }while(opcionO!='R'&&opcionO!='r');
            break;
        case's':
        case'S':
            break;
        default:
            cout<<"Opcion invalida\n";
            break;
        }
	}while(opcion!='S'&&opcion!='s');
}
