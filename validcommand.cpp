#include "validcommand.h"

CommandValidation::CommandValidation()
{
    m_command.reserve(4);
}

void CommandValidation::setToken(std::string s_str)
{
    if(s_str.size()!=0)
    {
        m_command.push_back(s_str);
    }
}

bool CommandValidation::create() const
{
    if(m_command.size()>3) 
    {
        std::cerr<<"ERROR \n Invalid input!"<<std::endl;
        return false;
    }
    if(m_command.size()==1)
    {
        std::cerr<<"ERROR \n Missing argument to create!"<<std::endl;
        return false;
    }
    else
    {
        if(m_command.size()==2 || m_command.size()==3)
        {
            if(!helper::isUIntNumber(m_command[1]))
            {
                std::cerr<<"ERROR \n Invlaid argument"<<std::endl;
                return false;
            }
            if(m_command.size()==3)
            {
                if(m_command[2].size()>4)
                {
                    std::cerr<<"ERROR \n Graph name is too large!"<<std::endl;
                    return false;
                }
            }
        }
    }
    return true;       
}
std::vector<std::string> CommandValidation::getCommand() const
{
    return m_command;
}
void CommandValidation::clear()
{
    m_command.clear();
}