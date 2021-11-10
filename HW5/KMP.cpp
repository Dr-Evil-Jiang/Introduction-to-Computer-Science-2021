#include"KMP.h"
#include"string.h"
using namespace std;

int bf_algorithm(string s, string p) {
	if (s.length() < p.length()) {
		cout << "Not matching!" << endl;
		return -1;
	}
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == p[j]) {
			if (j == (p.length() - 1)) {
				return i;
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

int KMP(string s, string p) {
	

}

int get_next(string p) {
	
	
}