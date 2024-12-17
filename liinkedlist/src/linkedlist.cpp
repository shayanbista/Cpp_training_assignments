#include "../include/linkedlist.h"

// Variant implementations
Variant::Variant() : m_sRes(nullptr) {
    std::cout << "this is a default constructor" << std::endl;
}

Variant::Variant(int value) : m_type(DATATYPE::NUMBER), m_nRes(value), m_sRes(nullptr) {
    std::cout << "integer is called: " << value << std::endl;
}

Variant::Variant(double value) : m_type(DATATYPE::FLOAT), m_dRes(value), m_sRes(nullptr) {
    std::cout << "double is called " << value << std::endl;
}

Variant::Variant(const char* value) : m_type(DATATYPE::STRING) {
    m_sRes = new char[strlen(value) + 1];
    strcpy(m_sRes, value);
}

Variant::Variant(const Variant& other) : 
    m_type(other.m_type), 
    m_nRes(other.m_nRes), 
    m_dRes(other.m_dRes), 
    m_sRes(nullptr) {
    if (other.m_type == DATATYPE::STRING && other.m_sRes) {
        m_sRes = new char[strlen(other.m_sRes) + 1];
        strcpy(m_sRes, other.m_sRes);
    }
}

Variant& Variant::operator=(const Variant& other) {
    if (this == &other) return *this;

    m_type = other.m_type;
    m_nRes = other.m_nRes;
    m_dRes = other.m_dRes;

    if (m_sRes) {
        delete[] m_sRes;
        m_sRes = nullptr;
    }

    if (other.m_type == DATATYPE::STRING && other.m_sRes) {
        m_sRes = new char[strlen(other.m_sRes) + 1];
        strcpy(m_sRes, other.m_sRes);
    }

    return *this;
}

int Variant::getIntValue() const {
    return m_nRes;
}

double Variant::getFloatValue() const {
    return m_dRes;
}

const char* Variant::getCharacters() const {
    return m_sRes;
}

Variant::~Variant() {
    if (m_sRes) {
        delete[] m_sRes;
    }
}

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