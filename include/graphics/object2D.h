/**
*	@file object2D.h
* 	@brief This file contains the class object2D, which is used to model
*	a 2D figure.
*/

#ifndef object2D_H
#define object2D_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include<iostream>
#include<fstream>
#include "point.h"
#include<vector>
#include<string>
using namespace std;

class object2D
{
	private:
		vector<point> vertices;
		vector<vector<int> > edges;
		vector <glm::vec4> vertices_vec;
		int numberOfVertices;

	public:
		/**
		*constructor for the 2D figure class
		*/
		object2D();

		object2D(vector <glm::vec4> vertices_vec_2d , vector< vector<int> > line_2d);

		/**
		*function to input the 2D figure from file
		*@param filename		File to be taken as input
		*Then it check the consistency
		*If inconsistant, raises exception else constructs the object
		*/
		void inputFromFile(string filename);

        /**
        *function to return all the coordinates of the 2d object
        */
        vector<glm::vec4> getVec();

        /**
        *function to return the edges between all the vertices of the object in form of adjacency list.
        */
        vector<vector<int> > getEdges();

        /**
        *function to return the number of vertices in the object.
        */
        int getNumVer();
};


#endif
