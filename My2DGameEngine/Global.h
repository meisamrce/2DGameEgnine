#ifndef GLOBAL_H
#define GLOBAL_H


#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_NONE

#include <vector>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

using namespace std;


#define DELETE_SAFE(obj) {delete obj;obj = NULL;}

#endif