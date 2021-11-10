#include <iostream>
#include "QUEUE.h"
#include"KMP.h"

using namespace std;
int main(){
    //QUEUE my_queue;
    //my_queue.enqueue(3);
    //my_queue.prt_queue();
    //my_queue.enqueue(4);
    //int res = my_queue.dequeue();
    //cout<<res<<endl;
    //my_queue.prt_queue();
    //my_queue.~QUEUE();
    string a = "ababxbababcadfdsss";
    string p = "abcdabd";
    cout << bf_algorithm(a, p) << endl;
    return 0;
}