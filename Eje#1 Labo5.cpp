#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *izq;
	nodo *der;
};

nodo *crearnodo(int n);
void Inser(nodo *&arbol, int n);
void menu();
void MostrArb(nodo *arbol, int contador);
int Contlevels(nodo *arbol);
int Conttnods(nodo *arbol);
int sumaNodos(nodo *arbol);

nodo *arbol=NULL;
int main(void){

	menu();
	return 0;
}

nodo *crearnodo(int n){
	nodo *nuevo_nodo=new nodo();

	nuevo_nodo->dato=n;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->der=NULL;

	return nuevo_nodo;
}
void Inser(nodo *&arbol, int n){
	if(arbol==NULL){
		nodo *nuevo_nodo = crearnodo(n);
		arbol = nuevo_nodo;
	}
	else{

		int valorRaiz = arbol->dato;
		if(n<valorRaiz){
			Inser(arbol->izq, n);

		}
		else{
			Inser(arbol->der, n);
		}
	}
}
void menu(){
	int dato, opcion, contador=0;

	do{
		cout<<"\t.:MENU:. "<<endl;
		cout<<"1. Insert un nuevo nodo."<<endl;
		cout<<"2. Mostrar el arbol completo."<<endl;
		cout<<"3. Mostrar la cantidad de niveles."<<endl;
		cout<<"4. Mostrar la cantidad de nodos."<<endl;
		cout<<"5. Efectuar la sumatoria de los datos contenidos en todos los nodos."<<endl;
		cout<<"0. Salir... Su eleccion: ";cin>>opcion;

		switch(opcion){
			case 1:
				cout<<"\nDigite un numero: ";
				cin>>dato;
				Inser(arbol, dato);
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"\nMostrando el arbol completo \n\n";
				MostrArb(arbol, contador);
				cout<<endl;
				system("pause");
				break;
			case 3:
			    cout<<"\nMostrando la cantidad de niveles (sin contar la raiz): "<< Contlevels(arbol)<<endl;
			    system("pause");
			    break;
			case 4:
				cout<<"\nMostrando la cantidad de nodos en el arbol: "<< Conttnods(arbol)<<endl;
				system("pause");
			    break;
			case 5:
				cout<<"\nMostrando sumatoria: "<< sumaNodos(arbol)<<endl;
				system("pause");
			    break;
		}
		system("cls");
	}while(opcion != 0);

}

int Contlevels(nodo *arbol){
	if(arbol!=NULL){
		int izq = Contlevels(arbol->izq)+1;
		int der = Contlevels(arbol->der)+1;
		if(izq>der){
			return izq;
		}else{
			return der;
		}
	}
	return -1;

}

int Conttnods(nodo *arbol){
	if(arbol==NULL) return 0;

    return 1 + Conttnods(arbol->izq) + Conttnods(arbol->der);
}

int sumaNodos(nodo *arbol){
    if(arbol != NULL){
    	int centro = arbol->dato;
    	int izq=sumaNodos(arbol->izq);
    	int der=sumaNodos(arbol->der);
    	return izq + centro + der;
	}else{
		return 0;
	}
}


void MostrArb(nodo *arbol, int contador){
	if(arbol==NULL){
		return;
	}
	else{
		MostrArb(arbol->der, contador+1);
		for(int i=0;i<contador;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		MostrArb(arbol->izq, contador+1);
	}
}

