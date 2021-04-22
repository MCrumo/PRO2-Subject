#include "Problema.hh"

Problema::Problema() {
    id = "";
    e_correctes = 0;
    e_totals = 0;
    ratio = 1.0;
}

Problema::Problema(srting nom) {
    id = nom;
    e_correctes = 0;
    e_totals = 0;
    ratio = 0;
}

void Problema::incrementar_envio() {
    e_totals += 1;
}

void Problema::incrementar_correctes() {
    e_correctes += 1;
}

void Problema::actualitzar_ratio() {
    ratio = (1 + e_totals) / double(1 + e_correctes);
}

string Problema::nom_problema() {
    return id;
}

int Problema::consul_enviats() {
    return e_totals;
}

int Problema::consul_correctes() {
    return e_correctes;
}

double Problema::consul_ratio() {
    return ratio;
}

void Problema::llegir_problema() {
    cin >> nom_p;
    id = nom_p;
    
}

void escriure_problema() {
    cout << id << "(" << e_totals << "," e_correctes << "," << ratio << ")" << endl;
}







