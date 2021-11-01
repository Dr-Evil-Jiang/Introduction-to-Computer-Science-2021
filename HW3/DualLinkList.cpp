#include<iostream>
#include"DualLinkList.h"
using namespace std;

Dual_LinkList::Dual_LinkList(void) {
	head = nullptr;
};

Dual_LinkList::~Dual_LinkList() {
	return;
}

void Dual_LinkList::insert_ele(int pos, double val) {
	if (pos == 0) {
		Dual_LinkList* node = new Dual_LinkList();
		node->val = val;
		node->next = head;
		node->prior = nullptr;
		head = node;
	}
	else {
		Dual_LinkList* ptr = head;
		int i = 1;
		while (i != pos) {
			ptr = ptr->next;
			++i;
		}
		Dual_LinkList* node = new Dual_LinkList();
		node->val = val;
		node->next = ptr->next;
		node->prior = ptr;
		ptr->next = node;
	}
}
void Dual_LinkList::copy_from_arr(double* arr, int length) {
	for (int i = 0; i < length; i++) {
		insert_ele(i, arr[i]);
	}
}
void Dual_LinkList::del_ele(int pos) { 
	if (pos == 0) {
		Dual_LinkList* ptr = head;
		head = ptr->next;
		free(ptr);
	}
	else {
		Dual_LinkList* ptr = head;
		ptr = ptr->next;
		int i = 1;
		while (ptr->next != nullptr) {
			if (i == pos) {
				ptr->prior->next = ptr->next;
				ptr->next->prior = ptr->prior;
				free(ptr);
				return;
			}
			ptr = ptr->next;
			i++;
		}
		ptr->prior->next = nullptr;
		free(ptr);
	}	
}
void Dual_LinkList::prt_duallinklist() {
	Dual_LinkList* ptr = head;
	while (ptr != nullptr) {
		cout << ptr->val <<"<->";
		ptr = ptr->next;
	}
	cout << "null" << endl;
}