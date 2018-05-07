#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace helper
{
    std::vector<std::string> split(std::string const &s_str);
    bool isUIntNumber(std::string const &str);
    int strToint(std::string str);
    void decrement(std::pair<std::string,int> &item);

}