#include "../include/shared.h"

template<typename T>
SharedPointer<T>::SharedPointer(T* p) : m_ptr(p), m_refCount(nullptr) {
    if (m_ptr) {
        m_refCount = new int(1);
    }
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer& other) {
    if (this == &other) return *this;  
    cleanup();
    m_ptr = other.m_ptr;
    m_refCount = other.m_refCount;
    if (m_refCount) {
        (*m_refCount)++;
    }
    return *this;
}

template<typename T>
SharedPointer<T>::~SharedPointer() {
    cleanup();
}

template<typename T>
void SharedPointer<T>::cleanup() {
    if (m_refCount) {
        (*m_refCount)--;
        if (*m_refCount == 0) {
            delete m_ptr;
            delete m_refCount;
            m_ptr = nullptr;
            m_refCount = nullptr;
        }
    }
}

template class SharedPointer<int>;
template class SharedPointer<double>;
template class SharedPointer<char>;
