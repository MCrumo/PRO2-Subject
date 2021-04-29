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
    //cjt_s.llegir_sessions();
    //cjt_c.llegir_cursos();
    //cjt_u.llegir_usuaris();
    
    string c;
    while (c != "fin") {
        string cmd = "#" + c + " ";
        int nom_int;
        bool b, y;
        string nom, nom_2;
        if (c == "nuevo_problema" or c == "np") {
            cin >> nom;
            Problema p(nom);
            try { cjt_p.afegir_problema(p); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "nueva_sesion" or c == "ns") {
            Sessio s;
            s.llegir_sessio();
            try { cjt_s.afegir_sessio(s); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }/*
        else if (c == "nuevo_curso" or c == "nc") { //Entrega_FINAL
            Curs c;
            c.llegir_curs(cjt_c.total_cursos() + 1);
            cjt_c.afegir_curs(c); //llensara error o seguira executan? -> no acabat el .cc
            cjt_c.escriure_cursos();
        } */
        else if (c == "alta_usuario" or c == "a") {
            cin >> nom;
            Usuari u(nom);
            try { cjt_u.afegir_usuari(u); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "baja_usuario" or c == "b") {
            cin >> nom;
            try { cjt_u.eliminar_usuari(nom); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "inscribir_curso" or c == "i") {
            cin >> nom >> nom_int;
            try { b = cjt_c.existeix_curs(nom_int); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
            Usuari u; 
            try { u = cjt_u.buscar_usuari(nom); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
            try {
                y = u.curs_acabat(); // falta fer throw error!!
                if (b and y) {
                    u.inscriure_curs(nom_int);
                    Curs c;
                    c = cjt_c.buscar_curs(nom_int);
                    c.incrementar_usuari();
                    c.escriure_usuaris();
                }
            }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "curso_usuario" or c == "cu") {
            cin >> nom;
            try { (cjt_u.buscar_usuari(nom)).escriure_curs_inscrit(); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        } 
        /*
        else if (c == "sesion_problema" or c == "sp") {
            //Cjt_cursis:: string sesion_prob(int c const string& p) const;
            cin >> nom_int >> nom_2;
            x = cjt_c.existeix_curs(nom_int);
            b = cjt_p.existeix_problema(nom_2);
            if (x and b) {
                Curs c;
                c = cjt_c.buscar_curs(nom_int);
                y = c.conte_problema(nom_2); //fer el throw error -> funcio inacavada!
                if (y) c.nom_sessio(nom_2);
            }
        }
        */
        else if (c == "problemas_resueltos" or c == "pr") {
            cin >> nom;
           try { (cjt_u.buscar_usuari(nom)).llistar_resolts(); }
           catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "problemas_enviables" or c == "pe") {
            cin >> nom;
            Usuari u; 
            try {
                u = cjt_u.buscar_usuari(nom);
                if (not (u.consultar_curs() > 0)) {
                    cout << e10 << endl;
                } 
                else u.llistar_enviables(); //-> ll_env inacavada!
            }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
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
            cjt_p.llistar_problemes();
        }
        else if (c == "escribir_problema" or c == "ep") {
            cin >> nom;
            try { (cjt_p.buscar_problema(nom)).escriure_problema(); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "listar_sesiones" or c == "ls") {
            cjt_s.llistar_sessions();
        }
        else if (c == "escribir_sesion" or c == "es") {
            cin >> nom;
            try { (cjt_s.buscar_sessio(nom)).escriure_sessio(); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "listar_cursos" or c == "lc") {
            cjt_c.llistar_cursos();
        }
        else if (c == "escribir_curso" or c == "ec") {
            cin >> nom_int; 
            try { (cjt_c.buscar_curs(nom_int)).escriure_curs(); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        else if (c == "listar_usuarios" or c == "lu") {
            cjt_u.llistar_usuaris();
        }
        else if (c == "escribir_usuario" or c == "eu") {
            cin >> nom;
            try { (cjt_u.buscar_usuari(nom)).escriure_usuari(); }
            catch(ExcepcioEvaluator e) { cout << e.what() << endl; }
        }
        cin >> c;
    }
} 
