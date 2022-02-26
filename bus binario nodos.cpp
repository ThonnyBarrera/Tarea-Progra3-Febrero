#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

//prototipos
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;
int main(){
	menu();
	
	
	getch();
	return 0;
}

void menu(){
	int dato,opcion,contador=0;
	do{
		cout<<"\tMENU"<<endl;
		cout<<"1. Insertar un nuevo Nodo"<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento"<<endl;
		cout<<"4. Eliminar un nodo del arbol"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"opcion:";
		cin>>opcion;
		
		switch(opcion){
			case 1: 
			     cout<<"\nDigite un numero: ";
			     cin>>dato;
			     insertarNodo(arbol,dato,NULL);
			     cout<<"\n";
			     system("pause");
			     break;
			     
			case 2: 
			     cout<<"\nMostrando el arbol completo:\n\n";
			     mostrarArbol(arbol,contador);
			    cout<<"\n";
			     system("pause");
			     break;
			
			case 3: 
			     cout<<"\nDigite el elemento a buscar: ";
			     cin>>dato;
			     if(busqueda(arbol,dato)== true){
			     	cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";
				 }
				 else{
				 	cout<<"\nElemento no encontrado\n";
				 }
			     cout<<"\n";
			     system("pause");
			     break;
			
			case 4: cout<<"\nDigite el numero a eliminar: ";
			         cin>>dato;
				     eliminar(arbol,dato);
				     cout<<"\n";
				     system("pause");
				      break;
		}
		system("cls");
	}while(opcion !=5);
}
//Funcion para crear un nuevo Nodo
Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo= new Nodo();
	
	nuevo_nodo-> dato= n;
	nuevo_nodo-> der= NULL;
	nuevo_nodo-> izq= NULL;
	nuevo_nodo-> padre;
	
	return nuevo_nodo;
}

//Funcion para insertar nodos en el arbol
void insertarNodo(Nodo *&arbol,int n, Nodo *padre){
	if(arbol==NULL){
		Nodo *nuevo_nodo = crearNodo (n,padre);
		arbol = nuevo_nodo;
	}
      else{
      	int valorRaiz = arbol->dato;
      	if(n < valorRaiz){
      		insertarNodo(arbol->izq,n,arbol);
		  }
	 
		else{
			insertarNodo(arbol->der,n,arbol);
		}
	   }
	}

//Fundion para mostrar el arbol completo 
void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0; i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

//funsion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true; 
	}
	else if(n < arbol->dato){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
	}
}

//Eliminar un nodo en el arbol
void eliminar(Nodo *arbol,int n){
	if(arbol == NULL){
		return;
	}
	else if(n< arbol->dato){
		eliminar(arbol->izq,n);
	}
	else if(n> arbol->dato){
		eliminar(arbol->der,n);
		}
	else{
		eliminarNodo(arbol);
	}	
		
}

//funcion para determinar el nodo mas izq posible
Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
	
}

//funsion para reemplazar dos nodos
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		//arbol->padre hay que asignarle su nuevo hijo
	if(arbol->dato == arbol->padre->izq->dato){
		arbol->padre->izq=nuevoNodo;
	   }
	   else if(arbol->dato == arbol->padre->der->dato){
	   	arbol->padre->der=nuevoNodo;
	   }	
	}
	if(nuevoNodo){
		//procedemos a asignarle su nuevo padre
		nuevoNodo->padre= arbol->padre;
	}
}

//funcion para destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	
	delete nodo;
}



//funcion eliminar el nodo encontrado 
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor=minimo(nodoEliminar->der);
		nodoEliminar->dato=menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{//no tiene hijos
	     reemplazar(nodoEliminar,NULL);
	     destruirNodo(nodoEliminar);
		
	}
}
