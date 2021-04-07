#include "Logger.h"

Logger * Logger::m_Instance = NULL;

Logger* Logger::getInstance()
{
    if(m_Instance == NULL)
        m_Instance = new Logger();
    
    return m_Instance;
}


void Logger::init()
{
    m_File = new ofstream("log.txt");
}

void Logger::clean()
{
    m_File->close();
    DELETE_SAFE(m_File);
}

void Logger::log(string data,const char * filename,unsigned int lineNumber,LogMode lm)
{
    string logMode;
    if(lm == LM_INFO)
            logMode = "[INFO]";
    else if(lm == LM_ERROR)
            logMode = "[ERROR]";
    else
            logMode = "[DEBUG]";
            
    string logString;
    
    
    logString = logMode + "-"  + Tools::getInstance()->getDateTime() +  "-[" +  Tools::getInstance()->toString(filename) + ":" +  Tools::getInstance()->toString(lineNumber) +  "]-" +  data  + "\n";
    
    cout << logString;
    (*m_File) << logString;
}
