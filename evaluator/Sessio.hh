/** @file Sessio.hh
    @brief Especificació de la classe Sessio
*/

#ifndef SESSIO
#define SESSIO

#include "Problema.hh"
#include "BinTree.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
using namespace std;
#endif

/** @class Sessio
    @brief Representa una sessió del Evaluator.
    
    Conté un subconjut de problemes de la colecció de problemes
*/

class Sessio
{
public:
    //Constructores
    
    /** @brief Creadora per defecte.
        S'executa directament al declara una sessió.
        \pre <em>cert</em>
        \post El resultat és una sessió sense nom i sense problemes
    */
    Sessio();
    
    /** @brief Creadora amb valors concrets.
        \pre nom es de tipus string
        \post el resultat es una sessio amb nom "nom" i sense problemes
    */
    Sessio(string nom);
    
    //Modificadores
    
    bool existeix_problema(string p);
    
    void actual_problemes(string p, const map<string, int>& llr, map<string, int>& lle);
    
    void afegir_enviables(const map<string, int>& llr, map<string, int>& lle);
    
    //Consultores
    
    /** @brief Consulta si p esta entre el conjunt de problemes
      \pre <em>cert</em>
      \post retorna true si el problema "p" pertany al parametre implicit
    */
    bool conte_problema(string p);
    
    /** @brief Consulta el problema inicial de la sessio
      \pre <em>cert</em>
      \post retorna el nom del problema inicial del parametre implicit
    */
    //string problema_inicial() const;
    
    /** @brief Compara els problemes entre dues sessions
      \pre arbre a2 i v es fals
      \post v es true si el parametre implicit i a2 tenen algun problema en comu
    */
    void cmp_problemes(const BinTree<string>& a2, bool& v) const;
    
    /** @brief Troba si hi ha un cret n a l'arbre a
      \pre arbre a i string n
      \post true si a conte n
    */
    //bool trobar_valor(const BinTree<string>& a, string n) const;
    
    /** @brief Consulta els problemes de la sessio
      \pre <em>cert</em>
      \post el resultat son els problemes de la sessio
    */
    BinTree<string> consul_problemes() const;
    
    /** @brief Consulta el nom de la sessio
      \pre <em>cert</em>
      \post el resultat es nom del parametre implicit
    */
    string nom_sessio() const;
    
    /** @brief Consulta el nombre de problemes del curs
      \pre <em>cert</em>
      \post el resultat es el nombre total de problemes del parametre implicit
    */
    int total_problemes() const;
    
    /** @brief Consulta el nom dels problemes de la sessio
      \pre 0 <= i < el tamany de la llista de problemes
      \post el resultat es el nom del problema a la iessima possicio
    */
    string consul_iessim(int i) const;
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura de sessio
      \pre hi ha preparat al canal estandard d'entrada un string i una sequencia d'identificadors de problemes en preordre
      \post el parametre implicit passa a tenir els atributs llegits del canal estandard d'entrada
    */
    void llegir_sessio();
    
    /** @brief Operacio de lectura de sessio
      \pre hi ha preparat al canal estandard d'entrada una sequencia d'identificadors de problemes en preordre
      \post el parametre implicit passa a tenir els atributs llegits del canal estandard d'entrada
    */
    void llegir_p_sessio();
    
    /** @brief Operacio d'escriptura de sessio
      \pre <em>cert</em>
      \post s'han escrit tots els atributs del parametre implicit al canal estandard de sortida
    */
    void escriure_sessio() const;

private:
    string id;
    BinTree<string> problemes_sessio;
    vector<string> llista_problemes;
    void llegir_preordre(BinTree<string>& t);
    void escriure_postordre(const BinTree<string>& t) const;
    void buscar_prerequisits(const BinTree<string>& a, const map<string, int>& llr, map<string, int>& lle, string p, bool& cond);
    void afegir_prerequisits(const BinTree<string>& a, const map<string, int>& llr, map<string, int>& lle);
    bool trobar_valor(const BinTree<string>& a, string n) const;
};

#endif
