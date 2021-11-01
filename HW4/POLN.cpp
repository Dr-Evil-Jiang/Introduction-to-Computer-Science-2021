//
// Created by dell on 10/30/2021.
//
#include <cstdlib>
#include "POLN.h"
#include <iostream>
using namespace std;

POLN::POLN() {
    head = nullptr;
    length = 0;
}


void POLN::add_item(node *item) {
    if (head == nullptr){
        head = item;
        head->next = nullptr;
        length++;
    }
    else{
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = item;
        temp->next->next = nullptr;
        length++;
    }
}
void POLN::init_from_arr(double* coef, int coeff_len, int* expon, int expon_len) {
    if (coeff_len != expon_len){
        exit(0); //
    }
    for(int i = 0; i < coeff_len; i++){
        node* temp = new node;
        temp->expon = expon[i];
        temp->coef = coef[i];
        add_item(temp);
    }
}

void POLN::prt_poly() {
    node* temp = head;
    cout<<temp->coef<<"X^"<<temp->expon;
    temp = temp->next;
    for(int i = 1; i<length; i++){
        cout<<" + "<<temp->coef<<"X^"<<temp->expon;
        temp = temp->next;
    }
    cout<<endl;
}
void POLN::get_length() {
    cout<<"The length is "<<length<<'. '<<endl;
}

int POLN::cmp(node *p, node *q) {
    if (p->expon == q->expon){
        return 0;
    }
    else if(p->expon < q->expon) {
        return 1;
    }
    else{
        return -1;
    }
}

void POLN::add_poln(POLN a, POLN b) {
    node* ptr_1 = a.head;
    node* ptr_2 = b.head;
    while(ptr_1 != nullptr && ptr_2 != nullptr){
        switch(cmp(ptr_1, ptr_2)){
            case -1: // ptr_1 is larger!
            {
                add_item(ptr_1);
                ptr_1 = ptr_1->next;
                break;
            }
            case 0: // Equal
            {
                double sum = ptr_1->coef + ptr_2->coef;
                if (sum != 0.0){
                    node* sum_node = new node;
                    sum_node->coef = sum;
                    sum_node->expon = ptr_1->expon;
                    add_item(sum_node);
                }
                else{
                }
                ptr_1 = ptr_1->next;
                ptr_2 = ptr_2->next;
                break;
            }
            case 1: // ptr_2 is larger!
            {
                add_item(ptr_2);
                ptr_2 = ptr_2->next;
                break;
            }
        }
    }

    if (ptr_1 == nullptr){
        while(ptr_2 != nullptr){
            add_item(ptr_2);
            ptr_2 = ptr_2->next;
        }
    }
    else{
        while (ptr_1 != nullptr){
            add_item(ptr_1);
            ptr_1 = ptr_1->next;
        }
    }

}