#include "Usuari.hpp"
#include "Film.hpp"

// IMPLMENTACIÓ DE LA CLASSE USUARI
// (implementació del codi de tots els mètodes especificats en el fitxer Usuari.hpp)



Usuari::Usuari()
/* Pre: cert */  
/* Post: el resultat és un Usuari buit*/
{
  userName = "";
  ID = -1;
}

Usuari::Usuari(int ID, string userName)
/* Pre: cert */
/* Post: el resultat es un usuari amb la seva ID i el seu nom
  d'usuari */
{
  this->userName = userName;
  this->ID = ID;
}

Usuari::Usuari(const Usuari &u)
/* Pre: cert */
/* Post: el resultat es un usuari amb els parametres del usuari u*/
{
  userName = u.userName;
  numVal = u.numVal;
  ID = u.ID;

}
Usuari& Usuari::operator=(const Usuari &u) 
/* Pre: cert */
/* Post: el resultat es un usuari amb els parametres del usuari u*/
{
  this->userName = u.userName;
  this->numVal = u.numVal;
  this->ID = u.ID;
  return *this;
}

Usuari::~Usuari()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
  de visibilitat */
{
};


void Usuari::setID(int id)
/* Pre: cert */
/* Post: canvia el valor de la ID*/
{
    ID = id;    
}


void Usuari::addVal()
/* Pre: cert */
/* Post: el resultat és el nombre de valoracions de l'usuari 
  més 1 */
{
    numVal++;
}

int Usuari::getID()
/* Pre: cert */
/* Post: el resultat és la ID del Usuari*/
{
    return ID;    
}
   
string Usuari::getName()
/* Pre: cert */
/* Post: el resultat es el nom del usuari (username)*/
{
    return userName;
}

int Usuari::getNumVal()
/* Pre: cert */
/* Post: el resultat es el nombre de valoracions que ha fet
  l'usuari */
{
    return numVal;
}


istream& operator>> (istream &is, Usuari &u)
/* Pre: cert */
/* Post: l'usuari u passa a tenir els atriubuts que s'han
  llegit en el canal d'entrada*/
{
    is >> u.userName;
    return is;
}

ostream& operator<< (ostream &os, Usuari &u)
/* Pre: necessitem haver llegit un usuari u amb els seus atributs
  corresponents */
/* Post: s'han escrit els atributs del usuari u al canal estandard de 
  sortida */
{
    os << u.ID << " | " << u.userName << " | " << u.numVal << endl;
    return os;
}

