#include<iostream>
using namespace std;
#pragma once

#ifndef _SEQLIST_H_
#define _SEQLIST_H_
class SeqList {
private:
	double* data;
	int store_size;
	int length;

public:
	SeqList(int size);
	~SeqList(void);
	int list_length(void);
	double get_ele(int idx);
	void insert_ele(int pos, double val);
	void print_arr(void);
	void copy_from_arr(double* arr, int arr_length);
};
#endif



