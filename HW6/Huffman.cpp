#include"Huffman.h"
#include<string>
#include<vector>

void recast_memory(HuffmanNode** memory, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (memory[j]->weight < memory[j + 1]->weight) {
				HuffmanNode* temp = memory[j];
				memory[j] = memory[j + 1];
				memory[j + 1] = temp;
			}
		}
	}
}

HuffmanNode** merge_nodes(HuffmanNode** memory, int len) {
	HuffmanNode* temp = new HuffmanNode;
	temp->left = memory[len - 1];
	temp->right = memory[len - 2];
	temp->parent = nullptr;
	temp->weight = memory[len - 1]->weight + memory[len - 2]->weight;
	memory[len - 1]->parent = temp;
	memory[len - 2]->parent = temp;
	memory[len - 1]->code = '1';
	memory[len - 2]->code = '0';

	HuffmanNode** new_memory = new HuffmanNode * [len - 1];
	for (int i = 0; i < len - 2; i++) {
		new_memory[i] = memory[i];
	}
	new_memory[len - 2] = temp;
	return new_memory;
}

void get_code(vector<string>& res, HuffmanNode* root, string t) {
	if (root->left == nullptr && root->right == nullptr) {
		res.push_back(root->key + ": ");
		res.push_back(t);
		return;
	}
	if (root->left != nullptr) get_code(res, root->left, t + "->" + (root->left->code));
	if (root->right != nullptr) get_code(res, root->right, t + "->" + (root->right->code));
}

HuffmanCoding::HuffmanCoding(string s) {
	map<char, int> freq_tab;
	for (int i = 0; i<int(s.length()); i++) {
		if (freq_tab.end() != freq_tab.find(s[i])) freq_tab[s[i]]++;
		else freq_tab.insert(pair<char, int>(s[i], 1));
	}
	map<char, int>::iterator it;
	HuffmanNode** memory = new HuffmanNode* [int(freq_tab.size())];
	int couter = 0;
	for (it = freq_tab.begin(); it != freq_tab.end(); it++) {
		HuffmanNode* temp = new HuffmanNode;
		temp->left = nullptr;
		temp->right = nullptr;
		temp->parent = nullptr;
		temp->weight = it->second;
		temp->key = it->first;
		memory[couter++] = temp;
	}
	recast_memory(memory, couter);
	//for (int i = 0; i < couter; i++) {
	//	cout << memory[i]->weight << "  ";
	//}
	//cout << "counter is: "<<couter<<endl;
	
	while (couter > 1) {
		memory = merge_nodes(memory, couter);
		couter--;
		recast_memory(memory, couter);
		//for (int i = 0; i < couter; i++) {
		//	cout << memory[i]->weight << "  ";
		//}
		//cout << "counter is: " << couter << endl;
	}

	HuffmanTree = memory[0];
	int path[200];
	int len = 0;
	vector<string> res;
	get_code(res, HuffmanTree, "");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
}


