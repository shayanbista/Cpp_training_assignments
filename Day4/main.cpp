#include "./include/linkedlist.h"

int main() {
    LinkedList list;
    
    list.insert(10);
    list.insert(20.5);
    list.insert("jenny");
    
    list.display();
    
    return 0;
}