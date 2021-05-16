/** @file Curs.hh
    @brief Especificació de la classe Curs
*/

#ifndef CURS
#define CURS

#include "Cjt_sessions.hh"

/** @class Curs
    @brief Representa un curs del Evaluator.
    
    Format per un subconjut del total de sessions
*/

class Curs 
{   
public:
    //Constructores

    /** @brief Creadora por defecte. 
    \pre <em>cert</em>
    \post el resultat es un curs sense id, amb u_inscrits = 0, u_completats = 0 i sense sessions
    \cost constant
    */  
    Curs();
    
    //Modificadores
    
    /** @brief Augmenta en 1 els usuaris inscrits al curs
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir els u_inscrits inicials +1
        \cost constant
    */
    void incrementar_usuari();
    
    /** @brief Augmenta en 1 els usuaris que han completat el curs
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir els u_completats inicials +1
        \cost constant
    */
    void incrementar_completats();
    
    /** @brief Decrementa en 1 els usuaris inscrits al curs
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir els u_inscrits inicials -1
        \cost constant
    */
    void decrementar_inscrits();
    
    //Consultores
    
    /** @brief Consulta la id de la sessio que conte el problema nom_p
        \pre <em>cert</em>
        \post retorna la id de la sessio del parametre implicit que conte el problema amb id = nom_p, si no hi ha cap sessio al parametre implicit que contingui el problema, s'imprimeix un missatge d'error
        \cost logaritmic
    */
    string sessio_problema(string nom_p) const;
    
    /** @brief Consulta la id del curs
      \pre <em>cert</em>
      \post el resultat es la id del parametre implicit
      \cost constant
    */
    int nom_curs() const;
    
    /** @brief Consulta el nombre d'usuaris inscrits al curs
      \pre <em>cert</em>
      \post el resultat es el u_inscrits del parametre implicit
      \cost constant
    */
    int usuaris_inscrits() const;
    
    /** @brief Consulta el nombre d'usuaris que han completat el curs
      \pre <em>cert</em>
      \post el resultat es el u_completats del parametre implicit
      \cost constant
    */
    int usuaris_completats() const;
    
    /** @brief Consulta el nombre total de sessions del curs
      \pre <em>cert</em>
      \post el resultat es el nombre total de sessions del parametre implicit
      \cost constant
    */
    int total_sessions() const;
    
    /** @brief Consulta la id de la iessima sessio del curs
      \pre 0 <= i < llista_sessions.size()
      \post el resultat es la id de la sessio situada a la iessima possicio del parametre implicit
      \cost constant
    */
    string consul_iessim(int i) const;
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura d'un curs
        \pre nom es de tipus enter i ses es un conjunt de sessions, estan preparats al canal estandard d'endrada un llistat de sessions
        \post el curs passa a tenir id = nom, el llistat de sessions llegits al canal d'entrada i un conjunt de problema/sessio al parametre implicit
    */
    void llegir_curs(int nom, const Cjt_sessions& ses);
    
    /** @brief Operacio d'escriptura de curs
      \pre <em>cert</em>
      \post s'han escrit els atributs del parametre implicit al canal estandard de sortida
      \cost lineal
    */
    void escriure_curs() const;
    
private:
    int id;
    int u_inscrits;
    int u_completats;
    vector<string> llista_sessions;
    map<string, string> map_problemes;
};

#endif









