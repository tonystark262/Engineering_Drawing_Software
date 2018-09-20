#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <string>
#include <vector>
#include<cmath>
#include "point.h"
#include "object2D.h"
#include "orthographic.h"
#include "object3D.h"
#include<utility>
#include<algorithm>

using namespace std;

extern float rX;
extern float rY;
extern int global_argc;
extern char **global_argv;
extern object3D rendering_obj3D;
extern object3D global_obj3D;
extern object2D rendering_obj2D, global_obj2D;
extern orthographic rendering_objOrtho, global_orthoObj;

/**
*function to initialize the glut window for display
*/
void initialiseGlut();

/**
*function to display the axis in the glut display window
*/
void drawAxis();

/**
*function to display axis in orthographic view
*/
void drawAxisOrtho();

/**
*function to control the 3D figure rotation from the keyboard arrow keys
*/
void keyboard(int key, int x, int y);

/**
*function to draw a line in the glut window between two points
@param v1 		takes first input vertex as glm vector
@param v2 		takes second input vertex as glm vector
*/
void makeLine(glm::vec4 v1, glm::vec4 v2);

/**
*function to clear the glut screen in wireframe model
*/
void clear();

/**
*function to clear the glut screen in the 3D models
*/
void clearSolid();

/**
*function to render 3D wireframe model
*/
void renderWire3D();

/**
*function to render 2D wireframe model
*/
void renderWire2D();

/**
*function to draw triangle between 3 points and make surface from the normal
*@param a 		first vertex
*@param b 		second vertex
*@param c 		third vertex
*@param d 		normal vector to the surface
*/
void makeTriangle(glm::vec4 a,glm::vec4 b, glm::vec4 c,glm::vec3 d);

/**
*function to take the cross product of two vectors
*/
glm::vec3 cross(glm::vec4 a,glm::vec4 b);

/**
*function to render 3D solid model with surface shading
*/
void renderSolid3D();

/**
*function to actually setup call back functions for rendering 3D wireframe object
*/
void makeWireFrame(object3D obj);

/**
*function to actually setup call back functions for rendering 2D wireframe object
*/
void makeWireFrame(object2D obj);

/**
*function to actually setup call back functions for rendering 3D solid model
*/
void makeSolid(object3D obj);

/**
*function to actually setup call back functions for rendering orthographic views
*/
void makeOrthographic(orthographic obj);

/**
*function to display the orthographic views on the glut screen
*/
void renderOrtho();

/**
*function to correctly translate the orthographic views for display
*/
void translatedRender(glm::vec4 tr,glm::vec4 sca, int view_number);

/**
*function to rotate the coordinate system for orthographic views.
*/
glm::vec4 changeCoord(glm::vec4 ver,int view_number);

void makeIsometric(object2D obj);
void renderWireIso();
#endif

