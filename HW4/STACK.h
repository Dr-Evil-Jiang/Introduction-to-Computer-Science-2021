//
// Created by dell on 10/31/2021.
//

#ifndef HW4_STACK_H
#define HW4_STACK_H


class STACK {
public:
    int* top;
    int* base;
    int stack_size;
    STACK(int size);
    ~STACK();
    bool is_empty(void);
    bool is_full(void);
    void push(int item);
    int pop(void);
    int get_top();
};


#endif //HW4_STACK_H
