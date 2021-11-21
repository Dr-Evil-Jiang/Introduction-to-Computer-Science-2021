#include <iostream>
#include "BiTREE.h"

int main() {
    int inorder[] = {6, 4, 8, 7, 9, 2, 5, 1, 3};
    int postorder[] = {6, 8,9, 7, 4, 5, 2, 3, 1};
    //BiTREE my_tree = BiTREE(inorder, postorder, 9);
    BiTREE my_tree = BiTREE();
    return 0;
}
