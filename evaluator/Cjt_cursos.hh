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
        \cost constant
    */
    Cjt_cursos();
    
    //Modificadores
    
    /** @brief Afegeix un curs al conjunt
      \pre el parametre implicit no conte cap curs igual al curs c
      \post s'ha afegit el curs c al parametre implicit i s'escriu pel canal de sortida el total de cursos del parametre implicit
      \cost lineal
    */
    void afegir_curs(const Curs& c);
    
    /** @brief Incrementa el total d'usuaris inscrits a un curs
      \pre el curs C amb id = nom pertany al parametre implicit
      \post el total d'usuaris inscrits al curs C del parametre implicit augmenta en 1 i s'escriu pel canal estandar de sortida
      \cost constant
    */
    void curs_inc_usuari(int nom);
    
    /** @brief Decrementa en 1 els usuaris inscrits a un curs
      \pre <em>cert</em>
      \post si nom es valid, decrementa els usuaris inscrits al curs amb id = nom del parametre implicit
      \cost constant
    */
    void actual_usuaris(int nom);
    
    /** @brief Canvia els atributs del curs quan un usuari el completa
      \pre "nom" es una id valida de curs
      \post el curs amb id = nom del parametre implicit se li decrementa en 1 els usuari que l'han completat i els usuaris inscrits al curs
      \cost constant
    */    
    void curs_completat(int nom);
    
    //Consultores
    
    /** @brief Consulta si hi ha un cert curs al conjunt de cursos
      \pre <em>cert</em>
      \post llença un error si el curs amb id = nom no existeix
      \cost constant
    */
    void existeix_curs(int nom) const;
    
    /** @brief Consulta el numero total de cursos del conjunt
      \pre <em>cert</em>
      \post el resultat es el numero total de cursos del parametre implicit
      \cost constant
    */
    int total_cursos() const;
    
    /** @brief Consulta el total de sessions d'un curs
      \pre "nom" es una id valida de curs
      \post s'ha retornat el total de sessions del curs amb id = nom
      \cost constant
    */
    int total_sessions(int nom) const;
    
    /** @brief Consulta la id de la sessio que conte el problema nom_p d'un curs del conjunt
      \pre "nom" es una id valida de curs
      \post retorna la id de la sessio del curs amb id = nom del parametre implicit que conte el problema amb id = nom_p, si no hi ha cap sessio al parametre implicit que contingui el problema, s'imprimeix un missatge d'error
      \cost logaritmic
    */
    string sessio_problema(int nom, string p);
    
    /** @brief Consulta el nom de la iessima sessio d'un curs
      \pre "nom" es una id valida de curs
      \post s'ha retornat el nom de la iessima sessio del curs amb id = nom del parametre implicit
      \cost constant
    */
    string consul_c_iessim(int nom, int i) const;
    
    /** @brief Consulta els usuaris inscrits d'un curs
      \pre "nom" es una id valida de curs
      \post s'ha retornat els usuaris inscrits del curs amb id = nom del parametre implicit
      \cost constant
    */
    int usuaris_inscrits(int nom) const;
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt de cursos
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre d'elements que llegirem) i les dades de tal nombre de cursos diferents
      \post el parametre implicit conte el conjunt de cursos llegits del canal estandard d'entrada
    */
    void llegir_cursos(const Cjt_sessions& ses);
    
    /** @brief Operació d'escriptura de tots els cursos
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida els atributs dels cursos del parametre implicit en ordre ascendent d'id
      \cost lineal
    */
    void llistar_cursos() const;
    
    /** @brief Operació d'escriptura d'un curs
      \pre nom es una id valida de curs
      \post s'han escrit pel canal estàndard de sortida els atributs del curs amb id = nom del parametre implicit
      \cost constant
    */
    void escriure_curs(int nom) const;
    
private:
    //vector de Cursos sense repeticio on la id de cada curs es la seva posicio +1
    vector<Curs> llista_cursos;
};

#endif








