#ifndef EXCEPCIO_EVALUATOR
#define EXCEPCIO_EVALUATOR

#ifndef NO_DIAGRAM
#include <exception>
#endif

using namespace std;

// Classe ExcepcioEvaluator
class ExcepcioEvaluator: public exception 
{
public:
    ExcepcioEvaluator(const char* frase) : exception(), missatge(frase) {}
    const char* what() const throw() {return missatge;};
    
private:
    const char* missatge;
};

#endif
//there is no .cc
//pararà quan llença l'error encara que fagi: "catch" ?¿
