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

void Sessio::actual_problemes(string p, const map<string, int>& llr, map<string, int>& lle) {
    bool cond = true;
    buscar_prerequisits(problemes_sessio, llr, lle, p, cond);
    /*for (int i = 0; i < p.size(); ++i) {
        afegir_prerequisits(problemes_sessio, llr, lle);
        i = 10000;
    }*/
}
//funcio ineficient!!!
void Sessio::buscar_prerequisits(const BinTree<string>& a, const map<string, int>& llr, map<string, int>& lle, string p, bool& cond) {
    if (not a.empty()) {
        if (a.value() == p) {
            cond = false;
            if (not a.left().empty()) {
                map<string, int>::const_iterator it = llr.find(a.left().value());
                if (it == llr.end()) lle.insert(make_pair(a.left().value(), 0));
                else buscar_prerequisits(a.left(), llr, lle, a.left().value(), cond);
            }
            if (not a.right().empty()) {
                map<string, int>::const_iterator it = llr.find(a.right().value());
                if (it == llr.end()) lle.insert(make_pair(a.right().value(), 0));
                else buscar_prerequisits(a.right(), llr, lle, a.right().value(), cond);
            }
        }
        else {
            if (cond) buscar_prerequisits(a.left(), llr, lle, p, cond);
            if (cond) buscar_prerequisits(a.right(), llr, lle, p, cond);
        }
    }
}

void Sessio::afegir_enviables(const map<string, int>& llr, map<string, int>& lle) {
    afegir_prerequisits(problemes_sessio, llr, lle);
}

void Sessio::afegir_prerequisits(const BinTree<string>& a, const map<string, int>& llr, map<string, int>& lle) {
    if (not a.empty()) {
        map<string, int>::const_iterator it = llr.find(a.value());
        //map<string, int>::const_iterator it2 = lle.find(a.value());
        if (it == llr.end() /*and it2 == lle.end()*/) { 
            lle.insert(make_pair(a.value(), 0)); 
        }
        else {
            afegir_prerequisits(a.right(), llr, lle);
            afegir_prerequisits(a.left(), llr, lle);
        }
    }
    /*
    if a.value not in resolts
        enviables.add(a.value)
    else
        if a.right not empty: afegir_prerequisits(a.right)
        if a.left not empty afegir_prerequisits(a.left)
    
    if (not a.empty()) {
        map<string, int>::const_iterator it = llr.find(a.value());
        if (it != llr.end()) {
            if (not a.left().empty()) {
                it = llr.find(a.left().value());
                if (it == llr.end()) lle.insert(make_pair(a.left().value(), 0));
            }
            if (not a.right().empty()) {
                it = llr.find(a.right().value());
                if (it == llr.end()) lle.insert(make_pair(a.right().value(), 0));
            } else {
                afegir_prerequisits(a.left(), llr, lle);
                afegir_prerequisits(a.right(), llr, lle);
            }
        }
        else lle.insert(make_pair(a.value(), 0));
    }*/
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
/*
void Sessio::llegir_sessio() {
    cin >> id;
    llegir_preordre(problemes_sessio);
    
}
*/
void Sessio::llegir_p_sessio() {
    llegir_preordre(problemes_sessio);
}

void Sessio::escriure_postordre(const BinTree<string>& t) const {
    if (not t.empty()) {
        cout << "(";
        escriure_postordre(t.left());
        escriure_postordre(t.right());
        cout << t.value();
        cout << ")";
    }
}

void Sessio::escriure_sessio() const {
    cout << id << " " << llista_problemes.size() << " ";
    escriure_postordre(problemes_sessio);
    cout << endl;
}



















