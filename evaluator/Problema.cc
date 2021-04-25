#include "Problema.hh"

Problema::Problema() {
    id = "";
    e_correctes = 0;
    e_totals = 0;
    ratio = 1.0;
}

Problema::Problema(string nom) {
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

string Problema::nom_problema() const {
    return id;
}

int Problema::consul_enviats() const {
    return e_totals;
}

int Problema::consul_correctes() const {
    return e_correctes;
}

double Problema::consul_ratio() const {
    return ratio;
}

void Problema::llegir_problema() {
    cin >> id;
}

void Problema::escriure_problema() const {
    cout << id << "(" << e_totals << "," << e_correctes << "," << ratio << ")" << endl;
}

bool Problema::operator<(const Problema& p) const {
    if (ratio != p.ratio) return ratio < p.ratio;
    else return id < p.id;
}







