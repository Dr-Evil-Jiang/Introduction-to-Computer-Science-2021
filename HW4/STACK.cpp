//
// Created by dell on 10/31/2021.
//

#include "STACK.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

STACK::STACK(int size) {
    base = new int [size - 1];
    if (base == nullptr){
        exit(0);
    }
    top = base;
    stack_size = size;
}

STACK::~STACK() {
    delete [] base;
    top = nullptr;
}

bool STACK::is_empty() {
    return top==base;
}

bool STACK::is_full() {
    return (stack_size == (top - base));
}

void STACK::push(int item) {
    if(is_full()){
        cout<<"The stack is full, so push() is failed!"<<endl;
        exit(1);
    }
    else{
        *top = item;
        top++;
    }
}
int STACK::pop() {
    if (is_empty()){
        cout<<"The stack is empty, so the pop operation is invalid!"<<endl;
        exit(1);
    }
    else{
        top--;
        int item = *top;
        return item;
    }
}
int STACK::get_top() {
    return *(top - 1);
}