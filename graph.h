#pragma once 

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
#include <queue>
#include "helperfunctions.h"
#include <iterator>
#include <stdlib.h>

typedef std::pair<std::string,int> mapType;
typedef std::pair<int,std::string> P_Type;

class Graph
{
	private:
		std::deque<std::deque<std::string> > m_GraphMatrix;
		std::vector<std::string> m_minConnectedNode; 
		std::vector<std::string> m_Mislist;
		// translator vertices name to it index
		std::map<std::string,int> m_map;
		bool isNodeExist(std::string const &nodeName) const;
		bool isValidNodeName(std::string const &node);
		// 
		void selfConnect();
	public:	
		Graph(unsigned int verticesCount,std::string const &name="A");
		Graph();
		bool toConnect(std::string first,std::string last);
		bool toDisconnect(std::string first,std::string last);
		bool addNode(std::string nodeName);
		bool deleteNode(std::string nodeName);
		void printGraphMatrix() const;
		bool isEmpty() const;
		//--------------------------------------

		bool isComplete() const;
		void SCCProblem();
		bool MaxIndependentset();
		int SolveProblem(Graph obj);

		Graph removeAdjacentes(std::string const &nodeName);
		int isFullUnconnected();
};



