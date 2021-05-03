 /** @file Cjt_sessions.hh
    @brief Especificació de la classe Cjt_sessions
*/
 
#ifndef CJT_SESSIONS
#define CJT_SESSIONS

#include "Sessio.hh" 

/** @class Cjt_sessions
    @brief Representa el conjunt de sessions del Evaluator.
*/

class Cjt_sessions
{
public:
    //Constructores
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post el resultat es un conjunt de sessions buit
    */
    Cjt_sessions();
    
    //Modificadores
    
    /** @brief Afegeix una sessio al conjunt de sessions
      \pre <em>cert</em>
      \post s'ha afegit la sessio s al parametre implicit i s'ha escrit el total de sessions pero en cas que ja existis, s'ha impres un missatge d'error
    */
    void afegir_sessio(Sessio& s);
    
    //Consultores
    
    /** @brief Consulta si hi ha una certa sessio al conjunt de sessions
      \pre <em>cert</em>
      \post llença un error si la sessio amb id "s" no esta al parametre implicit
    */
    void existeix_sessio(string s);
    
    /** @brief Consulta si hi ha un problema al conjunt de sessions
      \pre existeix el roblema "nom_p" i ses es un subconjunt del parametre implicit
      \post retorna el nom de la sessio on esta el problema "nom_p" i llença un error en cas que el problema no estigui a ses
    */
    string existeix_s_problema(const vector<string>& ses, string nom_p);
    
    /** @brief Consulta si hi ha problemes repetits al conjunt de sessions
      \pre <em>cert</em>
      \post true si han problemes repetits entre dues o mes sessions, false en cas contrari
    */
    bool problemes_repetits();
    
    /** @brief Consulta una sessio del conjunt
      \pre <em>cert</em>
      \post el resultat es la sessio amb nom "nom" que conte el parametre implicit, s'ha llençat un missatge d'error si "nom" no pertany al parametre implicit
    */
    //Sessio buscar_sessio(string nom) const;
    
    /** @brief Consulta el problema inicial d'una sessio
      \pre <em>cert</em>
      \post el resultat es el nom del problema inicial de la sessio "s", s'ha llençat un missatge d'error si "s" no pertany al parametre implicit
    */
    string problema_s_inicial(string s) const;
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt de sessions
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre d'elements que llegirem) i les dades de tal nombre de sessions diferents
      \post el parametre implicit conte el conjunt de sessions llegits del canal estandard d'entrada
    */
    void llegir_sessions();
    
    /** @brief Operació d'escriptura de totes les sessions
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida les sessions del parametre implicit en ordre ascendent de l'identificador
    */
    void llistar_sessions() const;
    
    /** @brief Operació d'escriptura d'una sessio
      \pre existeix sessio amb id "s" al parametre implicit
      \post s'han escrit pel canal estàndard de sortida els atributs de la sessio "s" del parametre implicit
    */
    void escriure_sessio(string s) const;
    
private:
    map<string, Sessio> llista_sessions;
};
#endif

