This is the repository created for an engineering drawing software created for COP290. 
More information about this can be found at the [course web page](http://www.cse.iitd.ac.in/~suban/COP290/semII-2017-2018/)

## Build

Run the following commands for compilation :
```
git clone https://github.com/tonystark262/Engineering_Drawing_Software.git
cd Engineering_Drawing_Software
make
./bin/Engineering_Drawing_Software  
```

## GUI

- On running the executable file located in the /bin folder, you have to select the type of input you want to give, i.e. either 3D or orthographic. 
- Then you can select either a file to give as an input or enter co-ordinates in the text area.
- Then the object will be constructed and you can perform various actions on the object.

## 3D Input

- First line contains the number of vertices (V).
- The next V lines contain the x, y and z co-ordinates of those vertices seperated by a space.
- The subsequent lines specify edges by vertex numbers (starting from 1).

## Orthographic Input

- First line contains the number of vertices (V).
- The next line contains the number of edges (E).
- Then specify the view (either top, side, front) and do the next two steps for each view
	- The next V lines contain the x, y and z co-ordinates of those vertices seperated by a space.
	- The subsequent E lines specify edges by vertex numbers (starting from 1).

Examples for input files can be found in the test folder

## Actions

- Translate
- Rotate
- Scale
- Reflect about a plane
- Project on an arbitrary plane
- Isometric Projection
- Orthographic Projection
- Render Wireframe
- Render Solid Object
- Reconstruct 3D from orthographic projections.
