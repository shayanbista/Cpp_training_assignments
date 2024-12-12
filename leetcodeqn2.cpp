// To check if the number is a palinrome or not
#include <iostream>

void isPalindrome(int num){
    int reversredNum=0;
    int originalNum=num;
    //use while loop  unitl the num is > 0 
    while(num>0){
        int lastDigit=num%10;
        reversredNum=reversredNum*10+lastDigit;
        num=num/10;
    }
    // if the condition mathces return true 
    if(reversredNum!=originalNum){
        std::cout<<"its not a palindrome number"<<std::endl;
    }
    // if it doesnt match then return false
    else{
        std::cout<<"its a palindrome number"<<std::endl;
    }
} 


int main(){
    int num=101;
    isPalindrome(num);
}