#include "Usuari.hh"


const char *e9 = "error: usuario inscrito en otro curso";

Usuari::Usuari() {
    curs_inscrit = 0;
    env_totals = 0;
}

Usuari::Usuari(string nom) {
    id = nom;
    curs_inscrit = 0;
    env_totals = 0;
}

void Usuari::inscriure_curs(int nom) {
    curs_inscrit = nom;
}

void Usuari::incrementar_totals() {
    env_totals += 1;
}
/*
void Usuari::afegir_correcte(string nom) {
}

void Usuari::actualitzar_curs() {
}

void Usuari::intent_resoldre(string p) {
}
*/
bool Usuari::curs_acabat() const {
    if (curs_inscrit == 0) return true;
    else {
        return false;
        throw ExcepcioEvaluator(e9);
    } 
}

string Usuari::nom_usuari() const {
    return id;
}

int Usuari::consultar_curs() const {
    return curs_inscrit;
}

void Usuari::llegir_usuari() {
    cin >> id;
}
/*
void Usuari::llistar_resolts() const {
    
}

void Usuari::llistar_enviables() const {
    
}
*/
void Usuari::escriure_curs_inscrit() const {
    cout << curs_inscrit << endl;
}

void Usuari::escriure_usuari() const {
    int intents = sum(llista_enviables) + sum(llista_resolts);
    cout << id << "(" << env_totals << "," << llista_resolts.size() << "," << intents << "," << curs_inscrit << ")" << endl;
}

int Usuari::sum(const map<string, int>& mapa) const {
    int sum = 0;
    for (map<string, int>::const_iterator it = mapa.begin(); it != mapa.end(); ++it) {
        sum += it->second;
    }
    return sum;
}








