#include "../include/linkedlist.h"

// Variant implementations
Variant::Variant() = delete;

Variant::Variant(int value) : m_type(DATATYPE::NUMBER), m_nRes(value), m_sRes(nullptr) {
    std::cout << "integer is called: " << value << std::endl;
}

Variant::Variant(double value) : m_type(DATATYPE::FLOAT), m_dRes(value), m_sRes(nullptr) {
    std::cout << "double is called " << value << std::endl;
}

Variant::Variant(const char* s) : m_type(DATATYPE::STRING) {
    m_sRes = std::shared_ptr<char[]>(new char[strlen(s) + 1], std::default_delete<char[]>());
    strcpy(m_sRes.get(), s);
}

Variant::Variant(const Variant& other): 
    m_type(other.m_type), 
    m_nRes(other.m_nRes), 
    m_dRes(other.m_dRes), 
    m_sRes(nullptr) {
    if (other.m_type == DATATYPE::STRING && other.m_sRes) {
        m_sRes = std::shared_ptr<char[]>(new char[strlen(other.m_sRes.get()) + 1], std::default_delete<char[]>());
        strcpy(m_sRes.get(), other.m_sRes.get());
    }
}

Variant& Variant::operator=(const Variant& other) {
    if (this == &other) return *this;

    m_type = other.m_type;
    m_nRes = other.m_nRes;
    m_dRes = other.m_dRes;

    if (other.m_type == DATATYPE::STRING && other.m_sRes) {
        m_sRes = std::shared_ptr<char[]>(new char[strlen(other.m_sRes.get()) + 1], std::default_delete<char[]>());
        strcpy(m_sRes.get(), other.m_sRes.get());
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
    return m_sRes.get();
}

// Node implementation
Node::Node(const Variant& v) : v(v), next(nullptr) {}

// LinkedList implementations
LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insert(const Variant& other) {
    auto node=std::make_shared<Node>(other);
        
    if (head) {
        std::shared_ptr<Node> tempNode = head;
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

    std::shared_ptr<Node> temp=head;
    while (temp) {
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