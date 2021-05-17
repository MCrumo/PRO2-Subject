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
        \post el resultat es un problema sense nom, e_totals = 0, e_correctes = 0 i ratio = 1
        \cost constant
    */
    Problema();
    
    /** @brief Creadora amb valors concrets.
        \pre <em>cert</em>
        \post el resultat es un problema amb id = nom, e_totals = 0, e_correctes = 0 i ratio = 1
        \cost constant
    */
    Problema(string nom);
    
    //Modificadores
    
    /** @brief Modificadora de l'atribut enviaments totals
        \pre <em>cert</em>
        \post el parametre implicit passa a tenir els e_totals inicials + 1
        \cost constant
    */
    void incrementar_envio();
    
    /** @brief Modificadora de l'atribut enviaments correctes
        \pre <em>cert</em> 
        \post el parametre implicit passa a tenir els e_correctes inicials + 1
        \cost constant
    */
    void incrementar_correctes();
    
    //Consultores

    /** @brief Consulta el nom del problema
      \pre <em>cert</em>
      \post el resultat es la id del parametre implicit
      \cost constant
    */
    string nom_problema() const;
    
    /** @brief Consultora el total d'enviaments
      \pre <em>cert</em>
      \post el resultat es el e_totals del parametre implicit
      \cost constant
    */
    int consul_enviats() const;
    
    /** @brief Consultora els enviaments correctes
      \pre <em>cert</em>
      \post el resultat es el e_correctes del parametre implicit
      \cost constant
    */
    int consul_correctes() const;
    
    /** @brief Consultora del ratio del problema
      \pre <em>cert</em>
      \post el resultat es la ratio del parametre implicit
      \cost constant
    */
    double consul_ratio() const;
    
    //Lectura i escriptura
    
    /** @brief Operacio de lectura de problema
      \pre hi ha preparat al canal estandard d'entrada un string
      \post el parametre implicit passa a tenir la id llegida al canal d'entrada
      \cost constant
    */
    void llegir_problema();
    
    /** @brief Operacio d'escriptura de problema
      \pre <em>cert</em>
      \post s'han escrit els atributs del parametre implicit pel canal estandard de sortida
      \cost constant
    */
    void escriure_problema() const;
    
    //Operadors
    
    /** @brief Operacio de comparacio de dos problemes
      \pre <em>cert</em>
      \post retorna cert si la ratio del parametre implicit es menor que la ratio del problema "p" i en cas de ser iguals retorna cert si la id del parametre implicit es menor que la id del problema "p"
      \cost constant
    */
    bool operator<(const Problema& p) const;
    
private:
    string id;
    int e_totals;
    int e_correctes;
    double ratio;
    //funcio estatica que aplica la formula de la ratio d'un problema
    static double actualitzar_ratio(int totals, int correctes);
};

#endif
