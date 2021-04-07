#ifndef TOOLS_H
#define TOOLS_H

#include "Global.h"

class Tools
{
    public:
            static Tools * getInstance();
            string toString(int value);
            string toString(unsigned int value);
            string toString(float value);
            string toString(double value);
            string toString(char value);
            string toString(bool value);
            string toString(const char * value);
            string toString(const GLubyte * value);
            string toString(const std::vector<char> &data);
            string getDateTime();
    private:
            static Tools * m_Instance;
            Tools();
            ~Tools() {} ;
            Tools(Tools &other) = delete;
            void operator=(const Tools &) = delete;

        


    
};

#endif // TOOLS_H
