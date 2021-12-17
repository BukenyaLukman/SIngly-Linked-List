#include<iostream>

#ifndef STRING_LINKED_LIST
#define STRING_LINKED_LIST


class StringLinkedList {
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const std::string& front() const;
    void addFront(const std::string& e);
    void removeFront();
private:
    StringNode* head;
};




#endif