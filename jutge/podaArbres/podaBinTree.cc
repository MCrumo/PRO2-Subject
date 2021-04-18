#include <iostream>
#include "BinTree.hh"

using namespace std;

bool poda_subarbre(BinTree<int> &a, int x) {
    if (a.empty()) return false;
    else {
        if (a.value() == x) {
            a = BinTree<int>();
            return true;
        }
        else {
            BinTree<int> a1(a.left(), a2(a.right());
            bool b;
            b = poda_subarbre(a1, x);
            if (not b) {
                b = poda_subarbre(a2, x);
            }
        }
        a = BinTree<int>(a.value, a1, a2);
        return b;
    }
}
