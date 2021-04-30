#include "Cjt_sessions.hh"

const char *e3 = "error: la sesion ya existe";
const char *e4 = "error: la sesion no existe";

Cjt_sessions::Cjt_sessions() {}

void Cjt_sessions::afegir_sessio(Sessio& s) {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s.nom_sessio());
    if (it != llista_sessions.end()) throw ExcepcioEvaluator(e3);
    else {
        llista_sessions.insert(make_pair(s.nom_sessio(), s));
        cout << llista_sessions.size() << endl;
    }
}

bool Cjt_sessions::problemes_repetits() {
    bool cond = false;
    for (map<string, Sessio>::const_iterator it = llista_sessions.begin(); it != llista_sessions.end() and not cond; ++it) {
        for (map<string, Sessio>::const_iterator it2 = ++it; it2 != llista_sessions.end() and not cond; ++it2) {
            it->second.cmp_problemes(it2->second.consul_problemes(), cond);
        }
    }
    return cond;
}

Sessio Cjt_sessions::buscar_sessio(string nom) const {
    map<string, Sessio>::const_iterator it = llista_sessions.find(nom);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator(e4);
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
