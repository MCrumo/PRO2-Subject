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

BinTree<string> Sessio::consul_problemes() const {
    return problemes_sessio;
}

string Sessio::nom_sessio() const {
    return id;
}

int Sessio::total_problemes() const {
    return problemes_totals;
}

//vector<string> Sessio::nom_problemes() {}

void Sessio::cmp_problemes(const BinTree<string>& a2, bool& v_igual) const {
    if (not a2.empty() and not v_igual){
        cmp_problemes(a2.left(), v_igual);
        cmp_problemes(a2.right(), v_igual);
        if (trobar_valor(problemes_sessio, a2.value())) {
            v_igual = true;
        }
    }
}

bool Sessio::trobar_valor(const BinTree<string>& a, string n) const {
    bool b;
    if (a.empty()) b = false;
    else if (a.value() == n) b = true;
    else {
        b = trobar_valor(a.left(),n);
        if (not b) b = trobar_valor(a.right(), n);
    }
    return b;
}

void Sessio::llegir_sessio() {
    cin >> id;
    afegir_problemes(problemes_sessio);
    
}

void Sessio::escriure_sessio_p(const BinTree<string>& t) const {
    if (not t.empty()) {
        cout << "(";
        escriure_sessio_p(t.left());
        escriure_sessio_p(t.right());
        cout << t.value();
        cout << ")";
    }
}

void Sessio::escriure_sessio() const {
    cout << id << " " << problemes_totals << " ";
    escriure_sessio_p(problemes_sessio);
    cout << endl;
}



















