
#include <string>
#include "Cancion.h"
using namespace std;

#ifndef NODOCANCION_H_
#define NODOCANCION_H_

class NodoCancion {
public:

public:
	NodoCancion();
	virtual ~NodoCancion();
	int id;
	Cancion *cancion;
	NodoCancion *siguiente;
	NodoCancion *anterior;

};

#endif /* NODOCANCION_H_ */
