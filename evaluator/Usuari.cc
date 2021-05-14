#include "Usuari.hh"


const char *e9 = "error: usuario inscrito en otro curso";
const char *e10 = "error: usuario no inscrito en ningun curso";
const char *e14 = "error: el problema no pertenece a los problemas enviables";
const char *e15 = "error: aquest problema ja ha sigut resolt";

Usuari::Usuari() {
    curs_inscrit = 0;
    env_totals = 0;
}

Usuari::Usuari(string nom) {
    id = nom;
    curs_inscrit = 0;
    env_totals = 0;
}

void Usuari::inscriure_curs(const int& nom_c, const Cjt_cursos& cs, Cjt_sessions& ses) {
    if (curs_inscrit == 0) {
        curs_inscrit = nom_c;
        string nom_sessio, problema;
        for (int i = 0; i < cs.total_sessions(nom_c); ++i) {
            nom_sessio = cs.consul_c_iessim(nom_c, i);
            ses.afegir_enviables(nom_sessio, cjt_resolts, cjt_enviables);
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

void Usuari::inc_p_intentat(string p) {
    llista_intentats.insert(p);
    //llista_enviables[p] += 1;
    cjt_enviables.incrementar_envio(p);
}

void Usuari::envio_correcte(string p) {
    /*llista_resolts[p] = llista_enviables[p];
    llista_enviables.erase(p);*/
    cjt_enviables.intercanviar_problema(p, cjt_resolts);
}

void Usuari::actual_enviables(string p, Cjt_sessions& ses, string s) {
    ses.actual_problemes(s, p, cjt_resolts, cjt_enviables);
}

void Usuari::desinscriure() {
    curs_inscrit = 0;
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

int Usuari::consul_curs() const {
    return curs_inscrit;
}

int Usuari::consultar_inscrit() const {
    if (curs_inscrit == 0) throw ExcepcioEvaluator(e10);
    else return curs_inscrit;
}

int Usuari::consul_enviables() const {
    //return llista_enviables.size();
    return cjt_enviables.problemes_totals();
}

void Usuari::llegir_usuari() {
    cin >> id;
}

void Usuari::llistar_resolts() const {
    /*for (map<string, int>::const_iterator it = llista_resolts.begin(); it != llista_resolts.end(); ++it) {
        cout << it->first << "(" << it->second << ")" << endl;
    } */
    cjt_resolts.enumerar_problemes();
}

void Usuari::llistar_enviables() const {
    /*for (map<string, int>::const_iterator it = llista_enviables.begin(); it != llista_enviables.end(); ++it) {
        cout << it->first << "(" << it->second << ")" << endl;
    }*/
    cjt_enviables.enumerar_problemes();
}
/*
void Usuari::escriure_curs_inscrit() const {
    cout << curs_inscrit << endl;
}*/

void Usuari::escriure_usuari() const {
    cout << id << "(" << env_totals << "," << cjt_resolts.problemes_totals() << "," << llista_intentats.size() << "," << curs_inscrit << ")" << endl;
}








