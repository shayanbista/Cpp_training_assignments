#include <iostream>
#include <cstring>
#include <sstream>

#include "../include/Let.hpp"
#include "../include/Variant.hpp"

Let::Let(const char* s) : m_type(DATATYPE::STRING) {
    std::cout << s << "\n";
    m_sRes = new char[strlen(s) + 1];
    strcpy(m_sRes, s);
}

Let::Let(int x) : m_type(DATATYPE::NUMBER) {
    std::cout << x << "\n";
    m_nRes = x;
}

Let::Let(double s) : m_type(DATATYPE::FLOAT) {
    std::cout << s << "\n";
    m_dRes = s;
}


Let::Let(std::initializer_list<Variant> variants) : m_type(DATATYPE::LIST) {
    for(auto& v : variants){
        std::cout<<"vavlue"<<v<<"\n";
    }
}

Let::~Let() {
    if (m_type == DATATYPE::STRING) {
        std::cout << "Destructor called for string: " << m_sRes << "\n";
        delete[] m_sRes;
    }
}

Let& Let::operator+=(int num) {
    if (m_type == DATATYPE::STRING) {
        std::ostringstream oss;
        oss << num;
        m_sRes = strcat(m_sRes, oss.str().c_str()); 
    } else if (m_type == DATATYPE::NUMBER) {
        m_nRes += num;  
    } else if (m_type == DATATYPE::FLOAT) {
        m_dRes += num;  
    }
    return *this;
}

Let& Let::operator+=(double num) {
    if (m_type == DATATYPE::STRING) {
        std::ostringstream oss;
        oss << num;
        m_sRes = strcat(m_sRes, oss.str().c_str());  
    } else if (m_type == DATATYPE::NUMBER) {
        m_nRes += num;  
    } else if (m_type == DATATYPE::FLOAT) {
        m_dRes += num; 
    }
    return *this;
}

Let& Let::operator+=(const char* s) {
    if (m_type == DATATYPE::STRING) {
        int len = strlen(m_sRes) + strlen(s) + 1;
        char* temp = new char[len];
        strcpy(temp, m_sRes);
        strcat(temp, s);
        delete[] m_sRes;
        m_sRes = temp;
    } else if (m_type == DATATYPE::NUMBER) {
        std::istringstream oss(s);
        oss >> m_nRes;
    } else if (m_type == DATATYPE::FLOAT) {
        std::istringstream oss(s);
        oss >> m_dRes;
    }
    return *this;
}


bool Let::operator==(const Let& other) {

    bool result = false;
    if (m_type == DATATYPE::NUMBER && other.m_type == DATATYPE::NUMBER) {
        result = m_nRes == other.m_nRes;
    } else if (m_type == DATATYPE::FLOAT && other.m_type == DATATYPE::FLOAT) {
        result = m_dRes == other.m_dRes;
    } else if (m_type == DATATYPE::STRING && other.m_type == DATATYPE::STRING) {
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

    if (m_type == DATATYPE::STRING) {
        delete[] m_sRes;
        m_sRes = new char[strlen(other.m_sRes) + 1];
        strcpy(m_sRes, other.m_sRes);
    } else if (m_type == DATATYPE::NUMBER) {
        m_nRes = other.m_nRes;
    } else if (m_type == DATATYPE::FLOAT) {
        m_dRes = other.m_dRes;
    }

    return *this;
}

bool Let::operator>(const Let& other) {
    bool result = false;

    if (m_type == DATATYPE::NUMBER && other.m_type== DATATYPE::NUMBER) {
        result = m_nRes > other.m_nRes;
    } else if (m_type == DATATYPE::FLOAT && other.m_type == DATATYPE::FLOAT) {
        result = m_dRes > other.m_dRes;
    } else if (m_type == DATATYPE::STRING && other.m_type == DATATYPE::STRING) {
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
    if (m_type == DATATYPE::NUMBER){
        std::cout<< "Number"<<m_nRes<<"\n";
    }

    else if (m_type == DATATYPE::FLOAT){
        std::cout<< "Float"<<m_dRes<<"\n";
    }
    else if(m_type  == DATATYPE::STRING){
        std::cout<< "String"<<m_sRes<<"\n";
    }
}
