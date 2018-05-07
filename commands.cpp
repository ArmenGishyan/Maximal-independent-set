#include "commands.h"

Commands::Commands()
{
    std::fstream file;
    file.open("commandsFile.txt",std::ios::in);
    if(!file.is_open())
    {
        std::cerr<<"ERROR \n File is not open!\n";
        std::terminate();
    }

    std::string str;
    int index=0;
    while(!file.fail())
    {
        getline(file,str);
        m_mCommand.insert(m_mCommand.begin(),CommandPair(str,index));
        index++;
    }
    file.close();
}
void Commands::execute()
{
    static int invalidCommandcount=0;
    try
    {
        switch (findCommand(m_validcommand.getCommand().at(0)))
        {
            case -1:
                {
                    std::cerr<<"ERROR \n Invalid command"<<std::endl;
                    invalidCommandcount++;
                    if(invalidCommandcount>4)
                    {
                        std::cerr<<"ERROR \n Please write valid commands\n";
                        std::terminate();
                    }
                    else
                    {
                        commandInput();
                    }
                }
            case 0:
                {
                    create();
                    invalidCommandcount=0; 
                    commandInput();
                    break;
                }
            case 1:
                {
                    connect();
                    invalidCommandcount=0; break;
                }
            case 2:
                {
                    disconnect(); 
                    invalidCommandcount=0; break;
                }
            case 3:
                {
                    _delete(); 
                    invalidCommandcount=0;break;
                }
            case 4:
                {
                    add();
                    invalidCommandcount=0;break;
                }
            case 5:
                {
                    print();
                    invalidCommandcount=0; break;
                }
            case 6:
                {
                    MISet();
                    invalidCommandcount=0;break;
                }    
            case 7:
                {
                    std::cout<<"Program successfully closed!\n";
                    exit(0);
                }
        }
    }
    catch(const std::out_of_range& oor)
    {
        commandInput();
    }
}
void Commands::commandInput()
{
    static std::string str="";
    while(true)
    {
        std::cout<<"Waiting command > ";
        getline(std::cin,str);
        m_validcommand.setCommand(helper::split(str));
        execute();
    }
}
int Commands::findCommand(std::string const &str)
{
    auto it= m_mCommand.find(str);
    if(it==m_mCommand.end())
    {
        return -1;
    }
    else
    {
        return it->second;
    }
}
void Commands::create()
{
    if(!m_validcommand.create())
    {
        commandInput();
    }
    else
    {
        if(m_validcommand.getCommand().size()==2)
        {
            Graph obj(helper::strToint(m_validcommand.getCommand()[1]));   
            m_graph=obj;
            std::cout<<"Graph "<<"A"<<"  was successfully created!"<<std::endl;
        }
        else
        {
            Graph obj(helper::strToint(m_validcommand.getCommand()[1]),m_validcommand.getCommand()[2]);
            m_graph=obj;
            std::cout<<"Graph "<<m_validcommand.getCommand()[2]<<"  was successfully created!"<<std::endl;
        }
    }
}
void Commands::connect()
{
    if(!m_graph.isEmpty() && !m_validcommand.connect())
    {
        commandInput();
    }
    else
    {
        if
        (
            !m_graph.toConnect
            (
                m_validcommand.getCommand()[1],
                m_validcommand.getCommand()[2] 
            )
        )
        {
            commandInput();
        }
    }
}
void Commands::print() 
{
    if(m_validcommand.print() && !m_graph.isEmpty())
    {
        m_graph.printGraphMatrix();
    }
    else
    {
        commandInput();
    }
}
void Commands::disconnect()
{
    if(m_validcommand.disconnect() && !m_graph.isEmpty())
    {
        if(m_graph.toDisconnect(m_validcommand.getCommand()[1],m_validcommand.getCommand()[2]))
        {
            commandInput();
        }
    }
    else
    {
        commandInput();
    }
}
void Commands::_delete()
{
    if(!m_validcommand._delete() && !m_graph.isEmpty())
    {
        commandInput();
    }
    else
    {
        if(!m_graph.deleteNode(m_validcommand.getCommand()[1]))
        {
            commandInput();
        }
    }
}
void Commands::add()
{
    if(!m_validcommand.addNode() && !m_graph.isEmpty())
    {
        commandInput();
    }
    else
    {
        if(!m_graph.addNode(m_validcommand.getCommand()[1]))
        {
            commandInput();
        }
    }
}
void Commands::MISet() 
{
    if(!m_validcommand.MISet() ||  !m_graph.MaxIndependentset())
    {
        commandInput();
    }
    
   
}