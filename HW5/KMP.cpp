#include"KMP.h"
#include"string.h"
#include<iostream>
using namespace std;

int bf_algorithm(string s, string p) {
	if (s.length() < p.length()) {
		cout << "Not matching!" << endl;
		return -1;
	}
	int j = 0;
	for (int i = 0; i < int(s.length()); i++) {
		if (s[i] == p[j]) {
			if (j == (p.length() - 1)) {
				return i-j;
			}
			j++;
			continue;
		}
		else {
			j = 0;
			continue;
		}
	}
	return -1;
}

void get_next(string p, int *next) {
	// Initializing the first value
	next[0] = -1; // Since in this case, the prefix and postfix have no overlapping;
	int l_ptr = -1;
	int r_ptr = 0;
	while (r_ptr < int(p.length())) {
		if (l_ptr == -1 || p[l_ptr] == p[r_ptr]) {
			l_ptr++;
			r_ptr++;
			next[r_ptr] = l_ptr;
		}
		else {
			l_ptr = next[l_ptr];
		}
	}
	return;
}
void get_next_p(string p, int *next) {
	next[0] = -1;
	int l_ptr = -1, r_ptr = 0;
	while (r_ptr < int(p.length())) {
		if (l_ptr == -1 || p[l_ptr] == p[r_ptr]) {
			l_ptr++;
			r_ptr++;
			if (p[l_ptr] != p[r_ptr]) {
				next[r_ptr] = l_ptr;
			}
			else {
				next[r_ptr] = next[l_ptr];
			}
		}
		else {
			l_ptr = next[l_ptr];
		}
	}
	return;

}

void prt_next(int *next, int next_len) {
	cout << "Next array is :" << endl;
	for (int i = 0; i < next_len; i++) {
		cout << next[i]<<" ";
	}
	cout << endl;
}

int KMP(string s, string p) {
	int i = 0, j = 0;
	int* next = new int[p.length()];
	get_next(p, next);
	prt_next(next, p.length());
	while (i < int(s.length()) && j < int(p.length())) {
		if (j == -1 || s[i] == p[j] ) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j >= int(p.length())) {
		return (i - int(p.length()));
	}
	else {
		return -1;
	}

}

