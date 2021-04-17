/** @file Cjt_usuaris.hh
    @brief Especificació de la classe Cjt_usuaris
*/

#ifndef CJT_USUARIS
#define CJT_USUARIS

#include "Usuari.hh"

/** @class Cjt_usuaris
    @brief Representa el conjunt d'usuaris del Evaluator.
*/

class Cjt_usuaris
{
public:
    //Constructores
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post El resultat es un conjunt d'usuaris buit
    */
    Cjt_usuaris();
    
    //Modificadores
    
    /** @brief Afegeix un usuari al conjunt d'usuaris
      \pre el parametre implicit no conte cap usuari amb l'identificador de u
      \post s'ha afegit l'usuari u al parametre implicit
    */
    void afegir_usuari(const Usuari& u);
    
    /** @brief Elimina un usuari del conjunt d'usuaris
      \pre el parametre implicit conte un usuari amb l'identificador "nom"
      \post s'ha tret del parametre implicit l'usuari amb nom "nom"
    */
    void eliminar_usuari(string nom);
    
    //Consultores
    
    /** @brief Consulta si hi ha un cert usuari al conjunt d'usuaris
      \pre <em>cert</em>
      \post retorna ture si hi ha un usuari amb aquell identificador i false en cas contrari
    */
    bool existeix_usuari(string nom);
    
    /** @brief Consulta el total d'usuaris del conjunt
      \pre <em>cert</em>
      \post retorna un enter que representa el total d'usuaris del parametre implicit
    */
    int total_usuaris();
    
    /** @brief Consulta l'usuari amb nom "nom"
      \pre el parametre implicit conte un usuari amb nom "nom"
      \post el resultat es l'usuari amb nom "nom" que conte el parametre implicit
    */
    Usuari buscar_usuari(string nom);
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt d'usuaris
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre d'elements que llegirem) i les dades de tal nombre d'usuaris diferents
      \post el parametre implicit conte el conjunt d'usuaris llegits del canal estandard d'entrada
    */
    void llegir_usuaris();
    
    /** @brief Operació d'escriptura del total d'usuaris
      \pre <em>cert</em>
      \post s'han escrit pel canal estàndard de sortida el total d'usuaris del parametre implicit
    */
    void escriure_total_usuaris() const;
    
    /** @brief Operació d'escriptura de tots els usuaris
      \pre <em>cert</em>
      \post s'han escrit pel canal estàndard de sortida els usuaris del parametre implicit en ordre ascendent d'identificador
    */
    void llistar_usuaris() const;
};


#endif




