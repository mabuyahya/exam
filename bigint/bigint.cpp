#include "bigint.hpp"

bigint::bigint(){
    str = "0";
}

bigint::bigint(unsigned int num){
    std::stringstream ss;
    ss << num;
    str = remove_leading_zeros(ss.str());
}

bigint::bigint(const bigint &other){
    str = other.str;
}

bigint::bigint(std::string s){
    str = remove_leading_zeros(s);
}

bigint::~bigint(){
}

bigint &bigint::operator=(const bigint &other){
    str = other.str;
    return (*this);
}

std::string bigint::getBigInt() const{
    return (str);
}

bigint bigint::operator+(const bigint &other){
    std::string result = add_two_strings(str,other.str);
    return (bigint(result));
}

bigint &bigint::operator+=(const bigint &other){
    str = add_two_strings(str, other.str);
    return (*this);
}


std::string bigint::remove_leading_zeros(const std::string &str){
    size_t first_non_zero = str.find_first_not_of('0');
    if (first_non_zero == std::string::npos)
        return ("0");
    return (str.substr(first_non_zero));
}

std::string bigint::add_two_strings(const std::string &s1, const std::string &s2) {
    std::string result = "";
    int carry = 0;
    int i = s1.size() - 1; 
    int j = s2.size() - 1; 
    int sum;

    while (i >= 0 || j >= 0 || carry){
        sum = carry;

        if (i >= 0){
            sum += (s1[i] - '0');
            i--;
        }
        if (j >= 0){
            sum += (s2[j] - '0');
            j--;
        }

        carry = sum / 10;
        result += (char) ((sum % 10) + '0');
    }
    std::reverse(result.begin(), result.end());

    return (remove_leading_zeros(result));
}

bigint &bigint::operator++(){
    str = add_two_strings(str, "1");
    return (*this);
}

bigint bigint::operator++(int){
    bigint temp;

    temp = *this;
    ++(*this);
    return (temp);
}

bigint bigint::operator<<(size_t shift){
    return (bigint(str + std::string(shift, '0')));
}

bigint &bigint::operator<<=(size_t shift){
    str += std::string(shift, '0');
    return(*this);
}

bigint bigint::operator>>(const bigint &other){
    bigint temp(*this);
    temp >>= other;
    return (temp);
}

bigint &bigint::operator>>=(const bigint &other){
    if (bigint(str.size()) <= other)
        str = "0";
    else {
        bigint i(0);
        while (i < other) {
            str = str.substr(0, str.size() - 1);
            i++;
        }
    }
    return (*this);
}

bool    bigint::operator<(const bigint &other) const {
    if (str.size() != other.str.size())
        return (str.size() < other.str.size());
    return (str < other.str);
}
bool    bigint::operator<=(const bigint &other) const {
    return (!(*this > other));
}
bool    bigint::operator>(const bigint &other)const{
    return ((other < *this));
}
bool    bigint::operator>=(const bigint &other)const{
    return (!(*this < other));
}
bool    bigint::operator==(const bigint &other)const{
    return (str == other.str);
}
bool    bigint::operator!=(const bigint &other)const{
    return (str != other.str);
}

std::ostream &operator<<(std::ostream &os, const bigint &other){
    os << other.getBigInt();
    return (os);
}