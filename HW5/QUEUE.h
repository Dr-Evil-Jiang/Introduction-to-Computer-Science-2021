//
// Created by dell on 11/10/2021.
//

#ifndef HW5_QUEUE_H
#define HW5_QUEUE_H


class NODE{
public:
    int val;
    NODE* next;
};

class QUEUE {
public:
    NODE* head = nullptr;
    NODE* tail = nullptr;
    QUEUE();
    ~QUEUE();
    void enqueue(int val);
    int dequeue();
    void prt_queue() const;
};


#endif //HW5_QUEUE_H
