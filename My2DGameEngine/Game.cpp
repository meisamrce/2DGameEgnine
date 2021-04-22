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
    
    SDL_Init(SDL_INIT_EVERYTHING);
    ilInit();
    
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

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    
    
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
    
    Camera2D::getInstance()->init(m_Width,m_Height);
            
    
    s1 = new Sprite("media/textures/elf.png","media/shaders/sprite.vert","media/shaders/sprite.frag");
    s1->setPosition(glm::vec2(100,100));
    s1->setColor(Color(255,0,255,255));
    s2 = new Sprite("media/textures/elf.png","media/shaders/sprite.vert","media/shaders/sprite.frag");
    s2->setPosition(glm::vec2(100,400));
   
    
    
}

void Game::processInput()
{
}

void Game::update()
{
    Camera2D::getInstance()->update();
    
}

void Game::render()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
         
    s1->draw();
    s2->draw();
    
    
    glfwSwapBuffers(m_Window);
    glfwPollEvents();

}

void Game::clean()
{
    iLog("Clean");
    
    DELETE_SAFE(s1);
    DELETE_SAFE(s2);

    
    SDL_Quit();
    ilShutDown();
    
    if(m_Window)
    {
        glfwDestroyWindow(m_Window);
        m_Window = NULL;
    }
    
    glfwTerminate();
    
    Logger::getInstance()->clean();
    
}