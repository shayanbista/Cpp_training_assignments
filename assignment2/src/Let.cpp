#include "../include/Let.h"
#include <iostream>
#include <cstring>

Let::Let(const char* s) : type(DATATYPE::STRING) {
    std::cout << s << "\n";
    m_sRes = new char[strlen(s) + 1];
    strcpy(m_sRes, s);
}

Let::Let(int x) : type(DATATYPE::NUMBER) {
    std::cout << x << "\n";
    m_nRes = x;
}

Let::Let(double s) : type(DATATYPE::FLOAT) {
    std::cout << s << "\n";
    m_dRes = s;
}

Let::~Let() {
    if (type == DATATYPE::STRING) {
        std::cout << "Destructor called for string: " << m_sRes << "\n";
        delete[] m_sRes;
    }
}

Let& Let::operator+=(int num) {
    if (type == DATATYPE::NUMBER) {
        m_nRes += num;
    }
    return *this;
}

Let& Let::operator+=(double num) {
    if (type == DATATYPE::FLOAT) {
        m_dRes += num;
    }
    return *this;
}

Let& Let::operator+=(const char* s) {
    if (type == DATATYPE::STRING) {
        int len = strlen(m_sRes) + strlen(s) + 1;
        char* temp = new char[len];
        strcpy(temp, m_sRes);
        strcat(temp, s);
        delete[] m_sRes;
        m_sRes = temp;
    }
    return *this;
}

bool Let::operator==(const Let& other) {

    bool result = false;
    if (type == DATATYPE::NUMBER && other.type == DATATYPE::NUMBER) {
        result = m_nRes == other.m_nRes;
    } else if (type == DATATYPE::FLOAT && other.type == DATATYPE::FLOAT) {
        result = m_dRes == other.m_dRes;
    } else if (type == DATATYPE::STRING && other.type == DATATYPE::STRING) {
        int l1 = strlen(m_sRes);
        int l2 = strlen(other.m_sRes);
        int i = 0, j = 0;
        
        while (i < l1 && j < l2 && m_sRes[i] == other.m_sRes[j]) {
            i++;
            j++;
        }
        
        result = i == l1 && j == l2;
        
}
    std::cout << result << "\n";
    return result;
}

Let& Let::operator=(const Let& other) {
    if (this == &other) {
        return *this;
    }

    if (type == DATATYPE::STRING) {
        delete[] m_sRes;
        m_sRes = new char[strlen(other.m_sRes) + 1];
        strcpy(m_sRes, other.m_sRes);
    } else if (type == DATATYPE::NUMBER) {
        m_nRes = other.m_nRes;
    } else if (type == DATATYPE::FLOAT) {
        m_dRes = other.m_dRes;
    }

    return *this;
}

bool Let::operator>(const Let& other) {
    bool result = false;

    if (type == DATATYPE::NUMBER && other.type == DATATYPE::NUMBER) {
        result = m_nRes > other.m_nRes;
    } else if (type == DATATYPE::FLOAT && other.type == DATATYPE::FLOAT) {
        result = m_dRes > other.m_dRes;
    } else if (type == DATATYPE::STRING && other.type == DATATYPE::STRING) {
        int l1 = strlen(m_sRes);
        int l2 = strlen(other.m_sRes);
        int i = 0, j = 0;
        
        while (i < l1 && j < l2 && m_sRes[i] == other.m_sRes[j]) {
            i++;
            j++;
        }
        
        result = (i < l1 && j < l2 && m_sRes[i] > other.m_sRes[j]);
    }

    std::cout << "Comparison result: " << result << std::endl;
    return result;
}


void Let::display(){
    if (type == DATATYPE::NUMBER){
        std::cout<< "Number"<<m_nRes<<"\n";
    }

    else if (type == DATATYPE::FLOAT){
        std::cout<< "Float"<<m_dRes<<"\n";
    }
    else if(type== DATATYPE::STRING){
        std::cout<< "String"<<m_sRes<<"\n";
    }
}
