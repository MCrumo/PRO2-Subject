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
        \cost constant
    */
    Cjt_problemes();
    
    //Modificadores
    
    /** @brief Afegeix un problema al conjunt
      \pre <em>cert</em>
      \post s'afegeix el problema "p" al parametre implicit si no hi estava i si ja pertanyia, es llença un error
      \cost logaritmic
    */
    void afegir_problema(const Problema& p);
    
    /** @brief Afegeix un problema al conjunt
      \pre <em>cert</em>
      \post s'afegeix el problema amb id = nom al parametre implicit si no hi estava i si ja pertanyia, es llença un error
      \cost logaritmic
    */
    void afegir_nom_problema(string nom);
    
    /** @brief Intercanvia un problema entre dos conjunts de problemes
      \pre <em>cert</em>
      \post si el problema P amb id = nom no pertany al parametre implicit es llença un excepcio, sino s'afegeix el problema P a cjt_2 i s'elimina P del parametre implicit
      \cost logaritmic
    */
    void intercanviar_problema(string nom, Cjt_problemes& cjt_2);    
    
    /** @brief Incrementa els enviaments totals d'un problema
      \pre el problema P amb id = p pertany al parametre implicit
      \post el problema P passa a tenir e_totals inicials + 1 
      \cost constant
    */
    void incrementar_envio(string p);
    
    /** @brief Incrementa els enviaments correctes d'un problema
      \pre el problema P amb id = p pertany al parametre implicit
      \post el problema P passa a tenir e_correctes inicials + 1
      \cost constant
    */
    void incrementar_correcte(string p);
    
    //Consultores
    
    /** @brief Consulta si existeix un problema al conjunt de problemes
      \pre <em>cert</em>
      \post llença un error si no hi ha un problema amb id = nom al parametre implicit
      \cost logaritmic
    */
    void existeix_problema(string nom) const;
    
    /** @brief Consulta si el conjunt de problemes conte un problema
      \pre <em>cert</em>
      \post retorna cert ci el problema amb id = nom pertany al parametre implicit
      \cost logaritmic
    */
    bool conte_problema(string nom) const;
    
    /** @brief Consulta el total de problemes del conjunt 
      \pre <em>cert</em>
      \post el resultat es el nombre total de problemes del parametre implicit
      \cost constant
    */
    int problemes_totals() const;
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt de porblemes
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre d'elements que llegirem) i les dades de tal nombre de problemes diferents
      \post el parametre implicit conte el conjunt de problemes llegits al canal estandard d'entrada
      \cost logaritmic en numero de problemes 
    */
    void llegir_problemes();
    
    /** @brief Operació d'escriptura del conjunt de problemes
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida els atributs dels problemes del parametre implicit en ordre ascendent de ratio i en cas d'empat per odre creixent d'identificador
      \cost n*log(n) on n es el total de problemes
    */
    void llistar_problemes() const;
    
    /** @brief Operació d'escriptura del conjunt de problemes
      \pre <em>cert</em>
      \post s'ha escrit pel canal estandard de sortida la id i el nombre de e_totals dels problemes del parametre implicit en odre creixent d'identificador
      \cost lineal
    */
    void enumerar_problemes() const;
    
    /** @brief Operació d'escriptura d'un problema
      \pre existeix el problema P amb id = nom al parametre implicit
      \post s'ha escrit pel canal estàndard de sortida els atributs del problema P del parametre implicit
      \cost logaritmic
    */
    void escriure_problema(string nom) const;
    
private:
    //conjunt amb la clau de id de problema i Problema
    map<string, Problema> llista_problemes;
};

#endif







