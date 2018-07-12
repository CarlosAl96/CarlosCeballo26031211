#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <fstream>

using namespace std;

class Principal{
	
	private:
		
		fstream archivo;
		char *charvec;
		unsigned int *intvec;
		unsigned int *_intvec;
		int tam;
		int tam2;
		
	public:
		
		Principal();
		~Principal();
		
		void cargar_charvec(); /* Metodo que carga charvec leyendo los caracteres de _text.txt */
		void cargar_intvec(); /* Metodo que carga intvec tomando cuatro caracteres de charvec por cada posision y guarda en _num.txt cada valor */
		void _cargar_intvec(); /* Metodo que carga _intvec leyendo de _num.txt y haciendo la conversion a enteros */
		void decod(); /* Metodo que parte de los enteros guardados en _intvec para mostrar el texto original */
};

#endif
