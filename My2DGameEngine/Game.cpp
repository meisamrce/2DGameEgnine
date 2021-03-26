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
    
    glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


    
    m_Window = glfwCreateWindow(m_Width, m_Height,m_Title.c_str(), NULL, NULL);
    
     if (!m_Window)
     {
         cout << "Error glfwCreateWindow " << endl;
         return;
     }
    
    
    glfwMakeContextCurrent(m_Window);//create opengl context
    
    cout << glGetString(GL_VERSION) << endl;
    cout << glGetString(GL_RENDERER) << endl;
    cout << glGetString(GL_VENDOR) << endl;
    cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;


    
    m_Runing = true;


    //RGBA
   //0.0 to 1.0 
   // 0 1.0 0 1.0  
    glClearColor(0.0f,1.0f,0.0f,1.0f);//background window green
    
    
    
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    
    float vertexData[] = {
        0.0f,1.0f, //v1-x,y
        -1.0f,-1.0f, //v2-x,y
        1.0f,-1.0f, //v3-x,y        
    };
    
    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),vertexData,GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);//position
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float),(void*)0);
    
    
    glBindBuffer(GL_ARRAY_BUFFER,0);//unbind
    glBindVertexArray(0);


    //vertex shader
    const char * vs =  "#version 410\n"
    "layout ( location = 0 ) in vec2 vertexPosition;\n"
    "void main() {\n"
    "gl_Position = vec4(vertexPosition.xy,0.0,1.0);\n"
    "}\0";
    
    GLuint vsid;
    vsid = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vsid,1,&vs,NULL);
    glCompileShader(vsid);

    
    
    
    //fragment shader
    const char * fs =  "#version 410\n"
    "out vec4 color;\n"
    "void main(){\n"
    "color = vec4(1.0,0.0,0.0,1.0);\n"
    "}\0";
    
    GLuint fsid;
    fsid = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fsid,1,&fs,NULL);
    glCompileShader(fsid);

    //shader program
    sp = glCreateProgram();
    glAttachShader(sp,vsid);
    glAttachShader(sp,fsid);
    glLinkProgram(sp);
    
    
}

void Game::processInput()
{
    //cout << "processInput" << endl;
}

void Game::update()
{
    //cout << "update" << endl;
}

void Game::render()
{
   // cout << "render" << endl;
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    /*
            opengl draw
     */
     
     glUseProgram(sp);
     glBindVertexArray(VAO);
     glDrawArrays(GL_TRIANGLES,0,3);
    
    
    glfwSwapBuffers(m_Window);
    glfwPollEvents();

}

void Game::clean()
{
    cout << "clean" << endl;
    
    if(m_Window)
    {
        glfwDestroyWindow(m_Window);
        m_Window = NULL;
    }
    
    glfwTerminate();
}