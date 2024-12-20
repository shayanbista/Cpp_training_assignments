#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <cstring>

#include "../include/Datatype.hpp"

struct Node {
    Variant v;
    Node* next;
    // Node(const Variant& v);
    Node(const Variant& v) : v(v), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    
    void insert(const Variant& other);
    void display();

private:
    Node* head;
};

#endif // LINKEDLIST_H