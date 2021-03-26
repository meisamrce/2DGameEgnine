#ifndef GAME_H
#define GAME_H

#include "Global.h"

class Game
{
    
    public:
        Game(unsigned int width,unsigned int height,const string &title);
        ~Game();
        void run();
        
private:
            void init();
            void processInput();
            void update();
            void render();
            void clean();
            bool m_Runing;
            GLFWwindow* m_Window;
            unsigned int m_Width;
            unsigned int m_Height;
            string m_Title;

};

#endif // GAME_H
