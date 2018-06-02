#pragma once

#include <string>
#include <vector>

struct  Wraper
{
    public:
        int m_count;
        std::vector<std::string> m_str;
        Wraper():m_count(0){}
        int getCount() const
        {
            return m_count;
        }
        void setCount(int val)
        {
            m_count=val;
        }
        std::vector<std::string> getStr() const
        {
            return m_str;
        }
        void addStr(std::string str)
        {
            m_str.push_back(str);
        }
        bool operator > (Wraper const &obj)
        {
            return m_count > obj.m_count;
        }
        bool operator < (Wraper const &obj)
        {
            return m_count < obj.m_count;
        }
        bool operator != (Wraper const &obj)
        {
            return m_count != obj.m_count;
        }
        bool operator == (Wraper const &obj)
        {
            return m_count == obj.m_count;
        }
       
    
};