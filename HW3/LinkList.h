#pragma once
#include<iostream>
using namespace std;
#ifndef _LINKLIST_H_
#define _LINKLIST_H_
class LinkList {
public:
	LinkList* head;
	double val;
	LinkList* next;
	LinkList(void);
	~LinkList(void);
	void add_ele(double val);
	void prt_linklist(void);
	void insert_ele(int pos, double val);
	double del_ele(int pos);
	void copy_from_arr(double* arr, int length);
};
#endif // !_LINKLIST_H_

