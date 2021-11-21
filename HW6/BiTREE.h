//
// Created by dell on 11/12/2021.
//

#ifndef HW6_BITREE_H
#define HW6_BITREE_H
class TreeNode{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

class BiTREE {
public:
    TreeNode* root;
    BiTREE(int* inorder_traverse, int* postorder_traverse, int num_ele);
    ~BiTREE();
    void in_order(); // Implementation of an unrecurrsive method for inorder transverse.
private:
    int* post;
    int* in;
    TreeNode* restore_tree(int postL, int postR, int inL, int inR);
};


#endif //HW6_BITREE_H
