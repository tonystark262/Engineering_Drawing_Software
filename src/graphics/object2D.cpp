#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include<fstream>
#include<iostream>
#include "point.h"
#include<vector>
#include<string>
#include "object2D.h"

using namespace std;

object2D::object2D()
{
	numberOfVertices = 0;
	vertices.clear();
	vertices_vec.clear();
	edges.clear();
}	

object2D::object2D(vector <glm::vec4> vertices_vec_2d , vector< vector<int> > line_2d)
{
	vertices.clear();
	vertices_vec.clear();
	edges.clear();
	numberOfVertices = vertices_vec_2d.size();
	for(int i=0;i<numberOfVertices;++i)
	{
		glm::vec4 qw = vertices_vec_2d[i];
		glm::vec4 temp(qw[0],qw[1],qw[2],1.0f);
		vertices_vec.push_back(temp);

		vector<int> temp_vec;
		edges.push_back(temp_vec);
	}

	for(int i=0;i<numberOfVertices;++i)
	{
		for(int j=0;j<line_2d[i].size();++j)	
		{
			edges[i].push_back(line_2d[i][j]);
		}
	}
}

void object2D::inputFromFile(string filename)
{
	vertices.clear();
	vertices_vec.clear();
	edges.clear();

	fstream fin;
	fin.open(filename.c_str(), std::ios::in|std::ios::binary);
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
}

vector<glm::vec4> object2D::getVec()
{
	vector<glm::vec4> temp_vec;
	for(int i=0;i<numberOfVertices;++i)
	{
		glm::vec4 qw = vertices_vec[i];
		glm::vec4 temp(qw[0],qw[1],qw[2],1.0f);
		temp_vec.push_back(temp);
	}
	return temp_vec;
}

vector<vector<int> > object2D::getEdges()
{
	vector<vector<int> > temp_vec;
	for(int i=0;i<numberOfVertices;++i)
	{
		vector<int> temp;
		temp_vec.push_back(temp);
	}

	for(int i=0;i<numberOfVertices;++i)
	{
		for(int j=0;j<edges[i].size();++j)	
		{
			temp_vec[i].push_back(edges[i][j]);
		}
	}
	return temp_vec;
}

int object2D::getNumVer()
{
	return numberOfVertices;
}

