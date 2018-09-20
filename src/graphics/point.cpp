#include<iostream>
#include "point.h"

using namespace std;

point::point(float x_coord=0, float y_coord=0, float z_coord=0)
{
	x = x_coord;
	y = y_coord;
	z = z_coord;
}

void point::inputPoint()
{
	cout<<"\nEnter the coordinates: ";
	cin>>x>>y>>z;
}

float point::getX()
{
	return x;
}

float point::getY()
{
	return y;
}

float point::getZ()
{
	return z;
}

line::line(point p1,point p2)
{
	float a,b,c ;
	a = p1.getX()-p2.getX();
	b = p1.getY()-p2.getY();
	c = p1.getZ()-p2.getZ();
	direction = point(a,b,c);
}

line::line(float a,float b,float c)
{
	direction = point(a,b,c);
}

point line::getDirection()
{
	return direction;
}

plane::plane(float A, float B, float C, float D)
{
	a=A;
	b=B;
	c=C;
	d=D;
	normal = point(a,b,c);
}

plane::plane(point p, line nor)
{
	point t = nor.getDirection();
	a = t.getX();
	b = t.getY();
	c = t.getZ();
	d = 0.0 - a*p.getX() - b*p.getY() - c*p.getZ();
}

float* plane::getCoefficients()
{
	float* temp=new float[4];
	temp[0]=a;temp[1]=b;temp[2]=c;temp[3]=d;
	return temp;
}

point plane::getNormal()
{
	return normal;
}