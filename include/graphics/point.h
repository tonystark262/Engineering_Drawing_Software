/**
*	@file point.h
* 	@brief This file contains the classes used to model
*	various geometric objects such as point, line and a plane
*/


#ifndef POINT_H
#define POINT_H
using namespace std;

class point{
	private:
		float x,y,z;
	public:
		/**
		*class to store the point for the graphics object
		*@param x_coord		X-coordinate with default initilisation zero
		*@param y_coord		Y-coordinate with default initilisation zero
		*@param z_coord		Z-coordinate with default initilisation zero
		*/
		point(float x_coord, float y_coord, float z_coord);

		/**
		*input the x,y,z coordinate in that order from stdin
		*/
		void inputPoint();

		/**
		*returns the x-coordinate of the point
		*/
		float getX();

		/**
		*returns the y-coordinate of the point
		*/
		float getY();

		/**
		*returns the z-coordinate of the point
		*/
		float getZ();
};

class line
{
private:
	point direction;
public:
	line(point p1,point p2);
	line(float a,float b,float c);
	/**
	*	@return direction pointed to by the line
	*/
	point getDirection();

};

class plane
{
	float a,b,c,d;
	point normal;
public:
	plane(float A, float B, float C, float D);
	plane(point p, line nor);

	/**
	*	Returns an array containing the co-efficients of the plane a,b,c,d respectively
	*/
	float* getCoefficients();

	/**
	*	Returns the normal of the plane
	*	@return A vector representing the components along x, y, and z directions
	*/
	point getNormal();

};
#endif
