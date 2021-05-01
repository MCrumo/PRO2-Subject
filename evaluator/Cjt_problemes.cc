#include "Cjt_problemes.hh"

const char *e1 = "error: el problema ya existe";
const char *e2 = "error: el problema no existe";
const char *e11 = "error: el problema no pertenece al curso";

Cjt_problemes::Cjt_problemes() {}

void Cjt_problemes::afegir_problema(const Problema& p) {
    map<string, Problema>::const_iterator it = llista_problemes.find(p.nom_problema());
    if (it != llista_problemes.end()) throw ExcepcioEvaluator(e1);
    else {
        llista_problemes.insert(make_pair(p.nom_problema(), p));
        vector_problemes.push_back(p);
        sort(vector_problemes.begin(), vector_problemes.end());
        cout << llista_problemes.size() << endl;
    }
}

void Cjt_problemes::existeix_problema(string nom) {
    map<string, Problema>::const_iterator it = llista_problemes.find(nom);
    if (it == llista_problemes.end()) {
        throw ExcepcioEvaluator(e2);
        // return false; ->for bool
    }
    // else return true; ->for bool
}
/*
Problema Cjt_problemes::buscar_problema(string nom) {
    map<string, Problema>::const_iterator it = llista_problemes.find(nom);
    if (it == llista_problemes.end()) throw ExcepcioEvaluator(e2);
    else {
        return it->second;
    }
}*/

void Cjt_problemes::llegir_problemes() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Problema p;
        p.llegir_problema();
        llista_problemes.insert(make_pair(p.nom_problema(), p));
        vector_problemes.push_back(p);
        sort(vector_problemes.begin(), vector_problemes.end());
    }
}

void Cjt_problemes::llistar_problemes() const {
    for (int i = 0; i < vector_problemes.size(); ++i) {
        vector_problemes[i].escriure_problema();
    }
}

void Cjt_problemes::escriure_problema(string p) const {
    map<string, Problema>::const_iterator it = llista_problemes.find(p);
    it->second.escriure_problema();
}











