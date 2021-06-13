#ifndef PILA
#define PILA

#include "utils.PRO2"


template <class T> class Pila {

private:
  struct node_pila {
    T info;
    node_pila* seguent;
  };

  int altura;
  node_pila* primer_node;


static void esborra_node_pila(node_pila* m)
    /* Pre: cert */
    /* Post: no fa res si m �s NULL, en cas contrari, allibera espai
       dels nodes de la cadena que t� el node apuntat per m com a
       primer */
  {
    if (m != NULL) {
      esborra_node_pila(m->seguent);
      delete m;
    }
  }

 void esborra_node_pila_it(node_pila* m){
    while(m!=NULL){
      node_pila* n=m->seguent;
      delete m;
      m=n;
    }
  }

public:

  Pila()
    /* Pre: cert */
    /* Post: El resultat �s una pila sense cap element */
  {
    altura= 0;
    primer_node= NULL;
  }


  Pila(const Pila& original)
    /* Pre: cert */
    /* Post: El resultat �s una c�pia d'original */
  {
    altura= original.altura;
    primer_node = copia_node_pila_it(original.primer_node);
  }


  ~Pila()
    // Destructora: Esborra autom�ticament els objectes locals en
    // sortir d'un �mbit de visibilitat
  {
    esborra_node_pila_it(primer_node);
  }


  void p_buida()
    /* Pre: cert */
    /* Post: El p.i. passa a ser una pila sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
{
    esborra_node_pila_it(primer_node);
    altura= 0;
    primer_node= NULL;
  }

  void empilar (const T& x)
    /* Pre: cert */
    /* Post: El p.i. �s com el p.i. original amb x afegit
       com a darrer element */
  {
    node_pila* aux;
    aux= new node_pila; // reserva espai pel nou element
    aux->info= x;
    aux->seguent= primer_node;
    primer_node= aux;
    ++altura;
  }

  void desempilar ()
    /* Pre: el p.i. �s una pila no buida (<=> primer_node != NULL) */
    /* Post: El p.i. �s com el p.i. original per� sense el darrer
       element afegit al p.i. original */
  {
    node_pila* aux;
    aux= primer_node; // conserva l'acc�s al primer node abans
    //   d'avan�ar
    primer_node= primer_node->seguent; // avan�a
    delete aux; // allibera l'espai de l'antic cim
    --altura;
  }

  T cim() const
    /* Pre: el p.i. �s una pila no buida (<=> primer_node != NULL) */
    /* Post: el resultat �s el darrer element afegit al p.i. */
  {
    return primer_node->info;
  }

  bool es_buida() const
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. �s una pila buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const
    /* Pre: cert */
    /* Post: El resultat �s el nombre d'elements del p.i. */
  {
    return altura;
  }
  
  // Input Output
  void llegir_pila_int(Pila<int> &p, int marca)
{
  int n;
  cin >> n;
  while (n != marca){
    p.empilar(n);
    cin >> n;
  }
}

void escriure_pila_int(const Pila<int> &p)
{
  cout << "[Cim] " << endl;
  Pila<int> copia(p); // copiamos p para que no se destruya y no tener
  while(not copia.es_buida()){ //que acordarnos de copiarla fuera
    cout << copia.cim() << endl;
    copia.desempilar(); // el que no haya salto de linea solo interesa
  }                   // si la pila no es muy grande
  cout << "[Ultim]"<<endl;
}

 #include "program.hh"
};

#endif
