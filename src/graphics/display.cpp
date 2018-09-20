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
#include "display.h"

float rX = 0.0;
float rY = 0.0;

int global_argc;
char **global_argv;

object3D rendering_obj3D,global_obj3D=object3D();
object2D rendering_obj2D, global_obj2D=object2D();
orthographic rendering_objOrtho, global_orthoObj=orthographic();

void initialiseGlut()
{
	glutInit(&global_argc, global_argv);

        // Request float buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100, 100);

    // Create window
    glutCreateWindow("OpenGL Cube");
}

void drawAxisOrtho()
{
	glBegin(GL_LINES);
		glVertex3f(0.0f, -4.0f, 0.0f);
		glVertex3f(0.0f, 4.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-4.0f, 0.0f, 0.0f);
		glVertex3f(4.0f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, -4.0f);
		glVertex3f(0.0f, 0.0f, 4.0f);
	glEnd();
}

void drawAxis()
{
	glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();
}

void keyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        {
                rY += 5;
        }
    else if (key == GLUT_KEY_LEFT)
        {
                rY -= 5;
        }
    else if (key == GLUT_KEY_DOWN)
        {
                rX -= 5;
        }
    else if (key == GLUT_KEY_UP)
        {
                rX += 5;
        }

    // Request display update
    glutPostRedisplay();
}

void makeLine(glm::vec4 v1, glm::vec4 v2)
{
	glBegin(GL_LINES);
		glVertex3f(v1[0], v1[1], v1[2]);
		glVertex3f(v2[0], v2[1], v2[2]);
	glEnd();
}

void clear()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	glRotatef(rX, 1.0, 0.0, 0.0);
	glRotatef(rY, 0.0, 1.0, 0.0);

    glColor3f(0.0,0.0,0.0);
}

void clearSolid()
{
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Enable shading
    glShadeModel(GL_SMOOTH);

    // Set up the projection parameters
    glMatrixMode(GL_PROJECTION);

	glOrtho(-1.0, 1.0, -1.0, 1.0, -3.0, 3.0);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    // Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[]	= {0.0, 1.0, -.5, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

    glClearColor(1.0,1.0,1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(rX, 1.0, 0.0, 0.0);
	glRotatef(rY, 0.0, 1.0, 0.0);

    glColor3f(0.5,0.5,0.5);

    //material prop
    GLfloat qaBlack[] = {0.5, 0.5, 0.5, 1.0};
	GLfloat qaGreen[] = {0.0, 1.0, 0.0, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBlack);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaBlack);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
    drawAxis();
}

void renderWire3D()
{
	clear();
    drawAxis();
	int numberOfVertices = rendering_obj3D.getNumVer();
	vector <glm::vec4> vertices_vec = rendering_obj3D.getVerVec();
	vector<vector<int> > edges = rendering_obj3D.getEdges();

	int visited[numberOfVertices];
	for(int i=0;i<numberOfVertices;++i)
	{
		visited[i]=0;
	}
	for(int i=0;i<numberOfVertices;++i)
	{
		vector<int> neighbours = edges[i];
		visited[i] = 1;
		for(int j=0;j<neighbours.size();++j)
		{
			int neigh = neighbours[j];
			if(visited[neigh]==0)
			{
				makeLine(vertices_vec[i],vertices_vec[neigh]);
			}
		}
	}
	glFlush();
	glutSwapBuffers();
}

void renderWire2D()
{
	clear();
    drawAxis();
	int numberOfVertices = rendering_obj2D.getNumVer();
	vector <glm::vec4> vertices_vec = rendering_obj2D.getVec();
	vector<vector<int> > edges = rendering_obj2D.getEdges();

	int visited[numberOfVertices];
	for(int i=0;i<numberOfVertices;++i)
	{
		visited[i]=0;
	}
	for(int i=0;i<numberOfVertices;++i)
	{
		vector<int> neighbours = edges[i];
		visited[i] = 1;
		for(int j=0;j<neighbours.size();++j)
		{
			int neigh = neighbours[j];
			if(visited[neigh]==0)
			{
				makeLine(vertices_vec[i],vertices_vec[neigh]);
			}
		}
	}
	glFlush();
	glutSwapBuffers();
}

void renderWireIso()
{
    clear();
    int numberOfVertices = rendering_obj2D.getNumVer();
    vector <glm::vec4> vertices_vec = rendering_obj2D.getVec();
    vector<vector<int> > edges = rendering_obj2D.getEdges();

    int visited[numberOfVertices];
    for(int i=0;i<numberOfVertices;++i)
    {
        visited[i]=0;
    }
    for(int i=0;i<numberOfVertices;++i)
    {
        vector<int> neighbours = edges[i];
        visited[i] = 1;
        for(int j=0;j<neighbours.size();++j)
        {
            int neigh = neighbours[j];
            if(visited[neigh]==0)
            {
                makeLine(vertices_vec[i],vertices_vec[neigh]);
            }
        }
    }
    glFlush();
    glutSwapBuffers();
}

void makeTriangle(glm::vec4 a,glm::vec4 b, glm::vec4 c,glm::vec3 d)
{
	glBegin(GL_TRIANGLES);
	glNormal3f(-d[0],-d[1],-d[2]);
	glVertex3f(a[0],a[1],a[2]);
	glVertex3f(b[0],b[1],b[2]);
	glVertex3f(c[0],c[1],c[2]);
	glEnd();
}

glm::vec3 cross(glm::vec4 a,glm::vec4 b)
{
	glm::vec3 a1 = glm::vec3(a[0],a[1],a[2]);
	glm::vec3 b1 = glm::vec3(b[0],b[1],b[2]);
	return glm::cross(a1,b1);
}

void renderSolid3D()
{
	clearSolid();
    glColor3f(0.6,0.6,0.6);
	int numberOfVertices = rendering_obj3D.getNumVer();
	vector <glm::vec4> vertices_vec = rendering_obj3D.getVerVec();
	vector<vector<int> > edges = rendering_obj3D.getEdges();

	for(int i=0;i<numberOfVertices;++i)
	{
		glm::vec4 start = vertices_vec[i];
		vector<int> neigh = edges[i];
		for(int j=0;j<neigh.size();++j)
		{
			int n1= neigh[j],n2=neigh[0];
			if(j<neigh.size()-1)
			{
				n2=neigh[j+1];
			}
			glm::vec4 ne1 = vertices_vec[n1], ne2 = vertices_vec[n2];
			glm:: vec3 normal = cross(ne1-start,ne2-start);
			makeTriangle(start,ne1,ne2,normal);
		}
	}	
	glFlush();
	glutSwapBuffers();
}

glm::vec4 changeCoord(glm::vec4 ver,int view_number)
{
	glm::vec4 temp = glm::vec4();
    if(view_number==1)
	{
		temp[0]=ver[1];
		temp[1]=ver[2];
		temp[2]=0.0f;
		temp[3]=ver[3];
		return temp;
	}
    if(view_number==3)
	{
		temp[1]=ver[0];
		temp[0]=ver[2];
		temp[2]=0.0f;
		temp[3]=ver[3];
		return temp;
    }
	return ver;
}

void translatedRender(glm::vec4 tr,glm::vec4 sca, int view_number)
{
	
	int numberOfVertices = rendering_obj2D.getNumVer();
	vector <glm::vec4> vertices_vec = rendering_obj2D.getVec();
	vector<vector<int> > edges = rendering_obj2D.getEdges();

	int visited[numberOfVertices];
	for(int i=0;i<numberOfVertices;++i)
	{
		visited[i]=0;
	}
	for(int i=0;i<numberOfVertices;++i)
	{
		vector<int> neighbours = edges[i];
		visited[i] = 1;
		for(int j=0;j<neighbours.size();++j)
		{
			int neigh = neighbours[j];
            if(visited[neigh]==0)
			{
				glm::vec4 t1,t2;
                t1=changeCoord(vertices_vec[i],view_number);
                t2=changeCoord(vertices_vec[neigh],view_number);
                makeLine(t1*sca+tr,t2*sca+tr);
			}
		}
	}
	
	
}

void renderOrtho()
{
	clear();
	drawAxisOrtho();
	rendering_obj2D = rendering_objOrtho.front;
    translatedRender(glm::vec4(0.2f,-0.2f,0.0f,0.0f),glm::vec4(1.0f,-1.0f,0.0f,0.0f),1);
	rendering_obj2D = rendering_objOrtho.top;
    translatedRender(glm::vec4(0.2f,0.2f,0.0f,0.0f),glm::vec4(1.0f,1.0f,0.0f,0.0f),2);
	rendering_obj2D = rendering_objOrtho.side;
    translatedRender(glm::vec4(-0.2f,-0.2f,0.0f,0.0f),glm::vec4(-1.0f,-1.0f,0.0f,0.0f),3);
	glFlush();
	glutSwapBuffers();
}

void makeWireFrame(object3D obj)
{
	initialiseGlut();
	rendering_obj3D = obj;
	glutDisplayFunc(renderWire3D);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}

void makeWireFrame(object2D obj)
{
    float tempX=rX;
    float tempY=rY;
    rX=0;
    rY=0;
	initialiseGlut();
    rendering_obj2D = obj;
    glutDisplayFunc(renderWire2D);
    glutSpecialFunc(keyboard);
	glutMainLoop();
    rX=tempX;
    rY=tempY;
}

void makeIsometric(object2D obj)
{
    float tempX=rX;
    float tempY=rY;
    rX=0;
    rY=0;
    initialiseGlut();
    rendering_obj2D = obj;
    glutDisplayFunc(renderWireIso);
    glutMainLoop();
    rX=tempX;
    rY=tempY;
}

void makeSolid(object3D obj)
{
	initialiseGlut();
	rendering_obj3D = obj;
	glutDisplayFunc(renderSolid3D);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}

void makeOrthographic(orthographic obj)
{
    initialiseGlut();
    rendering_objOrtho = obj;
    rX = 0;
    rY = 0;
    glutDisplayFunc(renderOrtho);
//	 glutSpecialFunc(keyboard);
    glutMainLoop();
}

