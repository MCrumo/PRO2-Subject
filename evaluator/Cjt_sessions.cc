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


void Cjt_sessions::afegir_enviables(string nom_s, const Cjt_problemes& llr, Cjt_problemes& lle) {
    llista_sessions[nom_s].afegir_enviables(llr, lle);
}

void Cjt_sessions::actual_problemes(string s, string p, const Cjt_problemes& llr, Cjt_problemes& lle) {
    llista_sessions[s].actual_problemes(p, llr, lle);
}

void Cjt_sessions::existeix_sessio(string s) {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator(e4);
}

string Cjt_sessions::consul_p_iessim(string s, int i) const {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator(e4);
    else return it->second.consul_iessim(i);
}

int Cjt_sessions::total_problemes(string s) const {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator("error: curso mal formado");
    else return it->second.total_problemes();
}

void Cjt_sessions::llegir_sessions() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string nom_s;
        cin >> nom_s;
        Sessio s(nom_s);
        s.llegir_p_sessio();
        llista_sessions.insert(make_pair(nom_s, s));
    }
}

void Cjt_sessions::llistar_sessions() const {
    for (map<string, Sessio>::const_iterator it = llista_sessions.begin(); it != llista_sessions.end(); ++it) {
        it->second.escriure_sessio();
    }
}

void Cjt_sessions::escriure_sessio(string s) const {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s);
    it->second.escriure_sessio();
}














