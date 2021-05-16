#include "Cjt_cursos.hh"

const char *e6 = "error: el curso no existe";

Cjt_cursos::Cjt_cursos() { }

void Cjt_cursos::afegir_curs(const Curs& c) {
    llista_cursos.push_back(c);
    cout << llista_cursos.size() << endl;
}


void Cjt_cursos::curs_inc_usuari(int nom_c) {
    llista_cursos[nom_c - 1].incrementar_usuari();
    cout << llista_cursos[nom_c - 1].usuaris_inscrits() << endl;
}

void Cjt_cursos::actual_usuaris(int c) {
    int i = c - 1;
    if ( i >= 0 and i < llista_cursos.size()) {
        llista_cursos[i].decrementar_inscrits();
    }
}

void Cjt_cursos::curs_completat(int c) {
    llista_cursos[c - 1].incrementar_completats();
    llista_cursos[c - 1].decrementar_inscrits();
}

void Cjt_cursos::existeix_curs(int nom) const{
    int i = nom - 1;
    if (llista_cursos.empty() or i < 0 or i >= llista_cursos.size()) {
        throw ExcepcioEvaluator(e6);
    }
}

int Cjt_cursos::total_cursos() const{
    return llista_cursos.size();
}

int Cjt_cursos::total_sessions(int c) const {
    return llista_cursos[c - 1].total_sessions();
}

string Cjt_cursos::sessio_problema(int c, string p) {
    return llista_cursos[c - 1].sessio_problema(p);
}


string Cjt_cursos::consul_c_iessim(int c, int i) const {
    return llista_cursos[c - 1].consul_iessim(i);
}

void Cjt_cursos::llegir_cursos(const Cjt_sessions& ses) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Curs c;
        c.llegir_curs(i + 1, ses);
        llista_cursos.push_back(c);
    }
}

void Cjt_cursos::llistar_cursos() const {
    for (int i = 0; i < llista_cursos.size(); ++i) {
        llista_cursos[i].escriure_curs();
    }
}

void Cjt_cursos::escriure_curs(int c) const {
    llista_cursos[c - 1].escriure_curs();
}

















