#ifndef VAR_H
#define VAR_H


enum class DATATYPE{
    NUMBER = 0,
    FLOAT,
    STRING
};


class Let{
    public:
        explicit Let(const char* s);
        explicit Let(int x);
        explicit Let(double x);

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
        DATATYPE type;
        int  m_nRes = 0;
        double m_dRes = 0;
        bool m_bRes = false;
        char* m_sRes ;
};


#endif

