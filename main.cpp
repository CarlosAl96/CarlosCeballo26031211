#include <iostream>

#include "Principal.h"

int main(int argc, char** argv) {

	Principal ob;
	
	ob.cargar_charvec();
	ob.cargar_intvec();
	ob._cargar_intvec();
	ob.decod();
	
	return 0;
}
