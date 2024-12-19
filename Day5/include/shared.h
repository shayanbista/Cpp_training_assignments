#ifndef SHARED_H
#define SHARED_H

template<typename T>
class SharedPointer {
public:
    int* m_refCount;
    explicit SharedPointer(T* p = nullptr); 
    SharedPointer& operator=(SharedPointer<T>& other);
    ~SharedPointer(); 

private:
    T* m_ptr;
    void cleanup(); 
};

#endif 
