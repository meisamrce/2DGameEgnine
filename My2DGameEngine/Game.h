#ifndef GAME_H
#define GAME_H


#include "Engine.h"
#include "Sprite.h"
#include "Camera2D.h"

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
            
            Sprite * s1;
            Sprite *s2;
            
            float m;
            
            
};

#endif // GAME_H
