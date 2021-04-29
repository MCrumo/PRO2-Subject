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
void Usuari::inscriure_curs(const Curs& c, const Cjt_sessions& ses) {
    if (curs_inscrit == 0) {
        curs_inscrit = c.nom_curs();
        pair<string, int> info;
        string nom_sessio, problema;
        for (int i = 0; i < c.total_sessions(); ++i) {
            nom_sessio = c.consul_iessim(i);
            problema = ses.buscar_sessio(nom_sessio).problema_inicial();
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
    int intents = sumPair(llista_enviables) + sum(llista_resolts);
    cout << id << "(" << env_totals << "," << llista_resolts.size() << "," << intents << "," << curs_inscrit << ")" << endl;
}

int Usuari::sum(const map<string, int>& mapa) const {
    int sum = 0;
    for (map<string, int>::const_iterator it = mapa.begin(); it != mapa.end(); ++it) {
        sum += it->second;
    }
    return sum;
}

int Usuari::sumPair(const map<string, pair<string, int> >& mapa2) const {
    int sum = 0;
    for (map<string, pair<string, int> >::const_iterator it = mapa2.begin(); it != mapa2.end(); ++it) {
        sum += it->second.second;
    }
    return sum;
}







