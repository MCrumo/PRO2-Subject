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
      \post s'ha tret del parametre implicit l'usuari amb nom "nom" i en retorna el curs on estava inscrit, en cas de no existir s'ha llençat un missatge d'error
    */
    int eliminar_usuari(string nom);
    
    /** @brief Incsriu un usuari al curs c
      \pre <em>cert</em>
      \post l'usuari "u" del parametre implicit passar a estar inscrit al curs "c"
    */
    void insc_usuari_curs(const string& u, const int& c, const Cjt_cursos& cs, const Cjt_sessions& ses);
    
    //Consultores
    
    /** @brief Consulta si hi ha un cert usuari al conjunt d'usuaris
      \pre <em>cert</em>
      \post llença un error si l'usuari amb id "nom" no esta al parametre implicit
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
    //Usuari buscar_usuari(string nom);
    
    void curs_acabat(int c);
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt d'usuaris
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre d'elements que llegirem) i les dades de tal nombre d'usuaris diferents
      \post el parametre implicit conte el conjunt d'usuaris llegits del canal estandard d'entrada
    */
    void llegir_usuaris();
    
    /** @brief Operació d'escriptura del curs al que esta inscrit l'usuari "u"
      \pre <em>cert</em>
      \post s'han escrit pel canal estàndard de sortida el el curs al que esta inscrit l'usuari "u" del parametre implicit i 0 si no esta inscrit en cap curs
    */
    void escriure_curs_inscrit(string u) const ;
    
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
    
    /** @brief Operació d'escriptura dels problemes resolts d'un usuari
      \pre existeix usuari amb id "u" al parametre implicit
      \post s'han escrit pel canal estàndard de sortida el problemes resolts de l'usuari "u" del parametre implicit
    */
    void llistar_u_resolts(string u) const;
    
    /** @brief Operació d'escriptura dels problemes enviables d'un usuari
      \pre existeix usuari amb id "u" al parametre implicit
      \post s'han escrit pel canal estàndard de sortida el problemes enviables de l'usuari "u" del parametre implicit
    */
    void llistar_u_enviables(string u) const;
    
    /** @brief Operació d'escriptura d'un usuari
      \pre existeix usuari amb id "u" al parametre implicit
      \post s'han escrit pel canal estàndard de sortida els atributs de l'usuari "u" de parametre implicit
    */
    void escriure_usuari(string u) const;
    
private:
    map<string, Usuari> llista_usuaris;
};


#endif





