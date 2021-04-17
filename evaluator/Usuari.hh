/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/

#ifndef USUARI
#define USUARI

#include "Curs.hh"

/** @class Usuari
    @brief Representa un usuari del Evaluator.
*/
/*
    Conte la informació de l'usuari com ara: nom, a quins cursos està inscrit, registre de problemes resolts, quins pot enviar, nombre total d'enviaments per problema o quants jutgats com a correctes
*/

class Usuari
{
public:
    //Constructoras

    /** @brief Creadora por defecte.
    \pre <em>cert</em>
    \post el resultat es un usuari sense nom ni informacio
    */  
    Usuari();
    
    /** @brief Creadora amb valors concrets.
    \pre <em>cert</em>
    \post el resultat es un usuari amb nom "nom" i total enviaments = 0, correctes = 0, no inscrit en cap curs i sense problemes resolts
    */
    Usuari(string nom);
    
    //Modificadores
    
    /** @brief Inscriu l'usuari a un curs
      \pre existeix un curs amb nom "nom" al conjunt de cursos i l'usuari no esta inscrit a cap curs
      \post el parametre implicit passa a estar inscrit al curs amb nom "nom"
    */
    void inscriure_curs(int nom);
    
    /** @brief Modifica el nombre d'enviaments totals de l'usuari
      \pre <em>cert</em>
      \post el parametre implicit passa a tenir els enviaments totals inicials mes 1
    */
    void incrementar_totals();
    
     /** @brief Modifica els problemes correctes de l'usuari i els que pot enviar
      \pre l'usuari esta inscrit al crus on apareix el problema amb nom "nom" i ha complert els prerrequisits per enviar el problema
      \post el parametre implicit passa a tenir el problema amb nom "nom" com a correcte, el total de problemes correctes inicials mes 1 i mes problemes que podra resoldre en cas que aquest problema sigues prerrequisit d'algun altre
    */
    void afegir_correcte(string nom);
    
     /** @brief Modifica l'estat del curs en el que esta inscrit l'usuari
      \pre <em>cert</em>
      \post si l'usuari ha completat tots els problemes del curs, passa a completar el curs sino segueix inscrit al curs on estava
    */
    void actualitzar_curs();
    
    /** @brief Modifica el nombre de problemes que ha intentat resoldre
      \pre l'usuari esta inscrit al crus on apareix el problema amb nom "nom" i ha complert els prerrequisits per eniar el problema
      \post el parametre implicit passa a tenir els problemes que ha intentat resoldre inicialment mes 1 en cas que sigui el primer cop que intenta resoldre el problema amb nom "p" 
    */
    void intent_resoldre(string p);
    
    //Consultores
    
    /** @brief Consulta si l'usuari ha acabat el curs
      \pre <em>cert</em>
      \post true si l'usuari ha acabat el curs false en cas contrari
    */
    bool curs_acabat() const;
    
    /** @brief Consulta el nom de l'usuari
      \pre <em>cert</em>
      \post el resultat es el nom del parametre implicit
    */
    string nom_usuari() const;
    
    /** @brief Consulta a quin curs esta inscrit l'usuari
      \pre <em>cert</em>
      \post el resultat es el nom (enter) del curs al que esta inscrit i 0 si no esta inscrit a cap curs
    */
    int consultar_curs();
    
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
    
    /** @brief Operacio d'escriptura del curs al que esta inscrit l'usuari
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida el curs al que esta inscrit l'usuari i 0 si no esta inscrit a cap curs 
    */
    void escriure_curs_inscrit() const;
    
    /** @brief Operacio d'escriptura d'usuari
      \pre <em>cert</em>
      \post s'han escrit els atributs del parametre implicit al canal estandard de sortida
    */
    void escriure_usuari() const;
    
};


#endif















