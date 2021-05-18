 /** @file Cjt_sessions.hh
    @brief Especificació de la classe Cjt_sessions
*/
 
#ifndef CJT_SESSIONS
#define CJT_SESSIONS

#include "Sessio.hh" 

/** @class Cjt_sessions
    @brief Representa el conjunt de sessions de l'Evaluator.
*/

class Cjt_sessions
{
public:
    //Constructores
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post el resultat es un conjunt de sessions buit
        \cost constant
    */
    Cjt_sessions();
    
    //Modificadores
    
    /** @brief Afegeix una sessio al conjunt de sessions
      \pre <em>cert</em>
      \post si la sessio s no pertany al parametre implicit, s'afegeix la sessio s al parametre implicit i s'escriu el total de sessions, si ja hi pertanyia s'imprimeix un missatge d'error
      \cost logaritmic
    */
    void afegir_sessio(Sessio& s);
    
    /** @brief Afegeix els problemes inicials d'una sessio que pot enviar l'usuari just despres d'inscriure's a un curs
      \pre el parametre implicit conte una sessio amb id = nom_s, llr es un conjunt de problemes al igual que lle
      \post lle conte els problemes que no son prerreqisit de cap altre (o be perque son el problema inicial o be perque ja pertany a llr)
    */
    void afegir_enviables(string nom_s, const Cjt_problemes& llr, Cjt_problemes& lle);
    
    /** @brief Afegeix els seguents problemes d'una sessio que podra enviar l'usuari
      \pre llr (llista resolts) es un conjunt de problemes al igual que lle (llista enviables), el problema amb id = nom, pertany a la sessio amb id = s del parametre implicit
      \post lle passa a tenir els probemes PP (on 0 <= PP <= 2) dels quals el problema amb id = nom es el seu prerrequisit mes proxim que no pertany a llr
    */
    void actual_problemes(string s, string p, const Cjt_problemes& llr, Cjt_problemes& lle);
    
    //Consultores
    
    /** @brief Consulta si hi ha una certa sessio al conjunt de sessions
      \pre <em>cert</em>
      \post llença un error si la sessio amb id = nom no esta al parametre implicit
      \cost logaritmic
    */
    void existeix_sessio(string nom);
    
    /** @brief Consulta el problema iessim d'una sessio
      \pre 0 <= i < llista d e problemes de la sessio "s"
      \post el resultat es la id del problema iessim de la sessio amb id = nom del parametre implicit
      \cost logaritmic
    */
    string consul_p_iessim(string nom, int i) const;
    
    /** @brief Consulta el total de problemes d'una sessio
      \pre <em>cert</em>
      \post si la sessio S amb id = nom pertany al parametre implicit consulta el total de problemes de S, si no hi pertany es llença un missatge d'error
      \cost logaritmic
    */
    int total_problemes(string nom) const;
    
    //Lectura i escriptura
    
    /** @brief Operació de lectura d'un conjunt de sessions
      \pre estan preparats al canal estandard d'entrada un enter (que representa el nombre de sessions que llegirem) i les dades de tal nombre de sessions diferents
      \post el parametre implicit conte el conjunt de sessions llegits del canal estandard d'entrada
    */
    void llegir_sessions();
    
    /** @brief Operació d'escriptura del conjunt de sessions
      \pre <em>cert</em>
      \post s'han escrit pel canal estandard de sortida les sessions del parametre implicit en ordre ascendent d'id
      \cost lineal
    */
    void llistar_sessions() const;
    
    /** @brief Operació d'escriptura d'una sessio
      \pre la sessio S amb id = nom pertany al parametre implicit
      \post s'han escrit pel canal estàndard de sortida els atributs de la sessio S del parametre implicit
      \cost logaritmic
    */
    void escriure_sessio(string nom) const;
    
private:
    //conjunt indexat amb la clau id de sessio i valor Sessio
    map<string, Sessio> llista_sessions;
};
#endif

