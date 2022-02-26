#include <iostream>
#include <stdlib.h>
#include <conio.h>

  using namespace std;   
  

struct nodo{
int info;
nodo *sgt;
};

void agrega(nodo **cab, nodo **fin);
void muestra(nodo *cab);
int main()
{ nodo *c=NULL,*f=NULL;  //puntero de cabecera, y puntero de fin de lista
  int opcion;
   do{
   system("cls");
   cout<<"1) Ingresa un dato (numero entero)."<<endl;
   cout<<"2) Muestra los datos ingresados."<<endl;
  cout<<"ingrese opcion"<<endl;
  cin>>opcion;
  switch(opcion){
  case 0: exit(0);break;
  case 1: agrega(&c, &f);break;
  case 2: muestra(c);break;
  }
  }
  while(opcion!=0);
      system("PAUSE");
      return 0;
}
void agrega(nodo **cab, nodo **fin){
int num;
cout<<"ingrese informacion"<<endl;
cin>>num;
if((*cab)==NULL){
*cab = new nodo;
(*cab)->info =num;
(*cab)->sgt=NULL;
(*fin)=(*cab);
}else{
(*fin)->sgt=new nodo;
(*fin)->sgt->info=num;
(*fin)=(*fin)->sgt;
(*fin)->sgt=NULL;
}
}
void muestra(nodo *cab){
cout<<"elementos en la lista"<<endl;
nodo* temp;
temp=cab;
while ( temp != NULL){
cout<<temp->info<<"   "<<temp->sgt;
temp=temp->sgt;
}
getche();
}
