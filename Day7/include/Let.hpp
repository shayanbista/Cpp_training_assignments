#ifndef VAR_H
#define VAR_H

#include "../include/Variant.hpp"
#include "../include/Datatype.hpp"
#include "../include/Linkedlist.hpp"

#include <vector>

//Forward declaration of classes
class Variant;
class LinkedList;


class Let{
    public:
        DATATYPE m_type;
        Let(std::initializer_list<Variant> variants); 
        Let(int x);
        Let(double x); 
        Let(const char* s);

        Let& operator+=(int num);
        Let& operator+=(double num);
        Let& operator+=(const char* x);
        Let& operator=(const Let& other);
        bool operator==(const Let& other);
        bool operator>(const Let& other);
       
        void display();

        // destructor
        ~Let();

    private:
        int  m_nRes = 0;
        double m_dRes = 0;
        bool m_bRes = false;
        char* m_sRes ;
        std::vector<Variant> m_variants; 

};


#endif

