#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <cstring>

#include "../include/Datatype.hpp"
#include "../include/Variant.hpp"

// Forward declaration
class Variant;

struct Node {
    Variant v;
    Node* next;
    Node(const Variant& v);
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