#include "Usuari.hh"


const char *e9 = "error: usuario inscrito en otro curso";
const char *e10 = "error: usuario no inscrito en ningun curso";

Usuari::Usuari() {
    curs_inscrit = 0;
    env_totals = 0;
}

Usuari::Usuari(string nom) {
    id = nom;
    curs_inscrit = 0;
    env_totals = 0;
}
//Cursss!!!
void Usuari::inscriure_curs(const int& nom_c, const Cjt_cursos& cs, const Cjt_sessions& ses) {
    if (curs_inscrit == 0) {
        curs_inscrit = nom_c;
        pair<string, int> info;
        string nom_sessio, problema;
        for (int i = 0; i < cs.total_sessions(nom_c); ++i) {
            nom_sessio = cs.consul_c_iessim(nom_c, i);
            problema = ses.problema_s_inicial(nom_sessio);
            info.first = "";
            info.second = 0;
            llista_enviables.insert(make_pair(problema, info));
        }
    } else throw ExcepcioEvaluator(e9);
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
}*/

void Usuari::inc_p_intentat(string problema) {
    llista_intentats.insert(problema);
}
/*
bool Usuari::curs_acabat() const {
    if (curs_inscrit == 0) return true;
    else {
        return false;
        throw ExcepcioEvaluator(e9);
    } 
}
*/
string Usuari::nom_usuari() const {
    return id;
}

int Usuari::consultar_curs() const {
    return curs_inscrit;
}

int Usuari::consultar_inscrit() const {
    if (curs_inscrit == 0) throw ExcepcioEvaluator(e10);
    else return curs_inscrit;
}

void Usuari::llegir_usuari() {
    cin >> id;
}

void Usuari::llistar_resolts() const {//faltara implementar problemes_resolts
    for (map<string, int>::const_iterator it = llista_resolts.begin(); it != llista_resolts.end(); ++it) {
        cout << it->first << "(" << it->second << ")" << endl;
    } 
}

void Usuari::llistar_enviables() const {
    for (map<string, pair<string, int> >::const_iterator it = llista_enviables.begin(); it != llista_enviables.end(); ++it) {
        cout << it->first << "(" << it->second.second << ")" << endl;
    }
}

void Usuari::escriure_curs_inscrit() const {
    cout << curs_inscrit << endl;
}

void Usuari::escriure_usuari() const {
    cout << id << "(" << env_totals << "," << llista_resolts.size() << "," << llista_intentats.size() << "," << curs_inscrit << ")" << endl;
}








