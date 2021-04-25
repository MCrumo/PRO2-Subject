#include "Sessio.hh" 

Sessio::Sessio() {
    problemes_totals = 0;
}

Sessio::Sessio(string nom) {
    problemes_totals = 0;
    id = nom;
}

void Sessio::afegir_problemes(BinTree<string>& t) {
    string nom_p;
    if (cin >> nom_p and nom_p != "0") {
        problemes_totals += 1;
        BinTree<string> t1;
        BinTree<string> t2;
        afegir_problemes(t1);
        afegir_problemes(t2);
        t = BinTree<string> (nom_p, t1, t2);  
    }
}

BinTree<string> Sessio::consul_problemes() {
    return problemes_sessio;
}

string Sessio::nom_sessio() {
    return id;
}

int Sessio::total_problemes() {
    return problemes_totals;
}
/*
vector<string> Sessio::nom_problemes() {
    
}
*/

void Sessio::llegir_sessio() {
    cin >> id;
    afegir_problemes(problemes_sessio);
    
}

void Sessio::escriure_sessio(const BinTree<string>& problemes_sessio) const {
    if (not problemes_sessio.empty()) {
        cout << "(";
        escriure_sessio(problemes_sessio.left());
        escriure_sessio(problemes_sessio.right());
        cout << problemes_sessio.value();
        cout << ")" << endl;
    }
}



















