#include "./include/Let.h"
#include <iostream>


int main(){
    Let v("Ram");  
    Let v1("Ram"); 
    v==v1;
    v+=100;

    v.display();
}

