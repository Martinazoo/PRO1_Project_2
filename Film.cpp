#include "Film.hpp"

// IMPLMENTACIÓ DE LA CLASSE FILM
// (implementació del codi de tots els mètodes especificats en el fitxer Film.hpp)


Film::Film()
/* Pre: cert */
/* Post: el resultat es un Film buit */
{
    name = "";
    gender = "";
}

Film::Film(string name, string gender)
/* Pre: cert */
/* Post: el resultat es un film amb un nom i genere determinats */
{
    this->name = name;
    this->gender = gender;
}

Film::Film(const Film &f)
/* Pre: cert */
/* Post: el resultat es un Film amb les caracteristiques de f*/
{
    name = f.name;
    gender = f.gender;
    numVal = f.numVal;
    valoracio = f.valoracio;
}

Film& Film::operator=(const Film &f)
/* Pre: cert */
/* Post: el resultat es un Film amb les caracteristiques de f*/
{
    this->name = f.name;
    this->gender = f.gender;
    this->numVal = f.numVal;
    this->valoracio = f.valoracio;
    return *this;
}

Film::~Film()
/* Post: esborra automaticament els objectes locals en sortir
  d'un ambit de visibilitat */
{
}

void Film::changeName(string &name)
/* Pre: cert */
/* Post: canvia el this-> name del film per el name introduit */
{
    this->name = name;
}

void Film::changeGender(string &gender)
/* Pre: cert */
/* Post: canvia el this-> gender del film pel gender introduit */
{
    this->gender = gender;
}

void Film::changeVal(const float &valoracio)
/* Pre: cert */
/* Post: canvia la valoracio del film per la valoracio mitjana d'aquest */  
{
    if (valoracio >= 1 or valoracio <= 5){
        this->valoracio = ((this->valoracio * numVal)+ valoracio) / (numVal+1);
    }
    else {
        cout << "Error: " << valoracio << "nombre de punts no vàlid, no s'ha afegit" << endl ;
    }
    ++numVal;
}

string Film::getName()
/* Pre: cert */
/* Post: el resultat es el nom del film */
{
    return name;
}

string Film::getGender()
/* Pre: cert */
/* Post: el resultat es el genere del film */
{
    return gender;
}
float Film::getVal()
/* Pre: cert */
/* Post: el resultat es la valoracio del film */
{
    return valoracio;
}
int Film::getNumVal()
/* Pre: cert */
/* Post: el resultat es el nombre de valoracions del film*/
{
    return numVal;
}

istream& operator>>(istream& is, Film& film)
/* Pre: cert */
/* Post: el film (film) passa a tenir els atributs llegits del canal
  estandard d'entrada */
{
    is >> film.name >> film.gender;
    return is;

}

ostream& operator<<(ostream& os, Film& film)
/* Pre: necessitem tenir llegit un film (film) amb els seus 
  atributs corresponents */
/* Post: s'han escrit els atributs del film (film) al canal 
  estandard de sortida */
   
{
    os << '(' <<film.name << ", " << film.gender << ", " << film.valoracio << ", " << film.numVal << ')' << endl;
    return os;
}