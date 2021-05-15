#include "Sessio.hh" 

Sessio::Sessio() {}

Sessio::Sessio(string nom) {
    id = nom;
}

void Sessio::actual_problemes(string p, const Cjt_problemes& llr, Cjt_problemes& lle) {
    bool cond = true;
    buscar_prerequisits(problemes_sessio, llr, lle, p, cond);
}

void Sessio::afegir_enviables(const Cjt_problemes& llr, Cjt_problemes& lle) {
    afegir_prerequisits(problemes_sessio, llr, lle);
}

string Sessio::nom_sessio() const {
    return id;
}

int Sessio::total_problemes() const {
    return llista_problemes.size();
}

string Sessio::consul_iessim(int i) const {
    return llista_problemes[i];
}

void Sessio::llegir_p_sessio() {
    llegir_preordre(problemes_sessio);
}

void Sessio::escriure_sessio() const {
    cout << id << " " << llista_problemes.size() << " ";
    escriure_postordre(problemes_sessio);
    cout << endl;
}


void Sessio::llegir_preordre(BinTree<string>& t) {
    string nom_p;
    if (cin >> nom_p and nom_p != "0") {
        llista_problemes.push_back(nom_p);
        BinTree<string> t1;
        BinTree<string> t2;
        llegir_preordre(t1);
        llegir_preordre(t2);
        t = BinTree<string> (nom_p, t1, t2);  
    }
}

void Sessio::escriure_postordre(const BinTree<string>& t) {
    if (not t.empty()) {
        cout << "(";
        escriure_postordre(t.left());
        escriure_postordre(t.right());
        cout << t.value();
        cout << ")";
    }
}

void Sessio::buscar_prerequisits(const BinTree<string>& a, const Cjt_problemes& llr, Cjt_problemes& lle, string p, bool& cond) {
    if (not a.empty()) {
        if (a.value() == p) {
            cond = false;
            if (not a.left().empty()) {
                if (not llr.conte_problema(a.left().value())) lle.afegir_nom_problema(a.left().value());
                else buscar_prerequisits(a.left(), llr, lle, a.left().value(), cond);
            }
            if (not a.right().empty()) {
                if (not llr.conte_problema(a.right().value())) lle.afegir_nom_problema(a.right().value());
                else buscar_prerequisits(a.right(), llr, lle, a.right().value(), cond);
            }
        }
        else {
            if (cond) buscar_prerequisits(a.left(), llr, lle, p, cond);
            if (cond) buscar_prerequisits(a.right(), llr, lle, p, cond);
        }
    }
}

void Sessio::afegir_prerequisits(const BinTree<string>& a, const Cjt_problemes& llr, Cjt_problemes& lle) {
    if (not a.empty()) {
        if (not llr.conte_problema(a.value())) lle.afegir_nom_problema(a.value());
        else {
            afegir_prerequisits(a.right(), llr, lle);
            afegir_prerequisits(a.left(), llr, lle);
        }
    }
}



















