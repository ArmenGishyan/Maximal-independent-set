#include "graph.h"
typedef std::pair<std::string,int> mapType;

Graph::Graph(unsigned int verticesCount,std::string const &name):m_GraphMatrix(verticesCount+1)
{
	verticesCount+=1;
	for(int i=0;i<m_GraphMatrix.size();++i)
	{
		m_GraphMatrix[i].resize(verticesCount);
		m_GraphMatrix[0][i]=name+std::to_string(i-1);
		m_GraphMatrix[i][0]=name+std::to_string(i-1);
	}
	m_GraphMatrix[0][0]="vertices";

	int j=1;
	for(int i=1;i<m_GraphMatrix.size();++i)
	{
		for(j=1;j<m_GraphMatrix[i].size();++j)
		{
			m_GraphMatrix[i][j]="0";
		}
	}

	for(int i=1;i<m_GraphMatrix.size();++i)
	{
		m_map.insert(m_map.begin(),mapType(m_GraphMatrix[0][i],i));
	}

	connect();
}
Graph::Graph(){}
void Graph::toConnect(std::string first,std::string last)
{
	if(isNodeExist(first) && isNodeExist(last))
	{
		m_GraphMatrix[m_map[first]][m_map[last]]="1";
	}
	else
	{
		std::cerr<<"ERROR: \n Invlid node name!\n";
		std::terminate();
	}
}
void Graph::printGraphMatrix() const 
{
	int j=0;
	for(int i=0;i<m_GraphMatrix.size();i++)
	{
		std::cout<<"\n";
		if(i!=0) std::cout<<"\t";
		for(j=0;j<m_GraphMatrix[i].size();j++)
		{
			std::cout<<m_GraphMatrix[i][j]<<",  ";
		}
	}
}
void Graph::toDisconnect(std::string first,std::string last) 
{
	if(isNodeExist(first) && isNodeExist(last))
	{
		m_GraphMatrix[m_map[first]][m_map[last]]="0";
	}
	else
	{
		std::cerr<<"ERROR: \n Invlid node name!\n";
		std::terminate();
	}
}
void Graph::addNode(std::string nodeName)
{
	if(isNodeExist(nodeName))
	{
		std::cerr<<"ERROR \n Node already exist!\n";
		std::terminate();
	}
	std::deque<std::string> nodeInsert(m_GraphMatrix.size()+1,"0");

	for(int i=1;i<m_GraphMatrix.size();++i)
	{
		m_GraphMatrix[i].push_back("0");
	}
	m_GraphMatrix.push_back(nodeInsert);
	
	m_GraphMatrix[0].push_back(nodeName);
	m_GraphMatrix[m_GraphMatrix.size()-1][0]=nodeName;

	m_map.insert(m_map.end(),mapType(nodeName,m_map.size()+1));
	m_GraphMatrix[m_map[nodeName]][m_map[nodeName]]="1";
}
void Graph::deleteNode(std::string nodeName)
{
	if(isNodeExist(nodeName))
	{
		auto it= m_GraphMatrix.begin();
		while(it->begin()[0]!=nodeName)
		{
			it++;
		}

		m_GraphMatrix.erase(it);
		auto itToelements=m_GraphMatrix.begin();
		while(itToelements!=m_GraphMatrix.end())
		{
			itToelements->erase(itToelements->begin()+m_map[nodeName]);
			itToelements++;
		}
	}
	else
	{
		std::cerr<<"ERROR: \n Invlid node name!\n";
		std::terminate();
	}

}
bool Graph::isNodeExist(std::string const &nodeName)const
{
	return (m_map.find(nodeName)!=m_map.end());
}
bool Graph::isValidNodeName(std::string const &nodeName)
{
	return (nodeName.size()<4);
}
void Graph::connect()
{
	for(int i=1;i<m_GraphMatrix.size();++i)
	{
		m_GraphMatrix[i][i]="1";
	}
}