#ifndef VERTEX_H
#define VERTEX_H


struct Position
{
    float x;
    float y;
};

struct UV
{
    float u;
    float v;
};



struct Vertex
{
    Position position;
    UV uv;
    
    void setPostion(float x,float y)
    {
        position.x = x;
        position.y = y;
    }
    
    void setUV(float u,float v)
    {
        uv.u = u;
        uv.v = v;
    }
  
};



#endif