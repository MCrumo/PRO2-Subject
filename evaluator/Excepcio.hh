/** @file Excepcio.hh
    @brief Especificació de la classe Excepcio
*/

#ifndef EXCEPCIO
#define EXCEPCIO

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Excepcio
    @brief Representa els errors del Evaluator
    
    Totes les operacions son de <b>cost constant</b>
*/

class Excepcio
{
public:
    //Constructores
    
    Excepcio();
    
    //Escriptura
    
    /** @brief Operacio d'escriptura d'errors: el problema ja existeix
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_p1() const;
    
    /** @brief Operacio d'escriptura d'errors: problemes repetits
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_p2() const;
    
    /** @brief Operacio d'escriptura d'errors: el problema no existeix
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_p3() const;
    
    /** @brief Operacio d'escriptura d'errors: la sessio ja existeix
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_s1() const;
    
    /** @brief Operacio d'escriptura d'errors: la sessio no existeix
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_s2() const;
    
    /** @brief Operacio d'escriptura d'errors: el curs no existeix
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_c1() const;
    
    /** @brief Operacio d'escriptura d'errors: el curs no conte el problema
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_c2() const;
    
    /** @brief Operacio d'escriptura d'errors: usuaris repetits
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_u1() const;
    
    /** @brief Operacio d'escriptura d'errors: usuari no existeix
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_u2() const;
    
    /** @brief Operacio d'escriptura d'errors: l'usuari no ha acabat el curs
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_u3() const;
    
    /** @brief Operacio d'escriptura d'errors: usuari no inscrit
        \pre <em>cert</em>
        \post s'ha escrit pel canal estandar de sortida l'error
    */
    void throw_u4() const;
};

#endif
