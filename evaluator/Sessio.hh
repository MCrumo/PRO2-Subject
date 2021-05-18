/** @file Sessio.hh
    @brief Especificació de la classe Sessio
*/

#ifndef SESSIO
#define SESSIO

#include "Cjt_problemes.hh"
#include "BinTree.hh"
#ifndef NO_DIAGRAM
#include "Problema.hh"
#include <iostream>
#include <vector>
using namespace std;
#endif

/** @class Sessio
    @brief Representa una sessió del Evaluator.
    
    Conté un subconjut de problemes de la colecció de problemes.
    Cada sessió té un nom que la identifica (string) i està formada per un sub-conjunt de problemes diferents de la col·lecció estructurats segons unes relacions de prerequisit. A cada sessió hi ha un problema bàsic inicial que s'ha de resoldre abans que la resta de problemes de la mateixa sessió. Els problemes d'una sessió poden ser prerequisit directe de 0, 1 o 2 problemes de la mateixa sessió, i cada problema, excepte el bàsic inicial, té un únic problema que és prerequsito directe d'ell.
*/

class Sessio
{
public:
    //Constructores
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post el resultat es una sessio sense nom i sense problemes
        \cost constant
    */
    Sessio();
    
    /** @brief Creadora amb valors concrets.
        \pre <em>cert</em>
        \post el resultat es una sessio amb id = nom i sense problemes
        \cost constant
    */
    Sessio(string nom);
    
    //Modificadores
    
    /** @brief Afegeix els seguents problemes que podra enviar l'usuari
        \pre llr (llista resolts) es un conjunt de problemes al igual que lle (llista enviables) i el problema amb id = nom, pertany al parametre implicit
        \post lle passa a tenir els probemes PP (on 0 <= PP <= 2) dels quals el problema amb id = nom es el seu prerrequisit mes proxim que no pertany a llr
    */
    void actual_problemes(string nom, const Cjt_problemes& llr, Cjt_problemes& lle);
    
    /** @brief Afegeix els problemes inicials que pot enviar l'usuari just despres d'inscriure's a un curs
        \pre llr (llista resolts) es un conjunt de problemes al igual que lle (llista enviables)
        \post lle conte els problemes que no son prerreqisit de cap altre (o be perque son el problema inicial o be perque ja pertany a llr)
    */
    void afegir_enviables(const Cjt_problemes& llr, Cjt_problemes& lle);
    
    //Consultores
    
    /** @brief Consulta el nom de la sessio
      \pre <em>cert</em>
      \post el resultat es la id del parametre implicit
      \cost constant
    */
    string nom_sessio() const;
    
    /** @brief Consulta el nombre de problemes del curs
      \pre <em>cert</em>
      \post el resultat es el nombre total de problemes del parametre implicit
      \cost constant
    */
    int total_problemes() const;
    
    /** @brief Consulta el nom dels problemes de la sessio
      \pre 0 <= i < el tamany de la llista de problemes
      \post el resultat es el nom del problema a la iessima possicio
      \cost constant
    */
    string consul_iessim(int i) const;
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura dels problemes de la sessio
      \pre hi ha preparat al canal estandard d'entrada una sequencia d'identificadors de problemes en preordre
      \post el parametre implicit passa a tenir els atributs llegits al canal estandard d'entrada
    */
    void llegir_p_sessio();
    
    /** @brief Operacio d'escriptura de sessio
      \pre <em>cert</em>
      \post s'han escrit tots els atributs del parametre implicit al canal estandard de sortida
    */
    void escriure_sessio() const;

private:
    string id;
    //identificadors dels problemes amb la seva estructura de prerrequisits
    BinTree<string> problemes_sessio;
    //identificadors dels problemes que conte la sessio
    vector<string> llista_problemes;
    //metodes estatics que treballen amb BinTrees
    void llegir_preordre(BinTree<string>& t);
    static void escriure_postordre(const BinTree<string>& t);
    static void buscar_prerequisits(const BinTree<string>& a, const Cjt_problemes& llr, Cjt_problemes& lle, string p, bool& cond);
    static void afegir_prerequisits(const BinTree<string>& a, const Cjt_problemes& llr, Cjt_problemes& lle);
};

#endif
