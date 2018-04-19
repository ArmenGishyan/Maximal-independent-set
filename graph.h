#pragma once 

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <deque>

class Graph
{
	private:
		std::deque<std::deque<std::string> > m_GraphMatrix;

		// translator vertices name to it index
		std::map<std::string,int> m_map;
		bool isNodeExist(std::string const &nodeName) const;
		bool isValidNodeName(std::string const &node);
		// 
		void connect();
	public:	
		Graph(unsigned int verticesCount,std::string const &name="A");
		Graph();
		void toConnect(std::string first,std::string last);
		void toDisconnect(std::string first,std::string last);
		void addNode(std::string nodeName);
		void deleteNode(std::string nodeName);
		void printGraphMatrix() const;
		

};



