#include "Cjt_cursos.hh"

const char *e6 = "El curs no existeix";

Cjt_cursos::Cjt_cursos() { }
/*
void Cjt_cursos::afegir_curs(const Curs& c) {
    if(...)
        llista_cursos.push_back(c);
}
*/

bool Cjt_cursos::existeix_curs(int nom) {
    int i = nom - 1;
    if (i < 0 or i >= llista_cursos.size()) {
        throw ExcepcioEvaluator(e6);
        return false;
    }
    else return true;
}

int Cjt_cursos::total_cursos() const{
    return llista_cursos.size();
}

Curs Cjt_cursos::buscar_curs(int nom) {
    return llista_cursos[nom - 1];
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


















