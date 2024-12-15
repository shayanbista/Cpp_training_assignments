#include <iostream>
#include <memory>
// dangling pointer example

class A{

    public:
    A(){ 
        // default constructor
    }

    void display(){
        std::cout<<"hello world"<<std::endl;
    }

};


int main(){


A *a = new A();

std::cout << "Pointer before delete: " << a << std::endl;

delete a;

std::cout<<"Pointer after delete: " << a << std::endl;

// solution to handle dangling pointer
// 1. we can assign a null pointer to the pointer

a=nullptr;

std::cout << "Pointer after delete: " << a << std::endl;

}


// 2.We can use shared pointer

// class A{

//     public:
//     A(){
//         // default constructor
//     }

//     void display(){
//         std::cout<<"hello world"<<std::endl;
//     }

// };

// int main(){

// std::shared_ptr<A> a=std::make_shared<A>();

// std::cout << "Pointer before delete (shared_ptr): " << a << std::endl;
// a->display(); 
// std::cout << "Pointer after delete (shared_ptr): " << a << std::endl;
// return 0;

// }
