#include <iostream>

class A {
public:
   
    A(int a, int b) {
        this->x = a; 
        this->y = b;  
        std::cout << "Constructor called with x = " << x << " and y = " << y << std::endl;
    }

    void operator()(int a, int b) {
        std::cout<<"the overloaded value id "<<a<<b<<std::endl;
        std::cout<<"the sum  is :"<<x+a<<" "<<y+b<<std::endl;
    }

private:
    int x, y; 
};

int main() {
    // here i am callling a normal constructor
    A a(10,5);


    // now this object will call the operator() function to overload
    a(20,10);
    
    return 0;
}
