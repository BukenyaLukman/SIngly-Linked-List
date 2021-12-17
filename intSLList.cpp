#include<iostream>
#include "intSSList.h"

IntSLList::~IntSLList(){
    for(IntSLLNode *p; !isEmpty();){
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el){
    head = new IntSLLNode(el, head);
    if(tail == 0){
        tail = head;
    }
}


void IntSLList::addToTail(int el){
    if(tail != 0){
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    }
}
int IntSLList::deleteFromHead(){
    int el = head->info;
    IntSLLNode *tmp = head;
    if(head == tail){
        head = tail = 0;
    }else{
        head = head->next;
        delete tmp;
    }
    return el;
}
int IntSLList::deleteFromTail(){
    int el = tail->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    }else{
        IntSLLNode *tmp;
        for(tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    return el;
}
void IntSLList::deleteNode(int el){
    if(head != 0){
        if(head == tail && el == head->info){
            delete head;
            head = tail = 0;
        }else if(el == head->info){
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;
        }
    }else{
        IntSLLNode *pred, *tmp;
        for(pred = head, tmp = head->next; 
        tmp != 0 && !(tmp->info == el);
        pred = pred->next, tmp = tmp->next
        );
        if(tmp != 0){
            pred->next = tmp->next;
            if(tmp == tail){
                tail = pred;
            }
            delete tmp;
        }
    }
}

bool IntSLList::isInList(int el) const{
    IntSLLNode *tmp;
    for(tmp = head; tmp != 0 && !(tmp->info ==el); tmp = tmp->next);
    return tmp != 0;
}

void IntSLList::print_linked_list(){
    if(head == 0){
        std::cout << "Empty list" << std::endl;
    }else{
        for(IntSLLNode *p = head; p != 0; p = p->next){
            std::cout << p->info << " ";
        }
        std::cout << std::endl;
    }
}
int main(){


    IntSLList list;
    list.print_linked_list();
    list.addToHead(14);
    list.addToHead(13);
    list.addToHead(12);
    list.addToHead(11);
    list.addToHead(10);
    list.print_linked_list();
    list.deleteNode(14);
    list.print_linked_list();




    return 0;
}