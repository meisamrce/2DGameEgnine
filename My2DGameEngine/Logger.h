#ifndef LOGGER_H
#define LOGGER_H

#include "Tools.h"

enum LogMode
{
    LM_DEBUG,
    LM_INFO,
    LM_ERROR
};

class Logger
{
    public:
        static Logger * getInstance();
        void init();
        void clean();
        void log(string data,const char * filename,unsigned int lineNumber,LogMode lm = LogMode::LM_DEBUG);

    private:
        Logger() {};
        ~Logger() {};
        static Logger * m_Instance;
        Logger(Logger &other) = delete;
        void operator=(const Logger &) = delete;
        ofstream * m_File;


};

#endif // LOGGER_H
