#include "Curs.hh" 

Curs::Curs() {
    u_inscrits = 0;
    u_completats = 0;
}

Curs::Curs(int nom, const Cjt_sessions& s) {
    u_inscrits = 0;
    u_completats = 0;
    id = nom;
}

void Curs::afegir_sessions(const Cjt_sessions& s) {
    
}
