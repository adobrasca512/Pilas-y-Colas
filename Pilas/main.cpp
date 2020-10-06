#include <iostream>
#include <string>
#include <ctime>
using namespace std;
struct date{
    int dias,mes,anio;
    date *next;
};

//Pendiente de revisión

struct box{
    int exp;
    string nm;
    box *sgt; // el puntero se obtiene por el '*'
};
box *peek = NULL;// Este es el pico de la pila
date *p=NULL;
//Se apunta a null porque la pila sigue vacia y aun asi estando vacia es una pila.
void push(int n,string nombre){
    //Se llama como una clase el puntero para creartelo
    box *nvox =  new box;
    //Se ingresa a la caja con la '->'
    nvox->exp=n,nvox->sgt=peek;
    nvox->nm=nombre;





    //nvox-> entra al campo v y en v mete a x que es el parametro de la funcion.
    //Luego le decimos al nvox que entre al puentero que sera igual a la punta de la pila
    peek=nvox;
}
void fecha(int d, int m, int a){
   // date *daybox= new date;
    date *daybox= new date;
    daybox->dias=d,daybox->next=p;
    daybox->mes=m;
    daybox->anio=a;
    p=daybox;

}
void popfecha(){
    if(p==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
        p=p->next;
}
void pop(){
    if(peek==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
        peek=peek->sgt;
}
void prt(){
    box *aux = peek;


    if(aux==NULL){
        cout<<"Nada que imprimir, Stack vacia\n";
    }

    else{
        while(aux!=NULL){
            cout<<aux->nm<<" -> ";
            cout<<aux->exp<<" -> ";

            aux=aux->sgt;

        }
    }



}
void prtdate(){

    date *aux2=p;

    if(aux2==NULL){
        cout<<"\nCampos de fecha vacios.\n";
    }

    else{
        while(aux2!=NULL){
            cout<<aux2->dias<<" -> ";
            cout<<aux2->mes<<" -> ";
            cout<<aux2->anio<<" -> ";
            aux2=aux2->next;
        }
    }

}

int main(){
    int op;
    string name;
    int dia;
    int mes;
    int anio;
    int ex;
    do{
        cout<<"\n(1) Datos (nombre y expediente)   (2)Fecha de cumpleaños     (3) Print   (4) Salir \n ";
        cout<<"\n Elija opcion: ",cin>>op;
        switch (op){
            case 1:
                cout<<"Ingresa tu nombre:  ",cin>>name;
                cout<<"Ingresa tu expediente:  ",cin>>ex;
                push(ex,name);
                break;
            case 2:
                cout<<"Ingresa el dia  ";cin>>dia;

                cout<<"Ingresa el mes  ";cin>>mes;
                cout<<"Ingresa el año  ";cin>>anio;
                fecha(dia,mes,anio);
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                prt();
                prtdate();
                break;
            case 4:
                cout<<"------Bye--------";

        }
    }while(op!=4);
}

