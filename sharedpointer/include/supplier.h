#ifndef SUPPLIER_H
#define SUPPLIER_H

#include<iostream>
#include<memory>

template<typename T>
class SharedPointer{
        
    public:
        int *m_refCount;

        SharedPointer<T>(T* p=nullptr);

        SharedPointer& operator=(SharedPointer<T> &other);
        
    private:
        int *m_ptr;


}