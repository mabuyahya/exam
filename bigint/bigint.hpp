#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <sstream>
#include <algorithm>

class bigint {
    private:
        std::string str;

        std::string add_two_strings(const std::string &s1, const std::string &s2);
        std::string remove_leading_zeros(const std::string &s2);
    public:
        bigint();
        bigint(unsigned int);
        bigint(std::string s);
        bigint(const bigint &other);
        ~bigint();
        bigint &operator=(const bigint &other);

        std::string getBigInt() const;

        bigint operator+(const bigint &other);
        bigint &operator+=(const bigint &other);


};

#endif