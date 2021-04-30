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
      \pre <em>cert</em>
      \post s'ha afegit l'usuari u al parametre implicit i en cas d'existir s'ha llençat un missatge d'error
    */
    void afegir_usuari(const Usuari& u);
    
    /** @brief Elimina un usuari del conjunt d'usuaris
      \pre string "nom"
      \post s'ha tret del parametre implicit l'usuari amb nom "nom" i en cas de no existir s'ha llençat un missatge d'error
    */
    void eliminar_usuari(string nom);
    
    /** @brief Incsriu un usuari al curs c
      \pre <em>cert</em>
      \post l'usuari "u" del parametre implicit passar a estar inscrit al curs "c"
    */
    void insc_usuari_curs(string u, const Curs& c, const Cjt_sessions& ses);
    
    //Consultores
    
    /** @brief Consulta si hi ha un cert usuari al conjunt d'usuaris
      \pre <em>cert</em>
      \post llença un error si l'usuari amb id "nom" no existeix
    */
    void existeix_usuari(string nom);
    
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
    
private:
    map<string, Usuari> llista_usuaris;
};


#endif





