//
// Created by dell on 10/31/2021.
//

#include "OPERATION.h"
#include "STACK.h"
#include "iostream"
#include "stdio.h"

using namespace std;
char OPERATION::precede(char a, char b) {
    char f;
    if (a == '+' || a == '-'){
        if (b == '+' || b == '-' || b == ')' || b == '#'){
            f = '>';
        }
        else if (b == '*' || b == '/' || b == '('){
            f = '<';
        }
    }
    else if (a == '*' || a == '/'){
        if (b == '+' || b == '-' || b == '*' || b == '/' || b ==')' || b == '#'){
            f = '>';
        }
        else if (b == '('){
            f = '<';
        }
    }
    else if (a == '('){
        if (b == '+' || b == '-' || b == '*' || b == '/' || b == '('){
            f = '<';
        }
        else if (b == ')'){
            f = '=';
        }
    }
    else if (a == ')'){
        if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '#'){
            f = '>';
        }
    }
    else if (a == '#'){
        if (b == '+' || b == '-' || b == '*' || b == '/' || b == '('){
            f = '<';
        }
        else if (b == '#'){
            f = '=';
        }
    }
    return f;
}
char OPERATION::operate(char a, char b, char op) {
    char c;
    a = a - '0';
    b = b - '0';
    switch (op) {
        case '+':{
            c = a + b + '0';
            break;
        }
        case '-':{
            c = a - b + '0';
            break;
        }
        case '*':{
            c = a * b + '0';
            break;
        }
        case '/': {
            c = a / b + '0';
            break;
        }
    }
    return c;
}
bool OPERATION::is_optr(char optr) {
    if (optr == '+' || optr == '-' || optr == '*' || optr == '/' || optr == '(' || optr == ')' || optr == '#'){
        return true;
    }
    else{
        return false;
    }
}
int OPERATION::calculate_expression() {
    STACK OPTR_stack = STACK(1000);
    STACK OPND_stack = STACK(1000);
    char ch = getchar();
    char a, b, x, optr;
    OPTR_stack.push('#');
    while(ch != '#' || OPTR_stack.get_top() != '#'){
        if (!is_optr(ch)){
            OPND_stack.push(ch);
            ch = getchar();
        }
        else{
            switch (precede(OPTR_stack.get_top(), ch)) {
                case '<':{
                    OPTR_stack.push(ch);
                    ch = getchar();
                    break;
                }
                case '>':{
                    optr = OPTR_stack.pop();
                    b = OPND_stack.pop();
                    a = OPND_stack.pop();
                    OPND_stack.push(operate(a, b, optr));
                    break;
                }
                case '=':{
                    x = OPTR_stack.pop();
                    ch = getchar();
                    break;
                }
            }
        }
    }
    return OPND_stack.get_top() - '0';
}