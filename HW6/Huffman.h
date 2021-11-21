#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;

#ifndef HW6_HUFFMANTREE_H
#define HW6_HUFFMANTREE_H
class HuffmanNode {
public:
	char code;
	int weight;
	string key; // which belongs to the last layer of the Huffman tree.
	HuffmanNode *left, *right, *parent;
};

class HuffmanCoding {
public:
	HuffmanCoding(string s);
	~HuffmanCoding() { ; };

	

private:
	HuffmanNode* HuffmanTree;
};


#endif //HW6_HUFFMANTREE_H
