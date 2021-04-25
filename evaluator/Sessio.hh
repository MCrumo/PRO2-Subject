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
    
    /** @brief Afegeix un conjunt de problemes a la sessio
      \pre estan preparats al canal estandar d'entrada un conjunt d'identificadors de problemes en preordre
      \post s'han afegit els problemes al parametre implicit
    */
    void afegir_problemes(BinTree<string>& t);
    
    //Consultores
    
    /** @brief Compara els problemes entre dues sessions
      \pre sessio 1 i sessio 2
      \post true si s1 i s2 tenen algun problema en comu
    */
    static bool comp_problemes(const Sessio& s1, const Sessio& s2);
    
    /** @brief Consulta els problemes de la sessio
      \pre <em>cert</em>
      \post el resultat son els problemes de la sessio
    */
    BinTree<string> consul_problemes();
    
    /** @brief Consulta el nom de la sessio
      \pre <em>cert</em>
      \post el resultat es nom del parametre implicit
    */
    string nom_sessio();
    
    /** @brief Consulta el nombre de problemes del curs
      \pre <em>cert</em>
      \post el resultat es el nombre total de problemes del parametre implicit
    */
    int total_problemes();
    
    /** @brief Consulta el nom dels problemes de la sessio
      \pre <em>cert</em>
      \post el resultat es un vector de noms dels problemes en postordre
    */
    vector<string> nom_problemes();
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura de sessio
      \pre hi ha preparat al canal estandard d'entrada un string i una sequencia d'identificadors de problemes en preordre
      \post el parametre implicit passa a tenir els atributs llegits del canal estandard d'entrada
    */
    void llegir_sessio();
    
    /** @brief Operacio d'escriptura de sessio
      \pre <em>cert</em>
      \post s'han escrit els atributs del parametre implicit al canal estandard de sortida
    */
    void escriure_sessio(const BinTree<string>& t) const;

private:
    string id;
    BinTree<string> problemes_sessio;
    int problemes_totals;
};

#endif
