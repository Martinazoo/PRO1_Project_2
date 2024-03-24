#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Film.hpp"
#include "Usuari.hpp"
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Plataforma {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una plataforma de registre de valoracions
// de films que fan els usuaris. Una plataforma té un nom, està formada per un conjunt
// d'usuaris i un conjunt de films.
public:
  	
// ESPECIFICACIÓ DE LA CLASSE PLATAFORMA
// (especificació Pre/Post de tots els mètodes)
  	
	
// Constructors
Plataforma();
/* Pre: cert */
/* Post: retorna la classe plataforma amb els seus atributs buits */
	
// Destructor
~Plataforma();
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
  de visibilitat */  

// Modificadors
void addFilm(Film film);
/* Pre: cert */
/* Post: el resultat es un vector de film amb un film més */
void addUsuari(Usuari usuari);
/* Pre: cert */
/* Post: el resultat es un vector de usuaris amb un usuari més */
void novaValoracio(const string &usuari, const string &film, const float &val);
/* Pre: necessitem un usuari, un film i una valoració */
/* Post: el resultat es un usuari i un film amb una valoracio més */
void millorsFilms(int n);
/* Pre: un nombre enter positiu n */
/* Post: escriu per pantalla els n primers millors films ordenats
    per la valoració, en cas d'empat seran ordenats alfabèticament */
       
// Consultors
int buscarUsuari(const string &username);
/* Pre: un usuari username */
/* Post: retorna la posicio del vector en la que es troba l'usuari */
int buscarFilm(const string &film);
/* Pre: un film film */
/* Post: retorna la posicio del vector en la que es troba el film */
void buscarGenere(string &gender);
/* Pre: un gènere gender */
/* Post: el resultat es una llista de films amb gènere gender */
string getName();
/* Pre: cert */
/* Post: el name de la plataforma */
vector <Film> getFilms();
/* Pre: cert */
/* Posy: retorna el vector films de Film */

// Lectura i escriptura
void mostrarFilms();
/* Pre: cert */
/* Post: el resultat es una llista de films */
void mostrarUsuaris();
/* Pre: cert */
/* Post: el resultat es una llista d'usuaris */
friend istream& operator>>(istream &is, Plataforma &p);
/* Pre: cert */
/* Post: la plataforma passa a tenir els atributs que s'han llegit
    en el canal d'entrada (name)*/
   
private:
// Implementació de la classe Plataforma 
// (definició del tipus i nom de cada atribut)
  string name;
  vector<Usuari> usuaris;
  vector<Film> films;
};
#endif
