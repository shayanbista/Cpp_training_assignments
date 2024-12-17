#include<iostream>
#include "./include/shared.h"


int main() {
    std::cout << "Creating first shared pointer\n";
    SharedPointer<int> ptr1(new int(42));
    SharedPointer<int> ptr2=ptr1;
    SharedPointer<int> ptr3=ptr1;
    std::cout << "\nLeaving main - ptr1 will be destroyed\n";
    return 0;
}