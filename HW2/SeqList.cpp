#include<iostream>
#include"SeqList.h"
using namespace std;

SeqList::SeqList(int size) {
	store_size = size;
	data = new double[store_size];
	length = 0;
}

SeqList::~SeqList(void) {
	delete[] data;
	data = NULL;
}

int SeqList::list_length(void) {
	return length;
}

double SeqList::get_ele(int idx) {
	if (idx < 0 || idx >= store_size) {
		throw "The indice is unavailiable!";
	}
	else {
		return data[idx];
	}
}

void SeqList::insert_ele(int pos, double val) {
	if (pos < 0 || pos > length) {
		throw"The indice is unavailable!";
	}
	else {
		for (int i = length - 1; i >= pos; i--) {
			data[i + 1] = data[i];
		}
		data[pos] = val;
		length++;
	}
}
void SeqList::print_arr(void) {
	for (int i = 0; i < length - 1; i++) {
		cout << data[i]<<',';
	}
	cout << data[length - 1] << endl;
}

void SeqList::copy_from_arr(double* arr, int arr_length) {
	if (arr_length > store_size) {
		throw"The input array is too long!";
	}
	else {
		for (int i = 0; i < arr_length; i++) {
			insert_ele(i, arr[i]);
		}
	}
}