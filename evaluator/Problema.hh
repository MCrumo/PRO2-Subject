/** @file Problema.hh
    @brief Especificació de la classe Problema
*/

#ifndef PROBLEMA
#define PROBLEMA

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include "ExcepcioEvaluator.hh"
using namespace std;
#endif

/** @class Problema
    @brief Representa un problema del Evaluator.
*/

class Problema 
{
public:
    //Constructores
    
    /** @brief Creadora per defecte
        \pre <em>cert</em>
        \post el resultat es un problema sense nom
    */
    Problema();
    
    /** @brief Creadora amb valors concrets.
        \pre nom es de tipus string
        \post el resultat es un problema amb nom "nom", envios totals = 0, envios correctes = 0 i ratio = 1
    */
    Problema(string nom);
    
    //Modificadores
    
    /** @brief Modificadora de l'atribut enviaments totals
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir els enviaments totals inicials mes 1
    */
    void incrementar_envio();
    
    /** @brief Modificadora de l'atribut enviaments correctes
        \pre <em>cert</em> 
        \post el parametre implicit passa a tenir els enviaments correctes inicials mes 1
    */
    void incrementar_correctes();
    
    /** @brief Modificadora de l'atribut ratio
        \pre t i e son dos enters >= 0
        \post el parametre implicit passa a tenir ratio (t+1)/(e+1)
    */
    //void actualitzar_ratio();
    
    //Consultores
    
    //AFEGIR COMENTARIS!!!!!!!!1
    bool operator<(const Problema& p) const;

    /** @brief Consulta el nom del problema
      \pre <em>cert</em>
      \post el resultat es el nom del parametre implicit
    */
    string nom_problema() const;
    
    /** @brief Consultora el total d'enviaments
      \pre <em>cert</em>
      \post el resultat es el total d'enviaments del parametre implicit
    */
    int consul_enviats() const;
    
    /** @brief Consultora els enviaments correctes
      \pre <em>cert</em>
      \post el resultat son els enviaments correctes del parametre implicit
    */
    int consul_correctes() const;
    
    /** @brief Consultora del ratio del problema
      \pre <em>cert</em>
      \post el resultat es la ratio del parametre implicit
    */
    double consul_ratio() const;
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura de problema
      \pre hi ha preparat al canal estandard d'entrada un string
      \post El parametre implicit passa a tenir els atributs llegits del canal estandard d'entrada
    */
    void llegir_problema();
    
    /** @brief Operacio d'escriptura de problema
      \pre <em>cert</em>
      \post s'han escrit els atributs del parametre implicit al canal estandard de sortida
    */
    void escriure_problema() const;
    
private:
    string id;
    int e_totals;
    int e_correctes;
    double ratio;
    double actualitzar_ratio(int totals, int correctes);
};

#endif
