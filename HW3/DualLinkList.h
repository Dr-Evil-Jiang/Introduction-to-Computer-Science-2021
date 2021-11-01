#pragma once
#ifndef _DUAL_LINKLIST_H_

#define _DUAL_LINKLIST_H_
class Dual_LinkList {
private:
	Dual_LinkList* head;
	Dual_LinkList* prior;
	Dual_LinkList* next;
	double val;
public:
	Dual_LinkList();
	~Dual_LinkList();
	void insert_ele(int pos, double val);
	void prt_duallinklist();
	void copy_from_arr(double* arr, int length);
	void del_ele(int pos);
};

#endif // !_DUAL_LINKLIST_H_
