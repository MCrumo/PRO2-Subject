#include "Cjt_sessions.hh"

const char *e1 = "La sessio ja existeix";
const char *e2 = "La sessio no existeix";

Cjt_sessions::Cjt_sessions() {}

void Cjt_sessions::afegir_sessio(Sessio& s) {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s.nom_sessio());
    if (it != llista_sessions.end()) throw ExcepcioEvaluator(e1);
    else {
        llista_sessions.insert(make_pair(s.nom_sessio(), s));
        cout << llista_sessions.size() << endl;
    }
}
/*
bool Cjt_sessions::problemes_repetits() {
    
}
*/
Sessio Cjt_sessions::buscar_sessio(string nom) {
    map<string, Sessio>::const_iterator it = llista_sessions.find(nom);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator(e2);
    else {
        return it->second;
    }
}

void Cjt_sessions::llegir_sessions() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Sessio s;
        s.llegir_sessio();
        llista_sessions.insert(make_pair(s.nom_sessio(), s));
    }
}

void Cjt_sessions::llistar_sessions() const {
    for (map<string, Sessio>::const_iterator it = llista_sessions.begin(); it != llista_sessions.end(); ++it) {
        it->second.escriure_sessio();
    }
}
