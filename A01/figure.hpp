	

void DrawFigure(A01 *A) {
/**************
 Function A->Plot(float x1, float y1, float r, float g, float b)

 draws a single point at (x1,y1), colored with the (r,g,b) specified color.
 The point is addressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 

 Function A->Line(float x1, float y1, float x2, float y2, float r, float g, float b)

 draws a segment from point (x1,y1) to point (x2, y2), colored with the (r,g,b) specified color.
 Starting and ending points are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]),
 following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 

 Function A->Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 Vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 
 
 Using functions Plot(...), Line(...) and Triangle(...) try to draw a simple picture.
 
 First remove the ten functions below (given only as an example), and replace them with your own.
 Please note that there is an upper limit in the number of primitives that can be used (89998). This number
 xs however huge, and it should not pose any limit, not even for the most complex drawings.

 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

	//Sky
	A->Triangle(-1.0, -1.0, -1.0, 1.0, 1.0, -1.0, 0.74, 0.96, 1.0);
	A->Triangle(-1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 0.74, 0.96, 1.0);

	// Mountains
	A->Triangle(-1.0, 0.6, -0.6, -0.4, -0.3, 0.6, 0.23, 0.1, 0.0);
	A->Triangle(-0.5, 0.6, -0.2, -0.5,  0.1, 0.6, 0.4, 0.2, 0.03);
	A->Triangle( 0.0, 0.6,  0.3, -0.3,  0.6, 0.6, 0.3, 0.21, 0.05);

	// Lake
	A->Triangle(-1.0, 0.6, 1.0, 0.6, -1.0, 1.0, 0.05, 0.53, 0.65);
	A->Triangle(-1.0, 1.0, 1.0, 1.0,  1.0, 0.6, 0.05, 0.53, 0.65);

	// Green Floor
	A->Line(-1.0, 0.6, 1.0, 0.6, 0.0, 0.8, 0.0);

	// House
	A->Triangle(1.0, 0.0, 1.0, 1.0, 0.1, 1.0, 0.4, 0.0, 0.0);
	A->Triangle(1.0, 0.0, 0.1, 0.0, 0.1, 1.0, 0.4, 0.0, 0.0);
	// Roof
	A->Triangle(0.1, 0.0, 1.0, 0.0, 0.55, -0.3, 0.45, 0.2, 0.0);

	//Snow
	A->Plot(-0.6,   -0.3, 1, 1, 1);
	A->Plot(-0.58, -0.28, 1, 1, 1);
	A->Plot(-0.63, -0.31, 1, 1, 1);

	A->Plot(-0.2,   -0.4, 1, 1, 1);
	A->Plot(-0.22, -0.39, 1, 1, 1);
	A->Plot(-0.19, -0.42, 1, 1, 1);

	A->Plot(0.3,  -0.2, 1, 1, 1);
	A->Plot(0.27, -0.21, 1, 1, 1);
	A->Plot(0.32, -0.19, 1, 1, 1);

}
