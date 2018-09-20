/**
*	@file orthographic.h
* 	@brief This file contains the class orthographic which is used to model orthographic projections of
*	a 3D object.
*/


#ifndef ORTHOGRAPHIC_H
#define ORTHOGRAPHIC_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "object2D.h"
#include <string>

using namespace std;


class orthographic
{
	private:
		
	public:

		object2D front,side,top;
		/**
		*constructor of the orthographic views
		@param f		Takes the reference of the front view 2D object
		@param ba		Takes the reference of the back view 2D object
		@param l		Takes the reference of the left view 2D object
		@param r		Takes the reference of the right view 2D object
		@param t		Takes the reference of the top view 2D object
		@param bo		Takes the reference of the bottom view 2D object
		*/
		orthographic(object2D f, object2D s, object2D t);
		orthographic();

		/**
		*@param filename		File from which input is taken.
		*/
		void inputFromFile(string filename);

};

#endif
