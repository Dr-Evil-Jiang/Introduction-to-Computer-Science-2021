#include <iostream>
#include "BiTREE.h"
#include"Huffman.h"
using namespace std;

void test_pre_traverse() {
    cout << "The preorder traverse of the tree is :" << endl;
    int inorder[] = { 6, 4, 8, 7, 9, 2, 5, 1, 3 };
    int postorder[] = { 6, 8 ,9, 7, 4, 5, 2, 3, 1 };
    BiTREE my_tree = BiTREE(inorder, postorder, 9);
    my_tree.in_order();
    return;
}

void test_huffman() {
    cout << "Huffman code:" << endl;
    HuffmanCoding tree = HuffmanCoding("111234541598");
}

int main() {
    test_pre_traverse();
    test_huffman();
}