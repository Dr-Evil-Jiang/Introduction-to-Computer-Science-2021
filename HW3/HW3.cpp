
#include <iostream>
#include"LinkList.h"
#include"DualLinkList.h"

// Implementation of algorithm 2.10
// this algorithm is implemented in LinkList::del_ele(int pos)
void test_2_10() {
	double la[] = { 3, 5, 8, 11 };
	double lb[] = { 2, 6, 8, 9, 11, 15, 20 };
	LinkList* LA = new LinkList();
	LA->copy_from_arr(la, int(sizeof(la) / sizeof(la[0])));
	cout << "LA is :" << endl;
	LA->prt_linklist();
	cout << "The position to be deleted is " << 3 << ", the first position is 0. " << endl;
	LA->del_ele(3);
	cout << "LA is: " << endl;
	LA->prt_linklist();
	return;
}
// Implementation of algorithm 2.11
void MergeListLink(LinkList* LA, LinkList* LB, LinkList* LC) {
	LinkList* la_ptr = LA->head;
	LinkList* lb_ptr = LB->head;
	LinkList* lc_ptr = nullptr;
	if (la_ptr->val >= lb_ptr->val) {
		LC->head = lb_ptr;
		lb_ptr = lb_ptr->next;
		lc_ptr = LC->head;
		lc_ptr->next = la_ptr;
	}
	else {
		LC->head = la_ptr;
		la_ptr = la_ptr->next;
		lc_ptr = LC->head;
		lc_ptr->next = lb_ptr;
	}
	while ((la_ptr != nullptr) && (lb_ptr != nullptr)) {
		if (la_ptr->val >= lb_ptr->val) {
			lc_ptr->next = lb_ptr;
			lb_ptr = lb_ptr->next;
			lc_ptr = lc_ptr->next;
			lc_ptr->next = la_ptr;
			la_ptr = la_ptr->next;
			lc_ptr = lc_ptr->next;
		}
		else {
			lc_ptr->next = la_ptr;
			la_ptr = la_ptr->next;
			lc_ptr = lc_ptr->next;
			lc_ptr->next = lb_ptr;
			lb_ptr = lb_ptr->next;
			lc_ptr = lc_ptr->next;
		}
	}
	if (la_ptr == nullptr) {
		lc_ptr->next = lb_ptr;
	}
	else {
		lc_ptr->next = la_ptr;
	}
}

void test_2_11() {
	double la[] = { 3, 5, 8, 11 };
	double lb[] = { 2, 6, 8, 9, 11, 15, 20 };
	LinkList* LA = new LinkList();
	LinkList* LB = new LinkList();
	LA->copy_from_arr(la, int(sizeof(la) / sizeof(la[0])));
	LB->copy_from_arr(lb, int(sizeof(lb) / sizeof(lb[0])));

	cout << "LA is :" << endl;
	LA->prt_linklist();
	cout << "LB is :" << endl;
	LB->prt_linklist();
	// Test for 2.12
	LinkList* LC = new LinkList();
	MergeListLink(LA, LB, LC);
	cout << "LC is :" << endl;
	LC->prt_linklist();
}
// Implementation of algorithm 2.19
// this algorithm is implemented in DualLinkList::del_ele(int pos)
void test_2_19() {
	double la[] = { 3, 5, 8, 11 };
	Dual_LinkList* my_list = new Dual_LinkList();
	my_list->copy_from_arr(la, int(sizeof(la) / sizeof(la[0])));
	cout << "LA is :" << endl;
	my_list->prt_duallinklist();
	cout << "The position to be deleted is " << 3 << ", the first position is 0. " << endl;
	my_list->del_ele(3);
	cout << "LA is :" << endl;
	my_list->prt_duallinklist();
}
int main()
{
	cout << "Test for 2.10: " << endl;
	test_2_10();
	cout << endl;
	cout << "Test for 2.11: " << endl;
	test_2_11();
	cout << endl;
	cout << "Test for 2.19: " << endl;
	test_2_19();

}
