#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "helperfunctions.h"
#include "graph.h"
#include "validcommand.h"

typedef std::map<std::string,unsigned int> CommandType;
typedef std::pair<std::string,unsigned int> CommandPair;

class Commands
{
    private:
        CommandType m_mCommand;
        CommandValidation m_validcommand;
        Graph m_graph;
        void _delete(std::vector<std::string > str);
        void add(std::vector<std::string > str);
        void connect(std::vector<std::string > str);
        void disconnect(std::vector<std::string > str);
        void create();
        void print() const;
        int findCommand(std::string const &str);
        void execute();
    public:
        Commands();
        void  commandInput();
};
