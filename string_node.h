#ifndef STRING_NODE
#define STRING_NODE

#include "singly_linked_list.h"
#include<iostream>

class StringNode{
    private:
        std::string elem;
        StringNode* next;
    friend class StringLinkedList;
};


#endif