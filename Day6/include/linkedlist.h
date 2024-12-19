#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <cstring>
#include <memory>  

enum class DATATYPE {
    NUMBER = 0,
    FLOAT,
    STRING
};

class Variant {
public:
    DATATYPE m_type;

    Variant();
    Variant(int value);
    Variant(double value);
    Variant(const char* value);
    Variant(const Variant& other);
    Variant& operator=(const Variant& other);
    int getIntValue() const;
    double getFloatValue() const;
    const char* getCharacters() const;

private:
    int m_nRes;
    double m_dRes;   
    std::shared_ptr<char[]> m_sRes;
   
};

struct Node {
    Variant v;
    Node* next;
    Node(const Variant& v);  
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    void insert(const Variant& other);
    void display();

private:
    Node* head;
};

#endif // LINKEDLIST_H