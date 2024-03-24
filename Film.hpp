#ifndef FILM_H
#define FILM_H
#include <iomanip>    // per indicar nombre de dígits en la part decimal amb setprecision()
#include <iostream>
#include <string>
using namespace std;

class Film {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un film del que s'indiquen 
// el seu títol, gènere, puntuació total obtinguda en les valoracions i
// nombre de valoracions que ha rebut
	
public:
  
// ESPECIFICACIÓ DE LA CLASSE FILM   
// (especificació Pre/Post de tots els mètodes)
  	
	
// Constructors
Film();
/* Pre: cert */
/* Post: el resultat es un Film buit */
Film(string name, string gender);
/* Pre: cert */
/* Post: el resultat es un film amb un nom i genere determinats */
Film(const Film &f);
/* Pre: cert */
/* Post: el resultat es un Film amb les caracteristiques de f*/
Film& operator=(const Film &f);
/* Pre: cert */
/* Post: el resultat es un Film amb les caracteristiques de f*/
   
// Destructor
~Film();
/* Post: esborra automaticament els objectes locals en sortir
  d'un ambit de visibilitat */
             
// Modificadors
void changeName(string &name);
/* Pre: cert */
/* Post: canvia el this-> name del film per el name introduit */
void changeGender(string &gender);
/* Pre: cert */
/* Post: canvia el this-> gender del film pel gender introduit */
void changeVal(const float &valoracio);
/* Pre: cert */
/* Post: canvia la valoracio del film per la valoracio mitjana d'aquest */  
			 
// Consultors
string getName();
/* Pre: cert */
/* Post: el resultat es el nom del film */
string getGender();
/* Pre: cert */
/* Post: el resultat es el genere del film */
float getVal();
/* Pre: cert */
/* Post: el resultat es la valoracio del film */
int getNumVal();
/* Pre: cert */
/* Post: el resultat es el nombre de valoracions del film*/

// Lectura i escriptura
friend istream& operator>>(istream& is, Film& film);
/* Pre: cert */
/* Post: el film (film) passa a tenir els atributs llegits del canal
  estandard d'entrada */
friend ostream& operator<<(ostream& os, Film& film);
/* Pre: necessitem tenir llegit un film (film) amb els seus 
  atributs corresponents */
/* Post: s'han escrit els atributs del film (film) al canal 
  estandard de sortida */
   
private:
  	string name;
    string gender;
    int numVal = 0;
    float valoracio = 0.0;
// Implementació de la classe Film 
// (definició del tipus i nom de cada atribut)
};
#endif
