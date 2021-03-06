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
#include <list>
#include "simplestruct.h"

typedef std::pair<std::string,int> mapType;
typedef std::pair<int,std::string> P_Type;

class Graph
{
	private:
		std::list<std::deque<std::string> > m_AdjacencyList;
		std::vector<std::string> m_minConnectedNode; 
		// translator vertices name to it index
		std::list<std::deque<std::string> > isNodeExist(std::string const &nodeName) const;
		bool isValidNodeName(std::string const &node);
		// 
		
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
		Wraper SolveProblem(Graph obj);

		Graph removeAdjacentes(std::string const &nodeName);
};



