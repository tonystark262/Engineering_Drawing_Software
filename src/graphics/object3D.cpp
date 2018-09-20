#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <GL/glut.h>

#include <string>
#include <sstream>
#include <vector>
#include<fstream>
#include<cmath>
#include "point.h"
#include "object2D.h"
#include "orthographic.h"
#include "object3D.h"
#include<utility>
#include<algorithm>

using namespace std;

void object3D::orderVertices()
{
	for(int i=0;i<numberOfVertices;++i)
	{
		int cou = 0;
		int flag=0;
		glm::vec4 start = vertices_vec[i];
		if(start[2]==0.0f)
		{
			flag=1;
			start[2]+=1.0f;
		}
		vector<int> neigh = edges[i];
		glm::vec4 final_loc[neigh.size()];
		glm::vec4 cent = glm::vec4(0.0f,0.0f,0.0f,0.0f);
		for(int j=0;j<neigh.size();++j)
		{
			glm::vec4 v = vertices_vec[neigh[j]];
			if(flag==1)
			{
				v[2]+=1.0f;	
			}
			float lambda = start[2]/(start[2] -v[2]);
			if(lambda>0.0f)
			{
				cou++;
			}
			final_loc[j][3]=1.0f;
			final_loc[j][2]=0.0f;
			final_loc[j][1]=start[1]+lambda*(v[1]-start[1]);
			final_loc[j][0]=start[0]+lambda*(v[0]-start[0]);
			cent+=final_loc[j];
		}
		cent/=((float)numberOfVertices);
		for(int j=0;j<neigh.size();++j)
		{
			final_loc[j]-=cent;
		}

		vector<pair<float,int> > ord;
		for(int j=0;j<neigh.size();++j)
		{
			float angle = atan2(final_loc[j][1]-final_loc[0][1],final_loc[j][0]-final_loc[0][0]);
			ord.push_back(make_pair(angle,neigh[j]));
		}
		sort(ord.begin(),ord.end());
		if(cou==-neigh.size())
		{
			edges[i].clear();
			for(int j=ord.size()-1;j>=0;--j)
			{
				edges[i].push_back(ord[j].second);
			}
		}	
		else
		{
			edges[i].clear();
			for(int j=0;j<ord.size();++j)
			{
				edges[i].push_back(ord[j].second);
			}
		}	
	}
}

object3D::object3D()
{
	numberOfVertices=0;
	vertices.clear();
	vertices_vec.clear();
	edges.clear();
}

object3D::object3D(vector <glm::vec4> vertices_vec_3d , vector<vector<int> > line_3d)
{
	numberOfVertices = vertices_vec_3d.size();
	vertices.clear();
	vertices_vec.clear();
	edges.clear();
	for(int i=0;i<numberOfVertices;++i)
	{
		glm::vec4 qw = vertices_vec_3d[i];
		glm::vec4 temp(qw[0],qw[1],qw[2],1.0f);
		vertices_vec.push_back(temp);

		vector<int> temp_vec;
		edges.push_back(temp_vec);
	}

	for(int i=0;i<numberOfVertices;++i)
	{
		for(int j=0;j<line_3d[i].size();++j)	
		{
			edges[i].push_back(line_3d[i][j]);
		}
	}
	orderVertices();
}

object3D::object3D(orthographic obj)
{
	
	vertices.clear();
	vertices_vec.clear();
	edges.clear();
	vector<vector<int> >  temp_edges = obj.front.getEdges();
	vector<glm::vec4> tf = obj.front.getVec();
	vector<glm::vec4> ts = obj.side.getVec();
	vector<glm::vec4> tt = obj.top.getVec();

	numberOfVertices = temp_edges.size();

	for(int i=0;i<numberOfVertices;++i)
	{
		glm::vec4 temp = glm::vec4();
		for (int j = 0; j < 4; ++j)
		{
			temp[j] = (tf[i][j] + ts[i][j] + tt[i][j])/2.0f;
		}
		vertices_vec.push_back(temp);

		vector<int> etemp;
		edges.push_back(etemp);
	}
	for(int i=0;i<numberOfVertices;++i)
	{
		for(int j=0;j<temp_edges[i].size();++j)
		{
			edges[i].push_back(temp_edges[i][j]);
		}
	}
	orderVertices();
}

void object3D::inputFromFile(string filename)
{
	vertices.clear();
	vertices_vec.clear();
	edges.clear();
	fstream fin;
	fin.open(filename.c_str(), ios::in | ios::binary);
	int n;
	fin>>n;
	numberOfVertices = n;
	for(int i=0; i<n ; ++i)
	{
		float a,b,c;
		fin>>a>>b>>c;
		vertices.push_back(point(a,b,c));

		glm::vec4 temp(a,b,c,1.0f);
		vertices_vec.push_back(temp);
		vector<int> temp_vec;
		edges.push_back(temp_vec);
	}
	int start,end;
	while(fin>>start)
	{
		fin>>end;
		edges[start-1].push_back(end-1);
		edges[end-1].push_back(start-1);
	}
	fin.close();
	orderVertices();
}

void object3D::translate(float x, float y, float z)
{
	glm::mat4 translate_mat = glm::translate(glm::mat4(),glm::vec3(x,y,z));
	for(int i=0;i<numberOfVertices;++i)
	{
		vertices_vec[i] = translate_mat*vertices_vec[i];
	}
}

void object3D::scale(float x, float y, float z)
{
	float a=(float)abs(x);
	float b=(float)abs(y);
	float c=(float)abs(z);
	glm::mat4 scale_mat = glm::scale(glm::mat4(1.0f),glm::vec3(a,b,c));
	for(int i=0;i<numberOfVertices;++i)
	{
		vertices_vec[i] = scale_mat*vertices_vec[i];
	}
}

void object3D::rotate(float theta, line axis)
{
	point dir = axis.getDirection();
    glm::mat4 rotate_mat = glm::rotate(glm::mat4(1.0f),((float)theta)*3.1415f/180.0f, glm::vec3(dir.getX(), dir.getY(), dir.getZ()));
	for(int i=0;i<numberOfVertices;++i)
	{
		vertices_vec[i] = rotate_mat*vertices_vec[i];
	}
}

void object3D::reflect(plane p)
{
	
	float *dir = p.getCoefficients();
	float a=dir[0],b=dir[1],c=dir[2],d=dir[3];
	
	float temp[16];
	temp[0] = 1.0 - a*a;temp[1] = -a*b;temp[2] = -a*c;temp[3] = -a*d;
	temp[4] = -a*b;temp[5] = 1.0 - b*b;temp[6] = -b*c;temp[7] = -b*d;
    temp[8] = -a*c;temp[9] = -c*b;temp[10] = 1.0-c*c;temp[11] = -c*d;
	temp[12] = 0.0;temp[13] = 0.0;temp[14] = 0.0;temp[15] = 1.0;

	glm::mat4 reflect_mat = glm::make_mat4(temp);

	for(int i=0;i<numberOfVertices;++i)
	{
		vertices_vec[i] = 2.0f*reflect_mat*vertices_vec[i] - vertices_vec[i];
	}
}

object2D object3D::project(plane p)
{
	float *dir = p.getCoefficients();
	float a=dir[0],b=dir[1],c=dir[2],d=dir[3];

	
	float temp[16];
	temp[0] = 1.0 - a*a;temp[1] = -a*b;temp[2] = -a*c;temp[3] = -a*d;
	temp[4] = -a*b;temp[5] = 1.0 - b*b;temp[6] = -b*c;temp[7] = -b*d;
    temp[8] = -a*c;temp[9] = -c*b;temp[10] = 1.0-c*c;temp[11] = -c*d;
	temp[12] = 0.0;temp[13] = 0.0;temp[14] = 0.0;temp[15] = 1.0;

	glm::mat4 reflect_mat = glm::make_mat4(temp);

	//cout<<"hello"<<endl;

	vector <glm::vec4> vertices_vec_2d;

	for(int i=0;i<numberOfVertices;++i)
	{
		vertices_vec_2d.push_back(reflect_mat*vertices_vec[i]);
	}

	object2D ans = object2D(vertices_vec_2d, edges);
	return ans;
}

orthographic object3D::orthographic_projection()
{
	glm::mat4 yz = glm::mat4(1.0f);
	glm::mat4 xz = glm::mat4(1.0f);
	glm::mat4 xy = glm::mat4(1.0f);
	yz[0][0] = 0.0f;
	xz[1][1] = 0.0f;
	xy[2][2] = 0.0f;

	vector <glm::vec4> vertices_vec_2d;
	for(int i=0;i<numberOfVertices;++i)
	{
		glm::vec4 temp = yz*vertices_vec[i];
		vertices_vec_2d.push_back(temp);
	}
	object2D front = object2D(vertices_vec_2d,edges);
	vertices_vec_2d.clear();

	for(int i=0;i<numberOfVertices;++i)
	{	
		glm::vec4 temp = xz*vertices_vec[i];
		vertices_vec_2d.push_back(temp);
	}
	object2D side = object2D(vertices_vec_2d,edges);
	vertices_vec_2d.clear();

	for(int i=0;i<numberOfVertices;++i)
	{
		vertices_vec_2d.push_back(xy*vertices_vec[i]);
	}
	object2D top = object2D(vertices_vec_2d,edges);
	vertices_vec_2d.clear();

	return orthographic(front, side, top);
}

object2D object3D::isometric_projection()
{
	glm::mat4 iso_mat = glm::mat4(1.0f);
	iso_mat[0][0] = 0.707107f;
	iso_mat[2][0] = 0.707107f;
	iso_mat[0][1] = 0.408248f;
	iso_mat[2][1] = -0.408248f;
	iso_mat[1][1] = 0.816597f;
	iso_mat[0][2] = -0.577353f;
	iso_mat[2][2] = 0.577353f;
	iso_mat[1][2] = 0.577345f;

	vector <glm::vec4> vertices_vec_2d;
	for(int i=0;i<numberOfVertices;++i)
	{
		vertices_vec_2d.push_back(iso_mat*vertices_vec[i]);
	}
	object2D isometric = object2D(vertices_vec_2d,edges);
	vertices_vec_2d.clear();

	return isometric;
}

int object3D::getNumVer()
{
	return numberOfVertices;
}

vector <glm::vec4> object3D::getVerVec()
{
	return vertices_vec;
}

vector<vector<int> > object3D::getEdges()
{
	return edges;
}

