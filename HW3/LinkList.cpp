#include<iostream>
#include"LinkList.h"
using namespace std;

LinkList::LinkList(void) {
	head = nullptr;
}

LinkList::~LinkList(void) {
	LinkList* curr_ptr = nullptr;
	LinkList* temp_ptr = nullptr;
	curr_ptr = temp_ptr = head;

	while (curr_ptr != nullptr) {
		temp_ptr = curr_ptr->next;
		free(curr_ptr);
		curr_ptr = temp_ptr;
	}

}
void LinkList::add_ele(double val) {
	LinkList* ptr = nullptr;
	ptr = head;
	if (head == nullptr) {
		LinkList* node = new LinkList();
		node->val = val;
		node->next = nullptr;
		head = node;
		return;
	}

	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	LinkList* node = new LinkList();
	node->val = val;
	node->next = nullptr;
	ptr->next = node;
}

void LinkList::prt_linklist(void) {
	LinkList* ptr = nullptr;
	ptr = head;
	cout << "val: ";
	while (ptr != nullptr) {
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout <<"null"<< endl;
}

void LinkList::insert_ele(int pos, double val) {
	if (head == nullptr) {
		if (pos == 0) {
			LinkList* node = new LinkList();
			node->val = val;
			node->next = nullptr;
			head = node;
			return;
		}
		else {
			throw "Something Wrong with postion";
			return;
		}
	}
	LinkList* ptr = head;
	int i = 0;
	while (ptr != nullptr) {
		if (i == pos - 1) {
			LinkList* node = new LinkList();
			node->val = val;
			LinkList* temp = ptr->next;
			ptr->next = node;
			node->next = temp;
			return;
		}
		i++;
		ptr = ptr->next;
	}

}
double LinkList::del_ele(int pos) {
	LinkList* ptr = head;
	int i = 0;
	if (head == nullptr) {
		return -1;
	}
	if (pos == 0) {
		LinkList* temp = head;
		head = temp->next;
		double val = temp->val;
		free(temp);
		return val;
	}

	while (ptr != nullptr) {
		if (i == pos - 1) {
			LinkList* temp = ptr->next;
			ptr->next = temp->next;
			double val = temp->val;
			free(temp);
			return val;
		}
		i++;
		ptr = ptr->next;
	}
	return -1;
}

void LinkList::copy_from_arr(double* arr, int length) {
	for (int i = 0; i < length; i++) {
		add_ele(arr[i]);
	}
}