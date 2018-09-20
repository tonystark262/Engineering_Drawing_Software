/**
*	@file object3D.h
* 	@brief This file contains the class object3D which is used to model
*	a 3D object.
*/

#ifndef object3D_H
#define object3D_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>
#include "point.h"
#include "object2D.h"
#include "orthographic.h"

using namespace std;


extern "C"{

class object3D
{
private:
	vector <point> vertices;
	vector<vector<int> > edges;
	vector <glm::vec4> vertices_vec;
	int numberOfVertices;

    /**
    *fuction to order the vertices so that the all the vertices in the list of a vertex are in cyclic order in 3D angle.
    */
	void orderVertices();

public:
	/**
	*	Constructs a blank 3D figure
	*/
	object3D();

    /**
    *contructor of object3D class given the vertices coordinates and the connection of points stored in adjacency list.
    *@param vertices_vec_3d		vertices co-ordinates
    *@param line_3d		adjacency list of connection of points.
    */
	object3D(vector <glm::vec4> vertices_vec_3d , vector<vector<int> > line_3d);


    /**
    *	Function to interactively input the points and their connections in form of lines
    *	and then it check the consistency
    *	If inconsistent, raises exception else constructs the object.
    */
	object3D(orthographic obj);

	/**
	*	Function to input the 2D figure from file
	*	and then it check the consistency
	*	If inconsistent, raises exception else constructs the object.
	*	@param filename 	File to be taken as input
	*/
	void inputFromFile(string filename);

	/**
	*	Translates the 3D Figure to a different 3D location.
	*	@param x 	amount of translation in x-direction
	*	@param y 	amount of translation in y-direction
	*	@param z 	amount of translation in z-direction
	*/
	void translate(float x=0.0, float y=0.0, float z=0.0);

	/**
	*	Scales the 3D Figure proportionately
	*	@param x 	amount of scaling in x-direction
	*	@param y 	amount of scaling in y-direction
	*	@param z 	amount of scaling in z-direction
	*/
	void scale(float x=1.0, float y=1.0, float z=1.0);

	/**
	*	Rotates the figure around a given axis by a given angle
	*	@param theta	angle to be rotated by
	*	@param axis		axis about which object is to be rotated
	*/
	void rotate(float theta, line axis);

	/**
	*	Reflects an object about a given plane
	*	@param p 	plane about which to reflect
	*/
	void reflect(plane p);


	/**
	*	Projects the 3D Figure on a given plane
	* 	@param p 	plane on which to project
	*/
	object2D project(plane p);	// input as equation

	/**
	*	Calculates orthographic projections of the 3D Figure
	*/
	orthographic orthographic_projection();

	/**
	*	Calculates isometric projection of the 3D Figure
	*/
	object2D isometric_projection();

	/**
    *function to return the number of vertices in the object.
    */
	int getNumVer();

    /**
    *function to return all the coordinates of the 2d object
    */
    vector <glm::vec4> getVerVec();

    /**
    *function to return the edges between all the vertices of the object in form of adjacency list.
    */
    vector<vector<int> > getEdges();
};
}
#endif
