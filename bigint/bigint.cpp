#include "bigint.hpp"

bigint::bigint(){
}

bigint::bigint(unsigned int num){
    std::stringstream ss;
    ss << num;
    str = ss.str();
}

bigint::bigint(const bigint &other){
    str = other.str;
}

bigint::~bigint(){
}

bigint &bigint::operator=(const bigint &other){
    str = other.str;
}

std::string bigint::getBigInt() const{
    return (str);
}

bigint bigint::operator+(const bigint &other){
    std::string result = add_two_strings(str,other.str);
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