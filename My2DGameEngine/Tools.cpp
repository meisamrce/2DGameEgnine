#include "Tools.h"

Tools * Tools::m_Instance = NULL;

Tools::Tools()
{
}


string Tools::toString(int value)
{
    stringstream str;
    str << value;
    return str.str();
}

string Tools::toString(unsigned int value)
{
    stringstream str;
    str << value;
    return str.str();
}

string Tools::toString(float value)
{
    stringstream str;
    str << value;
    return str.str();
}

string Tools::toString(double value)
{
    stringstream str;
    str << value;
    return str.str();
}

string Tools::toString(char value)
{
    stringstream str;
    str << value;
    return str.str();
}

string Tools::toString(bool value)
{
    return (value) ? "true" : "false";
}

string Tools::toString(const char * value)
{
    stringstream str;
    str << value;
    return str.str();
}

string Tools::toString(const GLubyte * value)
{
    stringstream str;
    str << value;
    return str.str();
}

Tools* Tools::getInstance()
{
    if(m_Instance == NULL)
        m_Instance = new Tools();
    
    return m_Instance;
}


string Tools::getDateTime()
{
    time_t currentTime = time(NULL);
    tm * tmObj = localtime(&currentTime);
    char buffer[100];
    strftime(buffer,100,"[%Y-%m-%d %H:%M:%S]",tmObj);
    return buffer;
}


string Tools::toString(const std::vector<char> &data)
{
    string str(data.begin(), data.end());
    return str;
}
