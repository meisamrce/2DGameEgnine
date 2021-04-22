#ifndef GLOBAL_H
#define GLOBAL_H


#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_NONE

#include <cmath>
#include <cstddef>
#include <vector>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <SDL.h>
#include <IL/il.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


using namespace std;


#define DELETE_SAFE(obj) {delete obj;obj = NULL;}

#endif