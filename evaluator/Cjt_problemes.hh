/** @file Cjt_problemes.hh
    @brief Especificació de la classe Cjt_problemes
*/

#ifndef CJT_PROBLEMES
#define CJT_PROBLEMES

#include "Problema.hh"
#ifndef NO_DIAGRAM
#include <map>
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
      \pre el parametre implicit no conte cap problema amb el nom de p
      \post s'ha afegit el problema p al parametre implicit
    */
    void afegir_problema(const Problema& p);
    
    //Consultores
    
    /** @brief Consulta si hi ha un cert problema al conjunt de problemes
      \pre <em>cert</em>
      \post retorna ture si hi ha un problema amb identificador "nom" al parametre implicit
    */
    bool existeix_problema(string nom);
    
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
    
    /** @brief Operació d'escriptura del total de problemes
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida el total de problemes del parametre implicit
    */
    void escriure_problemes() const;
    
    /** @brief Operació d'escriptura de tots els problemes
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida els problemes del parametre implicit en ordre ascendent de ratio i en cas d'empat per odre creixent d'identificador
    */
    void llistar_problemes() const;
    
private:
    map<string, Problema> llista_problemes;
};

#endif







