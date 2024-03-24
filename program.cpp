#include "Film.hpp"
#include "Usuari.hpp"
#include "Plataforma.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/* Pre: un enter n */
/* Post: Configurar el output stream per a que els floats els imprimeixi amb n decimals */
void fixDecimals(int n){ 
	cout << fixed;
	cout << setprecision(n);
}

int main() {
	
	//Llegir les dades de la plataforma (nom, films i usuaris)
	Plataforma plataforma;
	cin >> plataforma;
	int n; 
	cin >> n; 

	Film ifilm;
	for (unsigned int i = 0; i < n; i++){
		cin >> ifilm;
		plataforma.addFilm(ifilm);
	}

	cin >> n;
	Usuari iusuari;
	for (unsigned int i = 0; i < n; i++){
		cin >> iusuari;
		plataforma.addUsuari(iusuari);
	}

	//Bucle principal del programa
	string opt;
	cin >> opt;

	while (opt != "acabar"){	

		if(opt == "mostrarFilms"){
			fixDecimals(1);
			plataforma.mostrarFilms();

		} else if (opt == "mostrarUsuaris"){
			plataforma.mostrarUsuaris();

		} else if (opt == "enregistrarValoracio") {
			string usuari, film; 
			float val; 
			cin >> usuari >> film >> val;
			fixDecimals(0);
			plataforma.novaValoracio(usuari, film, val);
			 
		} else if (opt == "recomanarMillorFilm"){
			cout << "Film recomanat a " << plataforma.getName() << ":" <<endl;
			fixDecimals(1);
			plataforma.millorsFilms(1);
				
		} else if (opt == "mostrarMillorsFilms"){
			int n;
			cin >> n;
			cout << "Films amb millors valoracions a " << plataforma.getName() << " (" << n << " millors):"<< endl;
			fixDecimals(1);
			plataforma.millorsFilms(n);

		} else if (opt == "mostrarFilmsGenere"){
			string s;
			cin >> s;
			fixDecimals(1);
			cout << "Films del gènere " << s << " a " << plataforma.getName() << ":" << endl;
			plataforma.buscarGenere(s);

		} else {
			cout << " Error: Opció no vàlida" << endl;
		}

		cin >> opt;		
	}

	return -1;	
}
