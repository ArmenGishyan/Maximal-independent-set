#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
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
        void _delete();
        void add();
        void connect();
        void disconnect();
        void create();
        void print();
        int findCommand(std::string const &str);
        void execute();
    public:
        Commands();
        void  commandInput();
};
