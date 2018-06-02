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
        void addCount()
        {
            ++m_count;
        }
        std::vector<std::string> getStr() const
        {
            return m_str;
        }
        void addStr(std::string str)
        {
            m_str.push_back(str);
        }
        Wraper(Wraper const& obj)
        {
            m_count = obj.m_count;
            m_str = obj.m_str;
        }
        bool operator > (Wraper const obj) const
        {
            return (m_count > obj.m_count);
        }
        bool operator < (Wraper const obj) const
        {
            return m_count < obj.m_count;
        }
        bool operator != (Wraper const obj) const
        {
            return m_count != obj.m_count;
        }
        bool operator == (Wraper const obj) const
        {
            return m_count == obj.m_count;
        }
        Wraper& operator = (Wraper const obj) 
        {
            m_count = obj.m_count;
            m_str = obj.m_str;
            return *this;
        }

       
    
};