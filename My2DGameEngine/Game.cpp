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
    
    Logger::getInstance()->init();
    
    iLog("Init");
    
    if (!glfwInit())
    {
        eLog("glfwInit Error!");
        return;
    }
    
    glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


    
    m_Window = glfwCreateWindow(m_Width, m_Height,m_Title.c_str(), NULL, NULL);
    
     if (!m_Window)
     {
         eLog("glfwCreateWindow Error!");
         return;
     }
    
    
    glfwMakeContextCurrent(m_Window);//create opengl context
    
    iLog("OpenGL Version : " + Tools::getInstance()->toString(glGetString(GL_VERSION)));
    iLog("OpenGL Shader Version : " + Tools::getInstance()->toString(glGetString(GL_SHADING_LANGUAGE_VERSION)));
    iLog("Renderer : " + Tools::getInstance()->toString(glGetString(GL_RENDERER)));


    
    m_Runing = true;


    //RGBA
   //0.0 to 1.0 
   // 0 1.0 0 1.0  
    glClearColor(0.0f,0.0f,0.0f,0.0f);//background window green
    
    
    
    s1 = new Sprite("media/shaders/sprite.vert","media/shaders/sprite.frag");
    
    
}

void Game::processInput()
{
}

void Game::update()
{
}

void Game::render()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
         
    s1->draw();
    
    glfwSwapBuffers(m_Window);
    glfwPollEvents();

}

void Game::clean()
{
    iLog("Clean");
    
    DELETE_SAFE(s1);
    
    if(m_Window)
    {
        glfwDestroyWindow(m_Window);
        m_Window = NULL;
    }
    
    glfwTerminate();
    
    Logger::getInstance()->clean();
    
}