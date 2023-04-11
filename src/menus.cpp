
#include <thread>
#include "Cancion.h"
#include "menus.h"
#include "Lista.h"
#include "NodoCancion.h"
#include <string>
using namespace std;

Cancion *cancion();

Lista *I, *F, *T;
NodoCancion *IStore, *FStore, *TStore;
Lista *reproduccionActual;


void MenuPrincipal(){
	int entrada = 0;
	while(entrada != 5){
	cout<<"--------------------------------"<<endl;
	cout<<"menu principal"<<endl;
	cout<<"1. Operaciones con canciones"<<endl;
	cout<<"2. operaciones de Playlist"<<endl;
	cout<<"3. Reproduccion"<<endl;
	cout<<"4. carga masiva"<<endl;
	cout<<"5. salir"<<endl;

	cin>>entrada;
		switch (entrada) {
			case 1:
				MenuCanciones();
				break;
			case 2:
				MenuPlaylist();
				break;
			case 3:
				MenuReproduccion();
				break;
			case 4:
				Cargamasiva();
				break;

		}
	}

}

void MenuCanciones(){
	int entrada=0;
	while(entrada!=5){

	cout<<"--------------------------------"<<endl;
	cout<<"Operaciones con Canciones"<<endl;
	cout<<"1. insertar"<<endl;
	cout<<"2. eliminar"<<endl;
	cout<<"3. Buscar nombre"<<endl;
	cout<<"4. Listar Cancioes"<<endl;
	cout<<"5. retornar menu principal"<<endl;
	cin>>entrada;

	switch (entrada) {
		case 1:
			insertar();
			break;
		case 2:
			eliminar();
			break;
		case 3:
			buscarNombre();
			break;
		case 4:
			listarCanciones(NULL);
			break;
		}
	}

}

void MenuPlaylist() {
	int entrada=0;
	while(entrada!=7){

	cout<<"--------------------------------"<<endl;
	cout<<"Operaciones de Playlist"<<endl;
	cout<<"1. crear"<<endl;
	cout<<"2. eliminar"<<endl;
	cout<<"3. actualizar"<<endl;
	cout<<"4. listar"<<endl;
	cout<<"5. agreagar canciones"<<endl;
	cout<<"6. eliminar canciones"<<endl;
	cout<<"7. returonar al menu anterior"<<endl;
	cin>>entrada;

	switch (entrada) {
		case 1:
			crear();
			break;
		case 2:
			eliminarLista();
			break;
		case 3:
			actualizar();
			break;
		case 4:
			listar();
			break;
		case 5:
			agregar();
			break;
		case 6:
			eliminarCanciones();
			break;
		}
	}

}

void MenuReproduccion() {
	int entrada=0;
	cout<< "selecciona la playlist a reproducir"<<endl;
	listar();
	int indice=0;
	cin>>indice;
	T=I;
	while(T!=NULL){
		if(T->id == indice){
			reproduccionActual = T;
		}
		T = T->adelante;

	}
	while(entrada!=7){

		if(reproduccionActual !=NULL){
	cout<<"--------------------------------"<<endl;
	cout<<"Reproduccion "<<endl;
	cout<<"1. Normal"<<endl;
	cout<<"2. repetir"<<endl;
	cout<<"3. siguiente"<<endl;
	cout<<"4. anterior"<<endl;
	cout<<"5. lista de reproduccion"<<endl;
	cout<<"6. Agregar cancion a la lista de reproduccion"<<endl;
	cout<<"7. returonar al menu anterior"<<endl;
	cin>>entrada;

	switch (entrada) {
		case 1:
			normal();
			break;
		case 2:
			repetir();
			break;
		case 3:
			siguiente();
			break;
		case 4:
			anterior();
			break;
		case 5:
			listaReproduccion();
			break;
		case 6:
			AgregarCancion();
			break;
		case 7:
			reproduccionActual = NULL;
			break;
		}
		}else{
			cout<<"no hay lista de reproduccion motada"<<endl;
		}
	}
}

void Cargamasiva() {
	cout<<"estas en carga masiva"<<endl;
}


//comienso de menu canciones

void insertar() {

	TStore = new NodoCancion;
	TStore->cancion = cancion();
	TStore->id = 1;
	TStore->anterior = NULL;
	TStore->siguiente = NULL;

	if (IStore == NULL){
		IStore = TStore;
	}else{
		FStore->siguiente=TStore;
		TStore->anterior=FStore;
	}
	FStore = TStore;
	if(FStore->anterior != NULL)FStore->id= FStore->anterior->id++;


}

bool continuar(){
	int entrada = 0;
	cout<<"desea continuar"<<endl;
	cout<<"(1-Si)    (2-No)"<<endl;
	cin>>entrada;
	if(entrada == 1)return true;
	return false;

}
void ElimId(Lista *H){
	int eliminar=0;
	bool fin = false;
	bool comprobar = true;
	cout<<" ingrese el numero de la cancion a eliminar "<<endl;
	cin>>eliminar;
	if(H==NULL){
	TStore = IStore;
	}else{
		TStore= H->I;
	}
	if (TStore == NULL){
		cout<<"no existe canciones"<<endl;
	}else {
		while(TStore != NULL){

			if(TStore->id == eliminar){
				cout<<" cancion a eliminar "<<endl;
				cout<<TStore->id<<" "<<TStore->cancion->nombre<<endl;
				if(H==NULL)comprobar = continuar();
				if(comprobar){
					if(TStore->id!=1){
					TStore->anterior->siguiente = TStore->siguiente;
					TStore->siguiente->anterior = TStore->anterior;
					}else {
						if(H==NULL)IStore = TStore->siguiente;
						else H->I = TStore->siguiente;
					}
					fin = true;
				}

			}
			TStore =TStore->siguiente;
		}
	}
	if(!fin){
		cout<<"no se realizo eliminacion"<<endl;
	}
}

void ElimNombre(){
	string eliminar;
	bool fin = false;
	cout<<" ingrese el nombre de la cancion a eliminar"<<endl;
	getline(cin,eliminar);
	if (IStore == NULL){
		cout<<"no existe canciones en la tienda"<<endl;
	}else {
		TStore = IStore;
		while(TStore != NULL){

			if(TStore->cancion->nombre == eliminar){
				cout<<" cancion a eliminar "<<endl;
				cout<<TStore->id<<" "<<TStore->cancion->nombre<<endl;
				if(continuar()){
					TStore->anterior->siguiente = TStore->siguiente;
					TStore->siguiente->anterior = TStore->anterior;
					fin = true;
				}

			}
			TStore =TStore->siguiente;
		}
	}
	if(!fin){
		cout<<"no se realizo eliminacion"<<endl;
	}
}

void eliminar() {
	int entrada= 0;
	cout<<" 1. eliminar por id"<<endl;
	cout<<" 2. eliminar por nombre"<<endl;
	cin>>entrada;
	switch (entrada) {
		case 1:
			ElimId(NULL);
			break;
		default:
			ElimNombre();
			break;
	}

}

void buscarNombre() {
	string eliminar;
	bool fin = false;
	cout<<"nombre de la busqueda"<<endl;
	cin>>eliminar;
	if (IStore == NULL){
		cout<<"no existe canciones en la tienda"<<endl;
	}else {
		TStore = IStore;
		while(TStore != NULL){

			if(TStore->cancion->nombre == eliminar){
				cout<<" cancion a eliminar "<<endl;
				cout<<TStore->id<<" "<<TStore->cancion->nombre<<endl;
			}
			TStore =TStore->siguiente;
		}
	}
	if(!fin){
		cout<<"no hay coincidencias"<<endl;
	}
}

void listarCanciones(Lista *H) {
	if(H==NULL){
		TStore = IStore;
		cout<<""<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"----------Tienda----------------"<<endl;
		cout<<"--------------------------------"<<endl;
	}
	else {
		TStore = H->I;
		cout<<""<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<"----------"<<H->nombre<<"-------------"<<endl;
	}
	int cont = 1;
	while(TStore !=NULL){
		TStore->id=cont;
		cout<<""<<TStore->id<<" "<<TStore->cancion->nombre<<endl;
		TStore = TStore->siguiente;
		cont ++;
	}

}
//Opciones de playlist
bool aniadirC(){
	int entrada=0;
	cout<<"desea agregar canciones"<<endl;
	cout<<"  (1.Si)     (2.No)    ";
	cin>>entrada;
	if (entrada == 1) {
		return true;
	}return false;

}
Cancion *cancionStore(){
	Cancion *tmp = new Cancion;
	int entrada=0;
	listarCanciones(NULL);//ESTA EN NULL YAMA A TIENDA
		cout<<" ingrese el numero de la cancion a aniadir"<<endl;
		cin>>entrada;
		if (IStore == NULL){
			cout<<"no existe canciones en la tienda"<<endl;
		}else {
			TStore = IStore;
			while(TStore != NULL){

				if(TStore->id == entrada){
					tmp = TStore->cancion;
					return tmp;
				}
				TStore =TStore->siguiente;
			}
		}
	return NULL;
}

void unirCancionLista(Lista *T){
	int i = 0;
	while(i != 5){
		T->T = new NodoCancion;
		T->T->cancion = cancionStore();
		T->T->id = 1;
		T->T->anterior = NULL;
		T->T->siguiente = NULL;
		if (T->I == NULL){
			T->I = T->T;
		}else{
			T->F->siguiente=T->T;
			T->T->anterior=T->F;
		}
		T->F = T->T;
		if(T->F->anterior!=NULL)T->F->id= T->F->anterior->id++;
		i++;

	}
}

void crear() {
	string nombre;
	string descripcion;
	T = new Lista;
	T->id = 1;
	cout<<"ingrese el nombre de la playlist"<<endl;
	cin.get();
	getline(cin,nombre);
	T->nombre= nombre;
	cout<<"ingrese una descripcion"<<endl;
	getline(cin,descripcion);
	T->descripcion= descripcion;
	if (aniadirC()) {
		unirCancionLista(T);
	}

	T->atras = NULL;
	T->adelante = NULL;

	if (I == NULL){
		I = T;
	}else{
		F->adelante=T;
		T->atras=F;
	}
	F = T;
	if(F->atras!= NULL)F->id= F->atras->id++;

}

void eliminarLista() {
	int eliminar=0;
	bool fin = false;
	cout<<" ingrese el numero de la lista a eliminar "<<endl;
	cin>>eliminar;
	if (I == NULL){
		cout<<"no existen listas"<<endl;
	}else {
		T = I;
		while(T != NULL){

			if(T->id == eliminar){
				cout<<" Lista a eliminar "<<endl;
				cout<<T->id<<" "<<T->nombre<<endl;
				cout<<T->descripcion<<endl;
				if(continuar()){
					if(T->id!=1){
					T->atras->adelante = T->adelante;
					T->adelante->atras= T->atras;
					}else {
						I = T->adelante;
					}
					fin = true;
				}

			}
			T =T->adelante;
		}
	}
	if(!fin){
		cout<<"no se realizo eliminacion"<<endl;
	}
}

void actualizar() {
	listar();
	int editar=0;
	cout<<"ingrese el id de la lista que desea editar"<<endl;
	cin >>editar;
	T = I;
	string nombre;
	string descripcion;
	while (T!=NULL){
		if(T->id== editar){
			cin.get();
			cout<<"ingrese el nuevo nombre"<<endl;
			getline(cin,nombre);
			if(nombre!="")T->nombre= nombre;
			cout<<"ingrese la nueva descripcion"<<endl;
			getline(cin,descripcion);
			if(descripcion !="")T->descripcion= descripcion;

		}
		T=T->adelante;
	}
}

void listar() {
	T = I;
	int cont = 1;
		cout<<"  ----------PlayList-------   "<<endl;
	while(T !=NULL){
		T->id=cont;
		cout<<""<<T->id<<" "<<T->nombre<<endl;
		cout<<"  "<<T->descripcion<<endl;
		T = T->adelante;
		cont ++;
	}
}

void agregar() {
	int entrada;
	listar();
	cout<<"a que lista aniadir cacion ";
	cin>>entrada;
	T = I;
	while(T!=NULL){
		if(T->id== entrada){
			unirCancionLista(T);
		}
		T = T->adelante;
	}
}


void eliminarCanciones() {
	int entrada;
	listar();
	T=I;
	cout<<"ingrese la lista a modificar"<<endl;
	cin>>entrada;
		if(entrada == T->id){
		listarCanciones(T);
			cout<<"0 ------salir sin eliminar"<<endl;
		ElimId(T);
		}


}

NodoCancion *CTemp = new NodoCancion;

//opciones de reporductor
void normal() {
	listarCanciones(reproduccionActual);
	reproduccionActual->F->siguiente = NULL;
	reproduccionActual->I->anterior= NULL;
	CTemp = reproduccionActual->I;

	thread hilo{reproducir};
	hilo.detach();

}

void repetir() {
	CTemp = NULL;
	reproduccionActual->F->siguiente = reproduccionActual->I;
	reproduccionActual->I->anterior= reproduccionActual->F;
	CTemp = reproduccionActual->I;
	thread hilo{reproducir};
	hilo.detach();
}

void siguiente(){
	if(CTemp != NULL){
		CTemp = CTemp->siguiente;
	}

}

void anterior() {
	if(CTemp != NULL){
		CTemp = CTemp->anterior;
	}
}

void listaReproduccion() {
	listarCanciones(reproduccionActual);
}

void AgregarCancion() {
}

Cancion *cancion(){
	string nombre;
	string pad;
	Cancion *T = new Cancion;
	cout<<"--------------------------------"<<endl;
	cout<<"inserte nombre cancion"<<endl;
	cin.get();
	getline(cin,nombre);
	T->nombre = nombre;
	cout<<"inserte pad cancion"<<endl;
	getline(cin,pad);
	T->pad = pad;
	return T;
}

void reproducir(){
	cout<<"reproduciendo"<<endl;
	while(CTemp != NULL){

	 CTemp = CTemp->siguiente;

	}


}

