#include "helperfunctions.h"

std::vector<std::string> helper::split(std::string const & s_str)
{
    std::stringstream s_stream(s_str);
    std::string str_temp;

    std::vector<std::string> vec;
    while(!s_stream.eof())
    {
        getline(s_stream,str_temp,' ');
        if(str_temp.size()!=0)
        {
            vec.push_back(str_temp);
        }
    }
    return vec;
}
bool helper::isUIntNumber(std::string const &str)
{
    for(int i=0;i<str.size();++i)
    {
        if(str[i]>='9'|| str[i]<='0')
        {
            return false;
        }
    }
    return true;
}
int helper::strToint(std::string str)
{
    std::stringstream strstream(str);
    int x=0;
    strstream>>x;
    return x;
}