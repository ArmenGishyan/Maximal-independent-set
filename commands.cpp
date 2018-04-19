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
    switch (findCommand(m_validcommand.getCommand()[0]))
    {
        case -1:
            {
                std::cerr<<"ERROR \n Invalid command"<<std::endl;
                invalidCommandcount++;
                if(invalidCommandcount>5)
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
                //connect(v_str);
                invalidCommandcount=0; break;
            }
        case 2:
            {
               // disconnect(v_str); 
                invalidCommandcount=0; break;
            }
        case 3:
            {
                //_delete(v_str); 
                invalidCommandcount=0;break;
            }
        case 4:
            {
               // add(v_str);
                invalidCommandcount=0;break;
            }
    }

}
void Commands::commandInput()
{
    static std::string token="";
    static  char c_char=' ';
    m_validcommand.clear();
    
    std::cout<<"Waiting command: > ";
    
    do
    {
        while(true)
        {
            std::cin.get(c_char);
            if(c_char==' ' || std::cin.peek()==EOF) break;
            token+=c_char;
        }
        m_validcommand.setToken(token);
        token="";
    }
    while(std::cin.peek()!='\n');
    std::cout<<std::endl;
    execute();
    
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
        }
        else
        {
            Graph obj(helper::strToint(m_validcommand.getCommand()[1]),m_validcommand.getCommand()[2]);
            m_graph=obj;
            std::cout<<"Graph "<<m_validcommand.getCommand()[2]<<"  was successfully created!"<<std::endl;
        }
    }
}