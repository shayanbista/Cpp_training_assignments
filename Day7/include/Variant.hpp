#ifndef VARIANT_H
#define VARIANT_H

#include <iostream>
#include <string>
#include <memory>

#include "../include/Variant.hpp"
#include "../include/Let.hpp"
#include "../include/Datatype.hpp"


class Variant {
public:
    DATATYPE m_type;
    
    friend std::ostream& operator<<(std::ostream& os, const Variant& v);

    Variant();
    Variant(int value);
    Variant(double value);
    Variant(const char* value);
    Variant(const Variant& other);
    Variant& operator=(const Variant& other);
    int getIntValue() const;
    double getFloatValue() const;
    const char* getCharacters() const;
   
private:
    int m_nRes;
    double m_dRes;   
    std::shared_ptr<char[]> m_sRes;
};


#endif