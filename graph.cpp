#include "graph.h"
#include <set>
#include <functional>
#include <queue>

Graph::Graph(unsigned int verticesCount,std::string const &name){}

	
}
Graph::Graph(){}
bool Graph::toConnect(std::string first,std::string last)
{
	auto  itFirst = isNodeExist(first);
	auto  itLast  = isNodeExist(last);
	if((itFirst != m_AdjacencyList.end()) && (itLast != m_AdjacencyList.end()))
	{
		itFirst->push_back(last);
		itLast->push_back(first);
		return true;
	}
	else
	{
		std::cerr<<"ERROR: \n Invlid node name!\n";
		return false;
	}
}
void Graph::printGraphMatrix() const 
{
	auto it = m_AdjacencyList.begin();
	auto itToElement = m_AdjacencyList.begin()->begin();
	while(it != m_AdjacencyList.end())
	{
		itToElement = it->begin();
		while(itToElement != it->end())
		{
			std::cout<<*itToElement<<", ";
		}
		std::cout<<"\n";
	}
}
bool Graph::toDisconnect(std::string first,std::string last) 
{
	if(isNodeExist(first) && isNodeExist(last))
	{
		m_GraphMatrix[m_map[first]][m_map[last]]="0";
		m_GraphMatrix[m_map[last]][m_map[first]]="0";
		std::cout<<"Node "<<first<<" and "<<last<<" is successfully disconnected"<<std::endl;
		return true;
	}
	else
	{
		std::cerr<<"ERROR: \n Invlid node name!\n";
		return false;
	}
}
bool Graph::addNode(std::string nodeName)
{
	if(isNodeExist(nodeName))
	{
		std::cerr<<"ERROR \n Node already exist!\n";
		return false;
	}
	std::vector<std::string> newNode;
	newNode.push_back(nodeName);

	m_AdjacencyList.push_back(newNode);
	
	return true;
}
bool Graph::deleteNode(std::string nodeName)
{
	auto it = isNodeExist(nodeName);
	if(it != m_AdjacencyList.end())
	{
		m_AdjacencyList.erase(it);
		return true;
	}
	else
	{
		std::cerr<<"ERROR: \n Invlid node name!\n";
		exit(0);
		return false;
	}

}
std::list<std::vector<std::string> >::iterator Graph::isNodeExist(std::string const &nodeName)const
{
	auto it = m_AdjacencyList.begin();
	while(it != m_AdjacencyList.end())
	{
		if(*(it->begin()) == nodeName)
			return it;
	} 
	return it;
}
bool Graph::isValidNodeName(std::string const &nodeName)
{
	return (nodeName.size()<4);
}
bool Graph::isEmpty() const 
{
	if(m_AdjacencyList.empty())
	{
		std::cerr<<"Graph is empty"<<std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////
bool Graph::isComplete() const
{
	int j=0;
	for(int i=0;i<m_GraphMatrix.size();++i)
	{
		for(j=i;j<m_GraphMatrix[i].size();++j)
		{
			if(m_GraphMatrix[i][j]=="0")
			{
				return false;
			}
		}
	}
	return true;
}

//detect smallest coonected compontnts and push it in m_minConnectedNode voector 
void Graph::SCCProblem()
{
	m_minConnectedNode.clear();

	int temp_min = std::count(m_GraphMatrix[1].begin(),m_GraphMatrix[1].end(),"1");
	m_minConnectedNode.push_back(m_GraphMatrix[0][1]);
	int size=m_GraphMatrix.size();
	int count=0;
	for(int i=2;i<size;++i)
	{
		count = std::count(m_GraphMatrix[i].begin(),m_GraphMatrix[i].end(),"1");
		if(temp_min>count)
		{
			temp_min=count;
			m_minConnectedNode.clear();
			m_minConnectedNode.push_back(m_GraphMatrix[i][0]);
		}
		else
		{
			if(temp_min==count)
			{
				m_minConnectedNode.push_back(m_GraphMatrix[i][0]);
			}
		}
	}
}

bool Graph::MaxIndependentset()
{
	std::vector<std::string> str;
	Wraper wrap_obj;
	if(!isComplete())
	{
		wrap_obj = SolveProblem(*this);
		std::cout<<"Max Independent set = "<<wrap_obj.getCount()<<"\n"; 
		str = wrap_obj.getStr();
		std::cout<<"List of MIS ";
		std::cout<<std::for_each(str.begin(),str.end(),[](std::string str){std::cout<<str<<" ,";});
		std::cout<<"\n";
		return true;
	}
	std::cout<<"Graph is Complete\n";
	return false;
}
Wraper Graph::SolveProblem(Graph obj)
{
	std::priority_queue<Wraper > max_queue;
	Wraper wrap_obj;
	
	if(obj.isComplete())
	{
		wrap_obj.addCount();
		wrap_obj.addStr(obj.m_GraphMatrix[0][1]);
		return wrap_obj;
	}
	if(obj.isEmpty())
	{
		return wrap_obj;
	}
	
	obj.SCCProblem();
	for(int i=0;i<obj.m_minConnectedNode.size();++i)
	{
		wrap_obj = SolveProblem(obj.removeAdjacentes(obj.m_minConnectedNode[i]));
		wrap_obj.addStr(obj.m_minConnectedNode[i]);
		max_queue.push(wrap_obj); 
	}
	wrap_obj = max_queue.top();
	wrap_obj.addCount();
	return wrap_obj;
}
Graph Graph::removeAdjacentes(std::string const &nodeName)
{
	Graph obj=*this;
	int it=obj.m_map.find(nodeName)->second;
	
	for(int i=1;i<obj.m_GraphMatrix.size();++i)
	{
		if(obj.m_GraphMatrix[it][i]=="1")
		{
			obj.deleteNode(obj.m_GraphMatrix[0].at(i));
			--i;
			if(i<it)
			{
				--it;
			}
		}
	}
	obj.deleteNode(nodeName);
	return obj;
}
