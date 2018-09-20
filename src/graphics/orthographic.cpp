#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "object2D.h"
#include "orthographic.h"
#include <string>

using namespace std;

orthographic::orthographic(object2D f, object2D s, object2D t)
{
	front = f;
	side = s;
	top = t;
}

orthographic::orthographic()
{

}

void orthographic::inputFromFile(string filename)
{
	fstream fin;
	fin.open(filename.c_str(), std::ios::in|std::ios::binary);
	int n,numedges;
	fin>>n>>numedges;
	string view;
	for(int j=0;j<3;++j)
	{
		fin>>view;
		vector <glm::vec4> vertices_vec;
		vector< vector<int> > edges;
		for(int i=0; i<n ; ++i)
		{
			float a,b,c;
			fin>>a>>b>>c;
			glm::vec4 temp(a,b,c,1.0f);
			vertices_vec.push_back(temp);
			vector<int> temp_vec;
			edges.push_back(temp_vec);
		}
		int start,end;
		for(int i=0;i<numedges;++i)
		{
			fin>>start;
			fin>>end;
			edges[start-1].push_back(end-1);
			edges[end-1].push_back(start-1);
		}
		if(view=="front")
		{
			front = object2D(vertices_vec,edges);
		}
		else
		{
			if(view=="side")
			{
				side = object2D(vertices_vec,edges);	
			}
			else
			{
				top = object2D(vertices_vec,edges);
			}
		}
	}
	fin.close();
}
