/** @file Cjt_cursos.hh
    @brief Especificació de la classe Cjt_cursos
*/

#ifndef CJT_CURSOS
#define CJT_CURSOS

#include "Curs.hh"

/** @class Cjt_cursos
    @brief Representa el conjunt de cursos del Evaluator.
*/

class Cjt_cursos
{
public:
    //Constructores
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post el resultat es un conjunt de cursos buit
    */
    Cjt_cursos();
    
    //Modificadores
    
    /** @brief Afegeix el curs c al conjunt de cursos
      \pre el parametre implicit no conte cap curs amb l'identificador de c
      \post s'ha afegit el curs c al parametre implicit
    */
    void afegir_curs(const Curs& c);
    
    /** @brief Incrementa el total d'usuaris inscrits al curs "c" del parametre implicit
      \pre <em>cert</em>
      \post el total d'usuaris inscrits al curs "c" del parametre implicit augmenta en 1
    */
    void curs_inc_usuari(int u);
    
    /** @brief Modifica els usuaris del curs c
      \pre <em>cert</em>
      \post decrementa les usuaris inscrits de c si l'identificador es valid
    */
    void actual_usuaris(int c);
    
    //Consultores
    
    /** @brief Consulta si hi ha un cert curs al conjunt de cursos
      \pre l'identificador de curs es de tipus enter
      \post llença un error si el curs amb id "nom" no existeix
    */
    void existeix_curs(int nom);
    
    /** @brief Consulta el numero total de cursos del conjunt
      \pre <em>cert</em>
      \post el resultat es el numero total de cursos del parametre implicit
    */
    int total_cursos() const;
    
    /** @brief Consulta el curs amb identificador "nom"
      \pre el parametre implicit conte un curs amb nom "nom"
      \post el resultat es el curs amb nom "nom" que conte el parametre implicit
    */
    Curs buscar_curs(int nom);
    
    /** @brief Consulta les sessions d'un curs
      \pre el curs "c" pertany al parametre implicit
      \post s'ha retornat una llista de les sessions del curs "c"
    */
    vector<string> consul_c_sessions(int c);
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt de cursos
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre d'elements que llegirem) i les dades de tal nombre de cursos diferents
      \post el parametre implicit conte el conjunt de cursos llegits del canal estandard d'entrada
    */
    void llegir_cursos();
    
    /** @brief Operació d'escriptura del total de cursos
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida el total de cursos del parametre implicit
    */
    void escriure_cursos() const;
    
    /** @brief Operació d'escriptura de tots els cursos
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida els cursos del parametre implicit en ordre ascendent d'identificador
    */
    void llistar_cursos() const;
    
private:
    vector<Curs> llista_cursos;
};

#endif








