#pragma once
#include <vector>
#include <string>
#include "helperfunctions.h"

class CommandValidation
{
    private:
        std::vector<std::string> m_command;
    public:
        CommandValidation();
        void setToken(std::string command);
        std::vector<std::string> getCommand() const;
        bool create() const;
        void clear();
};