//
// Created by dell on 10/31/2021.
//

#ifndef HW4_OPERATION_H
#define HW4_OPERATION_H

class OPERATION {
public:
    char precede(char a, char b);
    char operate(char a, char b, char op);
    bool is_optr(char optr);
    int calculate_expression();
};


#endif //HW4_OPERATION_H
