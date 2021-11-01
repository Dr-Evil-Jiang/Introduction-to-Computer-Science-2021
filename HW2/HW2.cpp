#include <iostream>
#include "SeqList.h"
using namespace std;


// Implementation of algorithm 2.2
void MergeList(SeqList* LA, SeqList* LB, SeqList* LC) {
	int la_len = LA->list_length();
	int lb_len = LB->list_length();
	int i = 0;
	int j = 0;
	int k = 0;

	while ((i < la_len) && (j < lb_len)) {
		double temp_a = LA->get_ele(i);
		double temp_b = LB->get_ele(j);
		if (temp_a >= temp_b) {
			LC->insert_ele(k++, temp_b);
			j++;
		}
		else {
			LC->insert_ele(k++, temp_a);
			i++;
		}
	}
	while (i < la_len) {
		LC->insert_ele(k++, LA->get_ele(i++));
	}
	while (j < lb_len) {
		LC->insert_ele(k++, LB->get_ele(j++));
	}

}

int main()
{
	double la[] = { 3, 5, 8, 11 };
	double lb[] = { 2, 6, 8, 9, 11, 15, 20 };

	SeqList* LA = new SeqList(20);
	SeqList* LB = new SeqList(20);

	LA->copy_from_arr(la, int(sizeof(la) / sizeof(la[0])));

	LB->copy_from_arr(lb, int(sizeof(lb) / sizeof(lb[0])));
	cout << "LA is :" << endl;
	LA->print_arr();
	cout << "LB is :" << endl;
	LB->print_arr();

	// Test for 2.2
	SeqList* LC = new SeqList(50);
	MergeList(LA, LB, LC);
	cout << "LC is: " << endl;
	LC->print_arr();
}

