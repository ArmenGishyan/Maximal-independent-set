#pragma once
#include <vector>
#include <string>
#include "helperfunctions.h"
#include <fstream>
#include <algorithm>

class CommandValidation
{
    private:
        std::vector<std::string> m_command;
        std::fstream m_history;
    public:
        CommandValidation();
        void setCommand(std::vector<std::string> const  &v_str);
        std::vector<std::string> getCommand() const;
        bool create() const;
        bool connect() const;
        bool disconnect() const;
        bool addNode() const;
        bool MISet() const;
        bool print() const;
        bool _delete() const;
        void clear();
        void writeHistory(std::string const & word);
};