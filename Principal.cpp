#include <iostream>
#include <fstream>

#include "Principal.h"

using namespace std;

Principal::Principal(){
}

Principal::~Principal(){
}

/*____________________________________________________________________________________________________________*/

void Principal::cargar_charvec(){
	
	int i = 0;
	int saltos = 0;
	char c;
	
	if(!archivo.is_open())
		archivo.open("_text.txt", ios::in);
		
	while(!archivo.eof()){
		
		archivo.get(c);
		
		if(c == '\n')
			saltos++;
	}
		
	archivo.close();
	
	if(!archivo.is_open())
		archivo.open("_text.txt", ios::in);
		
	archivo.seekg(0, ios::end);
	tam = archivo.tellg();
	tam -= saltos;
	archivo.seekg(0, ios::beg);
	
	charvec = new char[tam];
	
	while(!archivo.eof()){
		
		archivo.get(charvec[i]);
		i++;
	}
	
	archivo.close();
	
	for(int i=0; i<tam+1; i++)
		cout << charvec[i];
		
	cout << endl;
}

/*___________________________________________________________________________________________________________-*/

void Principal::cargar_intvec(){
	
	float y;
	int num = 0;
	int it = 0;
	int icv = 0;
	
	tam2= tam/4;
	y = (float)tam/4;
	
	if((tam2-y) != 0)
		tam2 += 1;
		
	intvec = new int[tam2];
	
	if(!archivo.is_open())
		archivo.open("_num.txt", ios::out);
		
	for(int i=0; i<tam2; i++){
		
		while(it<4 && charvec[icv] != '\0'){
			
			if(it==0)
				num = charvec[icv];
			if(it==1)
				num = (charvec[icv]*256)|num;
			if(it==2)
				num = (charvec[icv]*65536)|num;
			if(it==3)
				num = (charvec[icv]*16777216)|num;
				
			it++;
			icv++;	
		}
		
		intvec[i] = num;
		
		if(charvec[icv] != '\0')
			archivo << num << endl;	
		else
			archivo << num;
			
		num = 0;
		it = 0;
		cout << intvec[i] << endl;
	}
	
	archivo.close();
}

/*______________________________________________________________________________________________________________*/

void Principal::_cargar_intvec(){
	
	char num_cad;
	int i = 0;
	int saltos = 0;
	bool bandera = false;
	
	if(!archivo.is_open())
		archivo.open("_num.txt", ios::in);
	
	while(!archivo.eof()){
		
		archivo.get(num_cad);
		
		if(num_cad == '\n')
			saltos++;
	}
	
	archivo.close();
	
	_intvec = new int[saltos+1];
	
	if(!archivo.is_open())
		archivo.open("_num.txt", ios::in);

	while(!archivo.eof()){
		
		archivo.get(num_cad);
			
		if(num_cad != '\n' && num_cad != ' '){
		
			if(bandera == false){
				
				_intvec[i] = num_cad - 48;
				bandera = true;	
			}
			else{
				_intvec[i] = _intvec[i]*10+(num_cad-48);
			}
		}
		else{
			
			bandera = false;
			i++;
		}
		
		cin.sync();
		num_cad = ' ';	
	}
	
	cout << endl;
	
	for(int i=0; i<saltos+1; i++){
		
		cout << _intvec[i] << "\n";
	}
	
	archivo.close();
}

/*____________________________________________________________________________________________________________*/

void Principal::decod(){
	
	int _it = 0;
	int _icv = 0;
	char caracter;
	
	cout << endl;
	
	for(int i=0; i<tam2; i++){
		
		while(_it<4){
			
			if(_it==0)
				caracter = (char)(_intvec[i]&255); 
			if(_it==1)
				caracter = (char)((_intvec[i]>>8)&255);
			if(_it==2)
				caracter = (char)((_intvec[i]>>16)&255);
			if(_it==3)
				caracter = (char)((_intvec[i]>>24)&255);
				
			cout << caracter;
			_it++;
		}
		
		_it = 0;
	}
	
	cout << endl;
}
