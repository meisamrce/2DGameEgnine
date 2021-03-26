#include "Game.h"

Game::Game(unsigned int width,unsigned int height,const string &title)
{
    m_Width = width;
    m_Height = height;
    m_Title = title;
    this->init();
}

Game::~Game()
{
    this->clean();
}

void Game::run()
{
    
    while(!glfwWindowShouldClose(m_Window) && m_Runing)
    {
        this->processInput();
        this->update();
        this->render();
    }

    
}

void Game::init()
{
    
    cout << "Init" << endl;
    
    if (!glfwInit())
    {
        cout << "Error glfwInit " << endl;
        return;
    }
    
    m_Window = glfwCreateWindow(m_Width, m_Height,m_Title.c_str(), NULL, NULL);
    
     if (!m_Window)
     {
         cout << "Error glfwCreateWindow " << endl;
         return;
     }
    
    
    glfwMakeContextCurrent(m_Window);//create opengl context
    
    m_Runing = true;


    //RGBA
   //0.0 to 1.0 
   // 0 1.0 0 1.0  
    glClearColor(0.0f,1.0f,0.0f,1.0f);//background window green
    
}

void Game::processInput()
{
    cout << "processInput" << endl;
}

void Game::update()
{
    cout << "update" << endl;
}

void Game::render()
{
    cout << "render" << endl;
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    /*
            opengl draw
     */
    
    
    glfwSwapBuffers(m_Window);
    glfwPollEvents();

}

void Game::clean()
{
    cout << "clean" << endl;
    glfwTerminate();
}