    /** @file Cjt_usuaris.hh
    @brief Especificació de la classe Cjt_usuaris
*/

#ifndef CJT_USUARIS
#define CJT_USUARIS

#include "Usuari.hh"

/** @class Cjt_usuaris
    @brief Representa el conjunt d'usuaris de l'Evaluator.
    
    Els usuaris es poden donar de baixa de la plataforma, la qual cosa implicarà que es perdi tota la informació associada a aquests usuaris.
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
      \pre <em>cert</em>
      \post s'ha tret del parametre implicit l'usuari amb nom "nom" i en retorna el curs on estava inscrit, en cas de no existir s'ha llençat un missatge d'error
    */
    int eliminar_usuari(string nom);
    
    /** @brief Incsriu un usuari al curs c
      \pre u es una id valida d'usuari i c es una id valida de curs
      \post l'usuari amb id = "u" del parametre implicit passar a estar inscrit al curs amb id = "c"
    */
    void insc_usuari_curs(string u, int c, const Cjt_cursos& cs, Cjt_sessions& ses);
    
    /** @brief Afegeix un nou enviament a un usuari
      \pre l'usuari "u" pertany al parametre implicit
      \post l'usuari "u" passa a tenir els enviaments totals inicials mes 1
    */
    void inc_env_totals(string u);
    
    /** @brief Afegeix un nou problema intentat a un usuari
      \pre l'usuari "u" pertany al parametre implicit i "p" al conjunt de problemes que "u" pot fer un enviament
      \post l'usuari "u" passa a tenir els problemes intentats inicials mes "p" (en cas que encara no l'hagues intentat)
    */
    void inc_p_intentat(string u, string p);
    
    /** @brief Afegeig un enviament correcte a un usuari
      \pre l'usuari "u" pertany al parametre implicit i "p" al conjunt de problemes que "u" pot fer un enviament
      \post l'usuari "u" passa a tenir els problemes correctes inicials mes "p"
    */
    void envio_correcte(string u, string p);
    
    /** @brief Actualitza el problemes enviables d'un l'usuari
      \pre u es una id valida d'usuari, p pertany al a nom_s i nom_s pertany a ses
      \post l'usuari amb id = u passa a tenir els següents problemes enviables que son prerrequisit de p i que encara no ha resolt
    */
    void actual_enviables(string u, string p, Cjt_sessions& ses, string nom_s);
    
    /** @brief Mira si un usuari ha acabat el curs
      \pre u es una id valida d'usuari
      \post si el problemes enviables de l'usuari del parametre implicit son nul, l'usuari passa a acabar el curs i pertant c_inscrit = 0
    */
    void actual_curs_insc(string u, Cjt_cursos& cs);
    
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
    
    /** @brief Consulta el curs inscrit d'un usuari
      \pre u es una id valida d'usuari
      \post retorna el c_inscrit l'usuari amb id = u del parametre implicit
    */
    int consul_curs(string u);
    
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
      \post s'han escrit pel canal estàndard de sortida els atributs de l'usuari "u" del parametre implicit
    */
    void escriure_usuari(string u) const;
    
private:
    //conjunt indexat amb la clau de id d'usuari i amb valor Usuari
    map<string, Usuari> llista_usuaris;
};


#endif





