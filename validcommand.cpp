#include "validcommand.h"

CommandValidation::CommandValidation():m_history("history.txt",std::ios::out)
{
    if(!m_history.is_open())
    {
        std::cerr<<"file is not open"<<std::endl;
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
bool CommandValidation::connect() const
{
    if(m_command.size()!=3)
    {
        std::cerr<<"Invalid argument to connect"<<std::endl;
        return false;
    }
    return true;
    
}
void CommandValidation::setCommand(std::vector<std::string> const &v_str)
{
    m_command=v_str;
    int size=v_str.size();
    for(int i=0;i<size;++i)
    {
        m_history<<v_str[i]<<" ";
    }
    m_history<<"\n";
}
bool CommandValidation::print() const
{
    if(m_command.size()>1)
    {
        std::cerr<<"print is without arguments!\n";
        return false;
    }
    return true;
}
bool CommandValidation::disconnect() const
{
    if(m_command.size()!=3 )
    {
        std::cerr<<"ERROR \n Invalid disconnect argument!\n";
        return false;
    }
    else
    {
        return true;
    }
}
bool CommandValidation::addNode() const
{
    if(m_command.size()!=2)
    {
        std::cerr<<"invalid add argument\n";
        return false;
    }
    return true;
}
bool CommandValidation::_delete() const
{
    if(m_command.size()!=2)
    {
        std::cerr<<"delete must be one argument!\n";
        return false;
    }
    return true;
}
bool CommandValidation::MISet() const
{
    if(m_command.size()>1)
    {
        std::cerr<<"MISet with out argument\n";
        return false;
    }
    return true;
}
void CommandValidation::writeHistory(std::string const &word)
{
    m_history<<word<<" ";
}