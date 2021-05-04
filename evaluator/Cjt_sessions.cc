#include "Cjt_sessions.hh"

const char *e3 = "error: la sesion ya existe";
const char *e4 = "error: la sesion no existe";
const char *e12 = "error: el problema no pertenece al curso";
const char *e13 = "error: curso mal formado";

Cjt_sessions::Cjt_sessions() {}

void Cjt_sessions::afegir_sessio(Sessio& s) {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s.nom_sessio());
    if (it != llista_sessions.end()) throw ExcepcioEvaluator(e3);
    else {
        llista_sessions.insert(make_pair(s.nom_sessio(), s));
        cout << llista_sessions.size() << endl;
    }
}

void Cjt_sessions::existeix_sessio(string s) {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator(e4);
}
/*
string Cjt_sessions::conte_s_problema(const vector<string>& ses, string nom_p) {
    map<string, Sessio>::iterator it;
    for (int i = 0; i < ses.size(); ++i) {
        it = llista_sessions.find(ses[i]);
        if (it->second.conte_problema(nom_p)) return it->second.nom_sessio();
    }
    throw ExcepcioEvaluator(e12);
}*/
/*
bool Cjt_sessions::problemes_repetits() {
    bool cond = false;
    for (map<string, Sessio>::const_iterator it = llista_sessions.begin(); it != llista_sessions.end() and not cond; ++it) {
        for (map<string, Sessio>::const_iterator it2 = ++it; it2 != llista_sessions.end() and not cond; ++it2) {
            it->second.cmp_problemes(it2->second.consul_problemes(), cond);
        }
    }
    return cond;
}
*/

string Cjt_sessions::existeix_s_problema(const vector<string>& ses, string p){
        for (int i = 0; i < ses.size(); ++i) {
            if (llista_sessions[ses[i]].existeix_problema(p)) return ses[i];
        }
        throw ExcepcioEvaluator(e12);
    }

/*
Sessio Cjt_sessions::buscar_sessio(string nom) const {
    map<string, Sessio>::const_iterator it = llista_sessions.find(nom);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator(e4);
    else {
        return it->second;
    }
}*/

void Cjt_sessions::validar_problemes(const vector<string>& ses) {
    bool cond = false;
    for (int i = 0; i < ses.size() - 1 and not cond; ++i) {
        for (int j = i + 1; j < ses.size() and not cond; ++j) {
            (llista_sessions[ses[i]]).cmp_problemes(llista_sessions[ses[j]].consul_problemes(), cond);
        }
    }
    if (cond) throw ExcepcioEvaluator(e13);
}

string Cjt_sessions::problema_s_inicial(string nom) const {
    map<string, Sessio>::const_iterator it = llista_sessions.find(nom);
    if (it == llista_sessions.end()) throw ExcepcioEvaluator(e4);
    else {
        return it->second.problema_inicial();
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

void Cjt_sessions::escriure_sessio(string s) const {
    map<string, Sessio>::const_iterator it = llista_sessions.find(s);
    it->second.escriure_sessio();
}














