#include "Cjt_usuaris.hh"

const char *e7 = "L'usuari ja existeix";
const char *e8 = "L'usuari no existeix";

Cjt_usuaris::Cjt_usuaris() { }

void Cjt_usuaris::afegir_usuari(const Usuari& u) {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(u.nom_usuari());
    if (it != llista_usuaris.end()) throw ExcepcioEvaluator(e7);
    else {
        llista_usuaris.insert(make_pair(u.nom_usuari(), u));
        cout << llista_usuaris.size() << endl;
    }
}

void Cjt_usuaris::eliminar_usuari(string nom) {
    map<string, Usuari>::iterator it = llista_usuaris.find(nom);
    if (it == llista_usuaris.end()) throw ExcepcioEvaluator(e8);
    else {
        llista_usuaris.erase(it);
        cout << llista_usuaris.size() << endl; 
    }
}
/* NO UTILITZADA AL MAIN
bool Cjt_usuaris::existeix_usuari(string nom) {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(nom);
    if (it == llista_usuaris.end()) {
        throw ExcepcioEvaluator(e8);
        return false;
    }
    else return true;
}*/

int Cjt_usuaris::total_usuaris() {
    return llista_usuaris.size();
}

Usuari Cjt_usuaris::buscar_usuari(string nom) {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(nom);
    if (it == llista_usuaris.end()) throw ExcepcioEvaluator(e8);
    else return it->second;
}

void Cjt_usuaris::llegir_usuaris() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Usuari u;
        u.llegir_usuari();
        llista_usuaris.insert(make_pair(u.nom_usuari(), u));
    }
}

//void Cjt_usuaris::escriure_total_usuaris() const {}

void Cjt_usuaris::llistar_usuaris() const {
    for (map<string, Usuari>::const_iterator it = llista_usuaris.begin(); it != llista_usuaris.end(); ++it) {
        it->second.escriure_usuari();
    }
}













