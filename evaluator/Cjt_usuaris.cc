#include "Cjt_usuaris.hh"

const char *e7 = "error: el usuario ya existe";
const char *e8 = "error: el usuario no existe";

Cjt_usuaris::Cjt_usuaris() { }

void Cjt_usuaris::afegir_usuari(const Usuari& u) {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(u.nom_usuari());
    if (it != llista_usuaris.end()) throw ExcepcioEvaluator(e7);
    else {
        llista_usuaris.insert(make_pair(u.nom_usuari(), u));
        cout << llista_usuaris.size() << endl;
    }
}

int Cjt_usuaris::eliminar_usuari(string nom) {
    map<string, Usuari>::iterator it = llista_usuaris.find(nom);
    if (it == llista_usuaris.end()) throw ExcepcioEvaluator(e8);
    else {
        int c = it->second.consultar_curs();
        llista_usuaris.erase(it);
        cout << llista_usuaris.size() << endl; 
        return c;
    }
}

void Cjt_usuaris::insc_usuari_curs(const string& nom_u, const int& nom_c, const Cjt_cursos& cs, const Cjt_sessions& ses) {
    map<string, Usuari>::iterator it = llista_usuaris.find(nom_u);
    it->second.inscriure_curs(nom_c, cs, ses);
}

void Cjt_usuaris::existeix_usuari(string nom) {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(nom);
    if (it == llista_usuaris.end()) {
        throw ExcepcioEvaluator(e8);
        // return false; ->for bool
    }
    //else return true; ->for bool
}

int Cjt_usuaris::total_usuaris() {
    return llista_usuaris.size();
}
/*
Usuari Cjt_usuaris::buscar_usuari(string nom) {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(nom);
    if (it == llista_usuaris.end()) throw ExcepcioEvaluator(e8);
    else return it->second;
}*/
/*
void Cjt_usuaris::curs_acabat(int c) { //GitHub
    llista_usuaris[c - 1].curs_acabat();
}
*/

void Cjt_usuaris::llegir_usuaris() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Usuari u;
        u.llegir_usuari();
        llista_usuaris.insert(make_pair(u.nom_usuari(), u));
    }
}

void Cjt_usuaris::escriure_curs_inscrit(string u) const {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(u);
    if (it == llista_usuaris.end()) throw ExcepcioEvaluator(e8);
    else it->second.escriure_curs_inscrit();
}

//void Cjt_usuaris::escriure_total_usuaris() const {}

void Cjt_usuaris::llistar_usuaris() const {
    for (map<string, Usuari>::const_iterator it = llista_usuaris.begin(); it != llista_usuaris.end(); ++it) {
        it->second.escriure_usuari();
    }
}

void Cjt_usuaris::llistar_u_resolts(string u) const {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(u);
    it->second.llistar_resolts();
}

void Cjt_usuaris::llistar_u_enviables(string u) const {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(u);
    it->second.consultar_inscrit();
    it->second.llistar_enviables();
}

void Cjt_usuaris::escriure_usuari(string u) const {
    map<string, Usuari>::const_iterator it = llista_usuaris.find(u);
    it->second.escriure_usuari();
}








