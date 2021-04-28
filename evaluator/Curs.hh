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
    //Constructoras

    /** @brief Creadora por defecte. 
    \pre <em>cert</em>
    \post el resultat es un curs sense nom ni sessions
    */  
    Curs();
    
    /** @brief Creadora amb valors concrets.
    \pre <em>cert</em>
    \post el resultat es un curs amb nom "nom" i un conjunt de sessions s
    */
    Curs(int nom, const vector<string>& s);
    
    //Modificadores
    
    /** @brief Modificadora de l'atribut usuaris totals
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir els usuaris totals inicials mes 1
    */
    void incrementar_usuari();
    
    /** @brief Modificadora de l'atribut del total de gent que ha completat el curs
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir el total de gent que ha completat el curs inicialment mes 1
    */
    void incrementar_completats();
    
    /** @brief Modificadora de l'atribut del total de gent inscrita al curs
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir el total de gent inscrits al curs inicialment menys 1
    */
    void decrementar_inscrits();
    
    //Consultores
    
    /** @brief Consulta el nom (identificador) del curs
      \pre <em>cert</em>
      \post El resultat és l'identificador (enter) del parametre implicit
    */
    int nom_curs() const;
    
    /** @brief Consulta el nombre d'usuaris inscrits
      \pre <em>cert</em>
      \post el resultat es el nombre d'usuaris del parametre implicit
    */
    int usuaris_inscrits() const;
    
    /** @brief Consulta el nombre d'usuaris que han completat el curs
      \pre <em>cert</em>
      \post el resultat es el nombre d'usuaris que han completat el curs del parametre implicit
    */
    int usuaris_completats() const;
    
    /** @brief Consulta el nombre de sessions del curs
      \pre <em>cert</em>
      \post el resultat es el nombre total de sessions del parametre implicit
    */
    int total_sessions() const;
    
    /** @brief Consulta el nom de sessions del curs
      \pre <em>cert</em>
      \post el resultat es un vector de noms de les sessions del parametre implicit amb el mateix ordre en el que van ser llegides
    */
    vector<string> nom_sessions() const;
    
    /** @brief Consulta si el curs conte un cert problema
      \pre <em>cert</em>
      \post true si el curs conte el problema p, false en cas contrari
    */
    bool conte_problema(string p);
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura d'un curs
        \pre nom es de tipus enter i estan preparats al canal estandard d'endrada un conjunt de sessions
        \post s'ha afegit la informacio al parametre implicit
    */
    void llegir_curs(int nom);
    
    /** @brief Operacio d'escriptura del total d'usuaris inscrits al curs
      \pre <em>cert</em>
      \post s'ha escrit pel canal estandard de sortida el nombre total d'usuaris inscrits al curs del parametre implicit
    */
    void escriure_usuaris() const;
    
    /** @brief Escriu el nom de la sessio que conte el problema p
      \pre el curs conte el problema p
      \post s'ha escrit pel canal estandard de sortida el nom de la sessio que conte el problema p del parametre implicit
    */
    void nom_sessio(string p) const;
    
    /** @brief Operacio d'escriptura de curs
      \pre <em>cert</em>
      \post s'han escrit els atributs del parametre implicit al canal estandard de sortida
    */
    void escriure_curs() const;
    
private:
    int id;
    int u_inscrits;
    int u_completats;
    vector<string> llista_sessions;
    map<string, int> map_problemes; //PROFE RULES
};

#endif









