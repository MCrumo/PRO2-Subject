#include "Sessio.hh" 

Sessio::Sessio() { }

Sessio::Sessio(string nom) {
    id = nom;
}
/*
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
}*/

void Sessio::afegir_problemes(BinTree<string>& t) {
    string nom_p;
    if (cin >> nom_p and nom_p != "0") {
        llista_problemes.push_back(nom_p);
        BinTree<string> t1;
        BinTree<string> t2;
        afegir_problemes(t1);
        afegir_problemes(t2);
        t = BinTree<string> (nom_p, t1, t2);  
    }
}
/*
bool Sessio::conte_problema(string p) {
    return trobar_valor(problemes_sessio, p);
}*/
/*
string Sessio::problema_inicial() const {
    return problemes_sessio.value();
}*/

BinTree<string> Sessio::consul_problemes() const {
    return problemes_sessio;
}

string Sessio::nom_sessio() const {
    return id;
}

int Sessio::total_problemes() const {
    return llista_problemes.size();
}
/*
bool Sessio::existeix_problema(string p) {
    return trobar_valor(problemes_sessio, p);
}*/

string Sessio::consul_iessim(int i) const {
    return llista_problemes[i];
}

void Sessio::actual_problemes(string p, map<string, int>& lle) {
    buscar_prerequisits(problemes_sessio, lle, p);
}

void Sessio::buscar_prerequisits(const BinTree<string>& a, map<string, int>& lle, string p) {
    if (not a.empty()) {
        if (a.value() == p) {
            if (not a.left().empty()) lle.insert(make_pair(a.left().value(), 0));
            if (not a.right().empty()) lle.insert(make_pair(a.right().value(), 0));
        }
        else {
            buscar_prerequisits(a.left(), lle, p);
            buscar_prerequisits(a.right(), lle, p);
        }
    }
}
/*
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
        b = trobar_valor(a.left(), n);
        if (not b) b = trobar_valor(a.right(), n);
    }
    return b;
}*/

void Sessio::llegir_sessio() {
    cin >> id;
    afegir_problemes(problemes_sessio);
    
}

void Sessio::llegir_p_sessio() {
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
    cout << id << " " << llista_problemes.size() << " ";
    escriure_sessio_p(problemes_sessio);
    cout << endl;
}



















