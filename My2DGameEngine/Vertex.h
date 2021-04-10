#ifndef VERTEX_H
#define VERTEX_H


struct Position
{
    float x;
    float y;
};


struct Vertex
{
    Position position;
    
    void setPostion(float x,float y)
    {
        position.x = x;
        position.y = y;
    }
  
};



#endif