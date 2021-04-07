#ifndef ENGINE_H
#define ENGINE_H

#include "Logger.h"

#define eLog(x) Logger::getInstance()->log(x,__FILE_NAME__,__LINE__,LM_ERROR);
#define dLog(x) Logger::getInstance()->log(x,__FILE_NAME__,__LINE__,LM_DEBUG);
#define iLog(x) Logger::getInstance()->log(x,__FILE_NAME__,__LINE__,LM_INFO);



#endif