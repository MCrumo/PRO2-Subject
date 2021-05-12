#include "Curs.hh" 

const char *e12 = "error: el problema no pertenece al curso";
const char *e5 = "error: curso mal formado";

Curs::Curs() {
    u_inscrits = 0;
    u_completats = 0;
    llista_sessions = vector<string> (0);
}
/*
Curs::Curs(int nom, const vector<string>& s) {
    u_inscrits = 0;
    u_completats = 0;
    id = nom;
    llista_sessions = s;
}*/

void Curs::incrementar_usuari() {
    u_inscrits += 1;
}

void Curs::incrementar_completats() {
    u_completats += 1;
}

void Curs::decrementar_inscrits() {
    if (u_inscrits - 1 <= 0) u_inscrits = 0;
    else u_inscrits -= 1;
}

string Curs::sessio_problema(string p) {
    map<string, string>::const_iterator it = map_problemes.find(p);
    if (it == map_problemes.end()) throw ExcepcioEvaluator(e12);
    else return it->second;
}

int Curs::nom_curs() const {
    return id;
}

int Curs::usuaris_inscrits() const {
    return u_inscrits;
}

int Curs::usuaris_completats() const {
    return u_completats;
}

int Curs::total_sessions() const {
    return llista_sessions.size();
}

string Curs::consul_iessim(const int& i) const{
    return llista_sessions[i];
}

vector<string> Curs::consul_sessions() const {
    return llista_sessions;
}
/*
void Curs::validar_sessions(const Cjt_sessions& ses) {
    ses.validar_problemes(llista_sessions);
}*/

/*
bool Curs::conte_problema(string p) {
    throw ExcepcioEvaluator("El curs no conte aquest problema")
}

void Curs::nom_sessio(string p) const {
    
}
*/
void Curs::llegir_curs(int nom, const Cjt_sessions& ses) {
    int n;
    id = nom;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string nom_s;
        cin >> nom_s;
        llista_sessions.push_back(nom_s);
        for (int i = 0; i < ses.total_problemes(nom_s); ++i) {
            string p = ses.consul_p_iessim(nom_s, i);
            map<string, string>::const_iterator it = map_problemes.find(p);
            if (it == map_problemes.end()) map_problemes.insert(make_pair(p, nom_s));
            else throw ExcepcioEvaluator(e5);
        }
    }
}

void Curs::escriure_usuaris() const {
    cout << u_inscrits << endl;
}

void Curs::escriure_curs() const {
    int len = llista_sessions.size();
    cout << id << " " << u_completats << " " << u_inscrits << " " << len << " (";
    for (int i = 0; i < len - 1; ++i) {
        cout << llista_sessions[i] << " ";
    }
    cout << llista_sessions[len - 1] << ")" << endl;
}










