/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/

#ifndef USUARI
#define USUARI

#include "Cjt_cursos.hh"
#include "Cjt_problemes.hh"
#ifndef NO_DIAGRAM
#include <set>
#endif

/** @class Usuari
    @brief Representa un usuari del Evaluator.

    Conte la informació de l'usuari com ara: nom, a quins cursos està inscrit, registre de problemes resolts, quins pot enviar, nombre total d'enviaments per problema o quants jutgats com a correctes
*/

class Usuari
{
public:
    //Constructoras

    /** @brief Creadora por defecte.
    \pre <em>cert</em>
    \post el resultat es un usuari sense id, curs_inscrit = 0 i env_totals = 0
    */  
    Usuari();
    
    /** @brief Creadora amb valors concrets.
    \pre <em>cert</em>
    \post el resultat es un usuari amb id = "nom" i total enviaments = 0, correctes = 0, no inscrit en cap curs i sense problemes resolts
    */
    Usuari(string nom);
    
    //Modificadores
    
    /** @brief Inscriu l'usuari a un curs
      \pre "c" es un difentificador valid de curs
      \post el parametre implicit passa a estar inscrit al curs amb nom "c" i s'afegeix al parametre implicit els problemes que ja pot resoldre, en cas que ja estigui inscrit en algun curs s'imprimeix un missatge d'error
    */
    void inscriure_curs(const int& c, const Cjt_cursos& cs,  Cjt_sessions& cjt_s);
    
    /** @brief Modifica el nombre d'enviaments totals de l'usuari
      \pre <em>cert</em>
      \post el parametre implicit passa a tenir els enviaments totals inicials mes 1
    */
    void incrementar_totals();
    
    /** @brief Afegeix un problema intentat al parametre implicit i incrementa l'enviament al problema
    \pre <em>cert</em>
    \post afegeix el problema si no estava al parametre implicit i incrementa l'envio al problema es cas que sigui un dels podblemes enviables del parametre implicit
    */
    void inc_p_intentat(string problema);
    
    /** @brief Afegeig un enviament correcte a l'usuari
      \pre p es una id valida de problema que pot intentar l'usuari
      \post l'usuari passa a tenir els problemes resolts inicials mes "p" i problemes enviables inicials menys "p"
    */
    void envio_correcte(string p);
    
    /** @brief Afegeig un enviament correcte a l'usuari
      \pre p es una id valida de problema que pot enviar l'usuari
      \post l'usuari passa a tenir els problemes resolts inicials mes "p" i problemes enviables inicials menys "p"
    */
    void actual_enviables(string p, Cjt_sessions& ses, string s);
    
    /** @brief Desinscriu l'usuari del curs
      \pre <em>cert</em>
      \post l'usuari passa a tenir curs_inscrit = 0
    */
    void desinscriure();
    
    //Consultores
    
    /** @brief Consulta el nom de l'usuari
      \pre <em>cert</em>
      \post el resultat es el nom del parametre implicit
    */
    string nom_usuari() const;
    
    /** @brief Consulta a quin curs esta inscrit l'usuari
      \pre <em>cert</em>
      \post el resultat es el nom (enter) del curs al que esta inscrit i 0 si no esta inscrit a cap curs
    */
    int consul_curs() const;
    
    /** @brief Consulta a quin curs esta inscrit l'usuari
        \pre <em>cert</em>
        \post retorna el curs en el que esta insrict l'usuari i si no estava inscrit a cap curs llença una excepcio
    */
    int consultar_inscrit() const;
    
    /** @brief Consulta el nombre total de problemes enviables
        \pre <em>cert</em>
        \post el resultat es el total de problemes de cjt_enviables del parametre implicit
    */
    int consul_enviables() const;
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura d'un usuari
      \pre hi ha preparat al canal estandard d'entrada els seus identificadors
      \post el parametre implicit passa a tenir els atributs llegits del canal estandard d'entrada
    */
    void llegir_usuari();
    
    /** @brief Operacio d'escriptura de tots els problemes que ha resolt l'usuari
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida els problemes que ha resolt el parametre implicit en ordre ascendent d'identificador i per cada problema el nombre d'enviaments que ha fet l'usuari
    */
    void llistar_resolts() const;
    
    /** @brief Operacio d'escriptura de tots els problemes que pot enviar l'usuari
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida els problemes del parametre implicit en ordre ascendent d'identificador i per cada problema el nombre d'enviaments que ha fet l'usuari
    */
    void llistar_enviables() const;
    
    /** @brief Operacio d'escriptura d'usuari
      \pre <em>cert</em>
      \post s'han escrit els atributs del parametre implicit al canal estandard de sortida
    */
    void escriure_usuari() const;
    
private:
    string id;
    int curs_inscrit;
    int env_totals;
    //conjunt de tots els problemes intentats per l'usuari sense repeticions
    set<string> llista_intentats;
    //conjut de problemes que ha resolt l'usuari
    Cjt_problemes cjt_resolts;
    //conjunt de problemes que pot enivar l'usuari
    Cjt_problemes cjt_enviables;
    //la interseccio entre el cjt_resolts i el cjt_enviables ha de ser buida
};

#endif















