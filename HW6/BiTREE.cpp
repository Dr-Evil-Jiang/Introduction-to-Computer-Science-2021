//
// Created by dell on 11/12/2021.
//

#include "BiTREE.h"
#include<iostream>
#include<stack>
using namespace std;

BiTREE::BiTREE(int* inorder_traverse, int* postorder_traverse, int num_ele){
    in = inorder_traverse;
    post = postorder_traverse;
    root = restore_tree(0, num_ele - 1, 0, num_ele - 1);
    return;
};


BiTREE::~BiTREE(){
    ;
}

TreeNode* BiTREE::restore_tree(int postL, int postR, int inL, int inR)
{
	if (postL > postR) {
		return NULL;
	}
	TreeNode* root = new TreeNode;
	root->val = post[postR];
	int i;
	for (i = inL; i <= inR; i++) {
		if (in[i] == post[postR]) {
			break;
		}
	}
	int numLeft;
	numLeft = i - inL;
	root->left = restore_tree(postL, postL + numLeft - 1, inL, i - 1);  
	root->right = restore_tree(postL + numLeft, postR - 1, i + 1, inR);

	return root;
}

void BiTREE::in_order(void) {
	stack<TreeNode*> s;
	TreeNode* p = root;
	while (p != nullptr || !s.empty()) {
		while (p != nullptr) {
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();
			cout << p->val << " ";
			s.pop();
			p = p->right;
		}
	
	}
	cout << endl;

}