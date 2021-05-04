/**
 * @mainpage Pràctica de PRO2: Evaluator, plataforma de gestió de problemes i cursos de programació. 

 En aquesta pràctica farem una plataforma de cursos de programació anomenada Evaluator en la cual un conjunt d'usuaris podran anar completant aquests cursos.
*/

/** @file main.cc
    @brief Programa principal de la pràctica <em>Evaluator, plataforma de gestió de problemes i cursos de programació</em>.
*/

#include "Cjt_problemes.hh"
#include "Cjt_sessions.hh"
#include "Cjt_cursos.hh"
#include "Cjt_usuaris.hh"
#ifndef NO_DIAGRAM
#endif

/** @brief Programa principal de la pràctica <em>Evaluator, plataforma de gestió de problemes i cursos de programació</em>.
*/

int main ()
{
    Cjt_problemes cjt_p;
    Cjt_sessions cjt_s;
    Cjt_cursos cjt_c;
    Cjt_usuaris cjt_u;
    
    cjt_p.llegir_problemes();
    cjt_s.llegir_sessions();
    cjt_c.llegir_cursos();
    cjt_u.llegir_usuaris();
    
    string c;
    while (c != "fin") {
        string cmd, nom;
        cmd = "#" + c;
        int nom_int;
        if (c == "nuevo_problema" or c == "np") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            Problema p(nom);
            try { cjt_p.afegir_problema(p); }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "nueva_sesion" or c == "ns") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            Sessio s(nom);
            s.llegir_p_sessio();
            try { cjt_s.afegir_sessio(s); }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "nuevo_curso" or c == "nc") { //Entrega_FINAL
            cout << cmd << endl;
            Curs c;
            c.llegir_curs(cjt_c.total_cursos() + 1);
            try {
                cjt_s.validar_problemes(c.consul_sessions());
                cjt_c.afegir_curs(c);
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "alta_usuario" or c == "a") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            Usuari u(nom);
            try { cjt_u.afegir_usuari(u); }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "baja_usuario" or c == "b") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            try { 
                nom_int = cjt_u.eliminar_usuari(nom); 
                cjt_c.actual_usuaris(nom_int);
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "inscribir_curso" or c == "i") {
            cin >> nom >> nom_int;
            cout << cmd << " " << nom << " " << nom_int << endl;
            try {
                cjt_u.existeix_usuari(nom);
                try { 
                    cjt_c.existeix_curs(nom_int);
                    try {
                        cjt_u.insc_usuari_curs(nom, nom_int, cjt_c, cjt_s);
                        cjt_c.curs_inc_usuari(nom_int);
                    }
                    catch(exception& e) { cout << e.what() << endl; }
                }
                catch(exception& e) { cout << e.what() << endl; }
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "curso_usuario" or c == "cu") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            try { cjt_u.escriure_curs_inscrit(nom); }
            catch(exception& e) { cout << e.what() << endl; }
        } 
        else if (c == "sesion_problema" or c == "sp") {
            cin >> nom_int >> nom;
            cout << cmd << " " << nom_int << " " << nom << endl;
            try {
                cjt_c.existeix_curs(nom_int);
                try {
                    cjt_p.existeix_problema(nom);
                    try {
                        vector<string> ses = cjt_c.consul_c_sessions(nom_int);
                        cout << cjt_s.existeix_s_problema(ses, nom) << endl;
                    }
                    catch(exception& e) { cout << e.what() << endl; }
                }
                catch(exception& e) { cout << e.what() << endl; }
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "problemas_resueltos" or c == "pr") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            try { 
                cjt_u.existeix_usuari(nom);
                cjt_u.llistar_u_resolts(nom); 
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "problemas_enviables" or c == "pe") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            try { 
                cjt_u.existeix_usuari(nom);
                try {
                    cjt_u.llistar_u_enviables(nom);
                }
                catch(exception& e) { cout << e.what() << endl; }
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        /*
        else if (c == "envio" or c == "e") { //Entrega_FINAL
            cin >> nom >> nom_2 >> nom_int; //u >> p >> r;
            Usuari u;
            Problema p;
            u = cjt_u.buscar_usuari(nom);
            p = cjt_p.buscar_problema(nom_2);
            u.incrementar_totals();
            u.intent_resoldre(nom_2); //-> int_res inacavada!
            p.incrementar_envio();
            if (nom_int == 1) {
                p.incrementar_correctes();
                u.afegir_correcte(nom_2); // -> afg_corr inacavada!
                u.actualitzar_curs(); // -> act_curs inacavada!
                if (u.curs_acabat()) {
                    Curs c;
                    c = cjt_c.buscar_curs(u.consultar_curs());
                    c.incrementar_completats();
                    c.decrementar_inscrits();
                }
            }
        }
        */
        else if (c == "listar_problemas" or c == "lp") {
            cout << cmd << endl;
            cjt_p.llistar_problemes();
        }
        else if (c == "escribir_problema" or c == "ep") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            try { 
                cjt_p.existeix_problema(nom);
                cjt_p.escriure_problema(nom); 
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "listar_sesiones" or c == "ls") {
            cout << cmd << endl;
            cjt_s.llistar_sessions();
        }
        else if (c == "escribir_sesion" or c == "es") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            try { 
                cjt_s.existeix_sessio(nom);
                cjt_s.escriure_sessio(nom); 
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "listar_cursos" or c == "lc") {
            cout << cmd << endl;
            cjt_c.llistar_cursos();
        }
        else if (c == "escribir_curso" or c == "ec") {
            cin >> nom_int; 
            cout << cmd << " " << nom_int << endl;
            try { 
                cjt_c.existeix_curs(nom_int);
                cjt_c.escriure_curs(nom_int);
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        else if (c == "listar_usuarios" or c == "lu") {
            cout << cmd << endl;
            cjt_u.llistar_usuaris();
        }
        else if (c == "escribir_usuario" or c == "eu") {
            cin >> nom;
            cout << cmd << " " << nom << endl;
            try {
                cjt_u.existeix_usuari(nom);
                cjt_u.escriure_usuari(nom);
            }
            catch(exception& e) { cout << e.what() << endl; }
        }
        cin >> c;
    }
} 
