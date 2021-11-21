#include <iostream>
#include "QUEUE.h"
#include"KMP.h"
using namespace std;

void test_KMP(void) {
    string a = "aabaac";
    string p = "aac";
    int pos = KMP(a, p);
    cout << "The main string is: " << a << endl;
    cout << "The pattern string is " << p << endl;
    cout << "The pattern string starts at "<< pos << endl;
}
void test_queue(void) {
    QUEUE my_queue;
    my_queue.enqueue(3);
    my_queue.enqueue(4);
    cout << "The queue is: " << endl;
    my_queue.prt_queue();
    int res = my_queue.dequeue();
    cout << "The deleted element is " << res << ", the rest queue is: " << endl;
    my_queue.prt_queue();
    my_queue.~QUEUE();
}

int main(){
    test_queue();
    test_KMP();
    return 0;
}