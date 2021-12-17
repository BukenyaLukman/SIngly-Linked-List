#ifndef INT_LINKED_LIST_H
#define INT_LINKED_LIST_H


#include<iostream>

class IntSLLNode{
    public:
        IntSLLNode(){
            next = 0;
        }

        IntSLLNode(int el, IntSLLNode *ptr = 0){
            info = el;
            next = ptr;
        }
        int info;
        IntSLLNode *next;
};


class IntSLList{
    public:
        IntSLList(){
            head = tail = 0;
            // same as
            // head = NULL
            // tail = NULL
        }
        ~IntSLList();
        int isEmpty(){
            return head == 0;
        }
        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();
        void deleteNode(int);
        void print_linked_list();
        bool isInList(int) const;



     private:
        IntSLLNode *head, *tail;   
};





#endif

