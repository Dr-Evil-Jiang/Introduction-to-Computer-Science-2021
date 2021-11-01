//
// Created by dell on 10/30/2021.
//

#ifndef HW4_POLN_H
#define HW4_POLN_H
class node{
public:
    double coef;
    int expon;
    node* next;
};

class POLN {
private:
    node* head;
    int length;
public:
    POLN(void);
    void prt_poly(void);
    void add_item(node* item);
    int cmp(node* p, node* q);
    void init_from_arr(double* coef, int coeff_len, int* expon, int expon_len);
    void add_poln(POLN a, POLN b); // Return a = a + b, and b is deleted from memory.;
    void get_length(void);
};


#endif //HW4_POLN_H
