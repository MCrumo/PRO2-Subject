#include "Cjt_problemes.hh"

const char *e1 = "El problema ja existeix";
const char *e2 = "El problema no existeix";

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
/*
bool Cjt_problemes::existeix_problema(string nom) {
    
}
*/
Problema Cjt_problemes::buscar_problema(string nom) {
    map<string, Problema>::const_iterator it = llista_problemes.find(nom);
    if (it == llista_problemes.end()) throw ExcepcioEvaluator(e2);
    else {
        return it->second;
    }
}

void Cjt_problemes::llegir_problemes() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Problema p;
        p.llegir_problema();
        llista_problemes.insert(make_pair(p.nom_problema(), p));
    }
}

void Cjt_problemes::llistar_problemes() const{
    for (int i = 0; i < vector_problemes.size(); ++i) {
        vector_problemes[i].escriure_problema();
    }
}
