#include "NodoCancion.h"

#ifndef LISTA_H_
#define LISTA_H_

class Lista {
public:
	Lista();
	virtual ~Lista();
	int id;
	string nombre;
	string descripcion;
	NodoCancion *I, *F, *T;
	Lista *adelante;
	Lista *atras;
};

#endif /* LISTA_H_ */
