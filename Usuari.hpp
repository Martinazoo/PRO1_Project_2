#ifndef USUARI_H
#define USUARI_H
#include "Film.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Usuari {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un usuari enregistrat a la plataforma
// per fer una valoració d'algun film.

public:
  
// ESPECIFICACIÓ DE LA CLASSE USUARI
// (especificació Pre/Post de tots els mètodes)
  	

// Constructors
Usuari();
/* Pre: cert */  
/* Post: el resultat és un Usuari buit*/
Usuari(int ID, string userName);
/* Pre: cert */
/* Post: el resultat es un usuari amb la seva ID i el seu nom
  d'usuari */
Usuari(const Usuari &u);
/* Pre: cert */
/* Post: el resultat es un usuari amb els parametres del usuari u*/
Usuari& operator= (const Usuari &u);
/* Pre: cert */
/* Post: el resultat es un usuari amb els parametres del usuari u*/

// Destructor
~Usuari();
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
  de visibilitat */


// Modificadors
/* void setUsername(); preguntar a marc per esta funcio */
/* Pre: cert */
/* Post: */
void setID(int id);
/* Pre: cert */
/* Post: el resultat es la ID del Usuari */
void addVal();
/* Pre: cert */
/* Post: el resultat és el nombre de valoracions de l'usuari 
  més 1 */


// Consultors
int getID();
/* Pre: cert */
/* Post: el resultat és la ID del Usuari*/
string getName();
/* Pre: cert */
/* Post: el resultat es el nom del usuari (username)*/
int getNumVal();
/* Pre: cert */
/* Post: el resultat es el nombre de valoracions que ha fet
  l'usuari */


// Lectura i escriptura
friend istream& operator>> (istream &is, Usuari &u);
/* Pre: cert */
/* Post: l'usuari u passa a tenir els atriubuts que s'han
  llegit en el canal d'entrada*/
friend ostream& operator<< (ostream &os, Usuari &u);
/* Pre: necessitem haver llegit un usuari u amb els seus atributs
  corresponents */
/* Post: s'han escrit els atributs del usuari u al canal estandard de 
  sortida */


private:
// Implementació de la classe Usuari 
// (definició del tipus i nom de cada atribut)
  string userName;   
  int numVal = 0;
  int ID;
        
};
#endif
