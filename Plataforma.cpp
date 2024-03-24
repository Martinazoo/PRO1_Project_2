#include "Plataforma.hpp"
// IMPLMENTACIÓ DE LA CLASSE PLATAFORMA
// (implementació del codi de tots els mètodes especificats en el fitxer Plataforma.hpp)

Plataforma::Plataforma()
/* Pre: cert */
/* Post: retorna la classe plataforma amb els seus atributs buits */
{
}
Plataforma::~Plataforma()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
  de visibilitat */
{
}

void Plataforma::addFilm(Film film)
/* Pre: cert */
/* Post: el resultat es un vector de film amb un film més */
{
    bool repetit = false;
		int i = 0; 
        while(i < films.size() and not repetit){
			if(film.getName() == films[i].getName()) repetit = true;
            ++i;
		}
    if(!repetit) films.push_back(film);
    else {
        cout << " Error: " << film.getName() << " film ja existent a " << name << ", no s'ha afegit" << endl;
    }
}

void Plataforma::addUsuari(Usuari usuari)
/* Pre: cert */
/* Post: el resultat es un vector de usuaris amb un usuari més */
{
    bool repetit = false;
    int i = 0;
    while(i < usuaris.size() and not repetit) {
        if(usuari.getName() == usuaris[i].getName()) repetit = true;
        ++i;
    }
    if(!repetit){
        usuari.setID(usuaris.size() + 1);
        usuaris.push_back(usuari);
    }
    else{
        cout << " Error: " << usuari.getName() << " usuari ja existent a " << name << ", no s'ha afegit" << endl;
    }
}

void Plataforma::novaValoracio(const string &usuari, const string &film, const float &val)
/* Pre: necessitem un usuari, un film i una valoració */
/* Post: el resultat es un usuari i un film amb una valoracio més */
{
    int useri = buscarUsuari(usuari);
    cout << "Nova valoració:" << endl;
    if (val < 0 or val > 5) cout  << " Error: " << val << " nombre de punts no vàlid, no s'ha afegit" << endl;
    else {
        if (useri < 0){
            cout << " Error: " << usuari << " usuari no enregistrat a " << name << endl;
            return;
        } else {
            usuaris[useri].addVal();
        }
        
        int filmi = buscarFilm(film);
        if(filmi < 0){
            cout << " Error: " << film << " film no enregistrat a " << name << endl;
        }
        if(useri >= 0 and filmi >= 0){

            films[filmi].changeVal(val);
            cout << " " << usuari << ", " << film << ", " << val << endl;
        }
    }
  
}

void Plataforma::millorsFilms(int n)
/* Pre: un nombre enter positiu n */
/* Post: escriu per pantalla els n primers millors films ordenats
    per la valoració, en cas d'empat seran ordenats alfabèticament */
{
    
    vector<Film> fil = films;
    unsigned int fSize = fil.size();

    if (n <= 0 ) cout << " Error: " << n << " valor no vàlid" << endl;
    else if (films.size() == 0) cout << " No hi ha films amb valoracions a " << name << endl;
	else {

        for (unsigned int i = 1; i < fSize; i++)
        {
            int j = i;
            Film x = fil[i];
            bool trobat = false;

            while (j > 0 and !trobat)
            {
                if (x.getVal() > fil[j - 1].getVal()){ //ordenar per valoracio
                    fil[j] = fil[j - 1];
                    --j;
                } else if (fil[j - 1].getVal() == x.getVal()){ //ordenar per numero de valoracions
                    if (fil[j - 1].getNumVal() < x.getNumVal()){
                        fil[j] = fil[j - 1];
                        --j;
                    } else if (fil[j - 1].getNumVal() == x.getNumVal()){ //ordenar per ordre alfabetic
                        if (x.getName() < fil[j - 1].getName()){
                            fil[j] = fil[j - 1];
                            --j;  
                        } else trobat = true;
                    } else trobat = true;
                } else trobat = true;
            }
            fil[j] = x;
        }
        if (n > films.size()) n = films.size();
        for (unsigned int i = 0; i < n; i++)cout << ' ' <<fil[i];

    }

}

int Plataforma::buscarUsuari(const string &username)
/* Pre: un usuari username */
/* Post: retorna la posicio del vector en la que es troba l'usuari */
{
    int i = 0; 
    bool trobat = false; 
    while(not trobat and i < usuaris.size()){
        if(usuaris[i].getName() == username){
            trobat = true;
        }
        else ++i;
    }
    if (!trobat) i = -1;
    return i;
}

int Plataforma::buscarFilm(const string &film)
/* Pre: un film film */
/* Post: retorna la posicio del vector en la que es troba el film */
{
    int i = 0;
    bool trobat = false; 
    while (!trobat and i < films.size()){
        if(films[i].getName() == film){
            trobat = true;
        }
        else ++i;
    }
    if (!trobat) i = -1;
    return i;
}
void Plataforma::buscarGenere(string &gender)
/* Pre: un gènere gender */
/* Post: el resultat es una llista de films amb gènere gender */
{

	if (films.size() == 0) cout << " No hi ha films enregistrats a " << name << endl;
    else{
        bool trobat = false;
        for(unsigned int i = 0; i < films.size(); ++i) {
            if (films[i].getGender() == gender){
                if (trobat == false) trobat = true;
                cout << " " << films[i];
            }  
        }
        if(!trobat) cout << " No hi ha films del gènere " << gender << " a " << name << endl;
    }
}

string Plataforma::getName()
/* Pre: cert */
/* Post: el name de la plataforma */
{
    return name;
}


vector <Film> Plataforma::getFilms()
/* Pre: cert */
/* Posy: retorna el vector films de Film */
{
    return films;
}


void Plataforma::mostrarFilms()
/* Pre: cert */
/* Post: el resultat es una llista de films */
{
    cout << "Films a " << name << " (ordre d'alta):" << endl;
    if(films.size() == 0) cout << " No hi ha films enregistrats a " << name << endl;
	for (size_t i = 0; i < films.size(); i++){
		cout << " " << films[i];
	}
}

void Plataforma::mostrarUsuaris()
/* Pre: cert */
/* Post: el resultat es una llista d'usuaris */
{
    cout <<"Usuaris de " << name << " (ordre d'alta):" << endl;
    if(usuaris.size() == 0) cout << " No hi ha usuaris enregistrats a " << name << endl;
    for (size_t i = 0; i < usuaris.size(); i++){
		cout << " " << usuaris[i];
	}
}

istream& operator>>(istream &is, Plataforma &p)
/* Pre: cert */
/* Post: la plataforma passa a tenir els atributs que s'han llegit
    en el canal d'entrada (name)*/
{
    is >> p.name;
    return is;   
}


