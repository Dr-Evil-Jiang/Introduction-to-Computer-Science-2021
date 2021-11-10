//
// Created by dell on 11/10/2021.
//
#include "QUEUE.h"
#include <iostream>
using namespace std;


QUEUE::QUEUE() {
    head = nullptr;
    tail = nullptr;
}

QUEUE::~QUEUE() {
    NODE* del_ptr = head;
    while (del_ptr != nullptr) {
        NODE* temp = del_ptr;
        del_ptr = del_ptr->next;
        free(temp);
    }
    del_ptr = nullptr;
    head = nullptr;
    tail = nullptr;
}

void QUEUE::enqueue(int val) {
    if (head == nullptr){
        head = new NODE;
        head->val = val;
        tail = head;
        tail->next = nullptr;
    }
    else{
        NODE* new_node = new NODE;
        new_node->val = val;
        tail->next = new_node;
        tail = new_node;
        tail->next = nullptr;
    }
}

int QUEUE::dequeue() {
    if (head == nullptr){
        cout<<"This queue is empty!"<<endl;
        return -1;
    }
    else{
        int res = head->val;
        NODE* del_node = head;
        head = head->next;
        free(del_node);
        return res;
    }
}

void QUEUE::prt_queue() const {
    if (head == nullptr){
        cout<<"This queue is empty!"<<endl;
        return;
    }
    else{
        NODE* prt_ptr = head;
        while (prt_ptr != nullptr){
            cout << prt_ptr->val << "<-";
            prt_ptr = prt_ptr->next;
        }
        cout << "rear" << endl;
    };
}