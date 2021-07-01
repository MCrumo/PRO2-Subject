#ifndef ARBRENARI_HH
#define ARBRENARI_HH

#include "utils.PRO2"

template <class T> class ArbreNari {
    
private:
    struct node_arbreNari {
        T info;
        vector<node_arbreNari*> seg;
    };
    int N;
    node_arbreNari* primer_node;
    
    static node_arbreNari* copia_node_arbreNari(node_arbreNari* m)
    /* Pre: cert */
    /* Post: el resultat és NULL si m és NULL; en cas contrari, el resultat apunta
    al node arrel d’una jerarquia de nodes que és una còpia de la
    jerarquia de nodes que té el node apuntat per m com a arrel */
    {
        node_arbreNari* n;
        if (m==NULL) n=NULL;
        else {
            n = new node_arbreNari;
            n->info = m->info;
            int N = m->seg.size();
            n->seg = vector<node_arbreNari*>(N);
            for (int i=0; i<N; ++i)
                n->seg[i] = copia_node_arbreNari(m->seg[i]);
        }
        return n;
    }
    static void esborra_node_arbreNari(node_arbreNari* m)
    /* Pre: cert */
    /* Post no fa res si m és NULL; en cas contrari, allibera espai de tots els nodes
    de la jerarquia que té el node apuntat per m com a arrel */
    {
        if (m != NULL) {
        int N = m->seg.size();
        for (int i=0; i<N; ++i)
            esborra_node_arbreNari(m->seg[i]);
            delete m;
        }
    }
    
    
    
    
    
}
