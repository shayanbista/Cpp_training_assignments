#include "../include/linkedlist.hpp"
#include "../include/Variant.hpp"

// Node implementation
Node::Node(const Variant& v) : v(v), next(nullptr) {}

// LinkedList implementations
LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(const Variant& other) {
    Node* node = new Node(other);

    if (head) {
        Node* tempNode = head;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = node;
    }
    else {
        head = node;
    }
}

void LinkedList::display() {
    Node* temp = head;
    while (temp) {
        std::cout << "Node data: ";
        switch (temp->v.m_type) {
            case DATATYPE::NUMBER:
                std::cout << temp->v.getIntValue();
                break;
            case DATATYPE::FLOAT:
                std::cout << temp->v.getFloatValue();
                break;
            case DATATYPE::STRING:
                std::cout << temp->v.getCharacters();
                break;
        }
        std::cout << "\n";
        temp = temp->next;
    }
}