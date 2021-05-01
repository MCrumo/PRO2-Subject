/** @file Cjt_problemes.hh
    @brief Especificació de la classe Cjt_problemes
*/

#ifndef CJT_PROBLEMES
#define CJT_PROBLEMES

#include "Problema.hh"
#ifndef NO_DIAGRAM
#include <algorithm>
#include <vector>
#endif

/** @class Cjt_problemes
    @brief Representa el conjunt de problemes del Evaluator.
*/

class Cjt_problemes
{
public:
    //Constructores
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post el resultat es un conjunt de problemes buit
    */
    Cjt_problemes();
    
    //Modificadores
    
    /** @brief Modifica el conjunt de problemes per afegir-li p
      \pre <em>cert</em>
      \post s'ha afegit el problema p al parametre implicit i en cas d'existir s'ha impres pel canal estandard de sortida un error
    */
    void afegir_problema(const Problema& p);
    
    //Consultores
    
    /** @brief Consulta si hi ha un cert problema al conjunt de problemes
      \pre <em>cert</em>
      \post llença un error si no hi ha un problema amb identificador "nom" al parametre implicit
    */
    void existeix_problema(string nom);
    
    /** @brief Consulta el problema amb identificador "nom"
      \pre el parametre implicit conte un problema amb nom "nom"
      \post el resultat es el problema amb nom "nom" que conte el parametre implicit
    */
    Problema buscar_problema(string nom);
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt de porblemes
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre d'elements que llegirem) i les dades de tal nombre de problemes diferents
      \post el parametre implicit conte el conjunt de problemes llegits del canal estandard d'entrada
    */
    void llegir_problemes();
    
    /** @brief Operació d'escriptura de tots els problemes
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida els problemes del parametre implicit en ordre ascendent de ratio i en cas d'empat per odre creixent d'identificador
    */
    void llistar_problemes() const;
    
private:
    map<string, Problema> llista_problemes;
    vector<Problema> vector_problemes;
};

#endif







