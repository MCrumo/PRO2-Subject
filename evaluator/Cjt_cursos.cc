#include "Cjt_cursos.hh"

const char *e6 = "error: el curso no existe";

Cjt_cursos::Cjt_cursos() { }
/*
void Cjt_cursos::afegir_curs(const Curs& c) {
    if(...)
        llista_cursos.push_back(c);
}
*/

void Cjt_cursos::existeix_curs(int nom) {
    int i = nom - 1;
    if (llista_cursos.empty() or i < 0 or i >= llista_cursos.size()) {
        throw ExcepcioEvaluator(e6);
        // return false; ->for bool
    }
    // else return true; ->for bool
}

int Cjt_cursos::total_cursos() const{
    return llista_cursos.size();
}

Curs Cjt_cursos::buscar_curs(int nom) {
    int i = nom - 1;
    if (llista_cursos.empty() or i < 0 or i >= llista_cursos.size()) {
        throw ExcepcioEvaluator(e6);
    }
    else return llista_cursos[i];
}

void Cjt_cursos::llegir_cursos() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Curs c;
        c.llegir_curs(i + 1);
        llista_cursos.push_back(c);
    }
}

void Cjt_cursos::escriure_cursos() const {
    cout << llista_cursos.size() << endl;
}

void Cjt_cursos::llistar_cursos() const {
    for (int i = 0; i < llista_cursos.size(); ++i) {
        llista_cursos[i].escriure_curs();
    }
}


















