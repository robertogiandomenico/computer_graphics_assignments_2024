

/**************
 Creae the meshes, as described below
 
 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

void MakeSquare(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
	vertices = {
				   {-size/2.0f, 0.0f,-size/2.0f},
				   {-size/2.0f, 0.0f, size/2.0f},
				   { size/2.0f, 0.0f,-size/2.0f},
				   { size/2.0f, 0.0f, size/2.0f}
	};
	indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong
	vertices = {
				   {-size/2.0f, -size / 2.0f, -size/2.0f},		// 0
				   {-size/2.0f, -size / 2.0f,  size/2.0f},		// 1
				   { size/2.0f, -size / 2.0f, -size/2.0f},		// 2
				   { size/2.0f, -size / 2.0f,  size/2.0f},		// 3

				   {-size / 2.0f, size / 2.0f, -size / 2.0f},	// 4
				   {-size / 2.0f, size / 2.0f,  size / 2.0f},	// 5
				   { size / 2.0f, size / 2.0f, -size / 2.0f},	// 6
				   { size / 2.0f, size / 2.0f , size / 2.0f},	// 7
	
	};

	indices = {2,1,0,  2,3,1,  4,5,6,  7,6,5,  6,7,3,  3,2,6,  4,0,1,  1,5,4,  6,0,4,  6,2,0,  5,1,7,  1,3,7};

}

void MakeCylinder(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	
    float halfHeight = height / 2.0f;
    float angleStep = 2.0f * M_PI / slices;

    // Create top and bottom vertices
    for (int i = 0; i < slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Bottom circle vertex
        vertices.push_back(glm::vec3(x, -halfHeight, z));

        // Top circle vertex
        vertices.push_back(glm::vec3(x, halfHeight, z));
    }

    // Create indices for side faces
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;

        // Side face 1st triangle
        indices.push_back(2 * i);
        indices.push_back(2 * i + 1);
        indices.push_back(2 * next);

        // Side face 2nd triangle
        indices.push_back(2 * next);
        indices.push_back(2 * i + 1);
        indices.push_back(2 * next + 1);
    }

    // Center vertices for top and bottom
    int bottomCenterIndex = vertices.size();
    vertices.push_back(glm::vec3(0.0f, -halfHeight, 0.0f));

    int topCenterIndex = vertices.size();
    vertices.push_back(glm::vec3(0.0f, halfHeight, 0.0f));

    // Create indices for bottom face
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(bottomCenterIndex);
        indices.push_back(2 * i);
        indices.push_back(2 * next);
    }

    // Create indices for top face
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(topCenterIndex);
        indices.push_back(2 * next + 1);
        indices.push_back(2 * i + 1);
    }

}

void MakeCone(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	
    float halfHeight = height / 2.0f;
    float angleStep = 2.0f * M_PI / slices;

    // Create base vertices
    for (int i = 0; i < slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Base circle vertex
        vertices.push_back(glm::vec3(x, -halfHeight, z));
    }

    // Add the apex vertex
    int apexIndex = vertices.size();
    vertices.push_back(glm::vec3(0.0f, halfHeight, 0.0f));

    // Add the center vertex for the base
    int baseCenterIndex = vertices.size();
    vertices.push_back(glm::vec3(0.0f, -halfHeight, 0.0f));

    // Create indices for the side faces
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;

        // Side face triangle (CCW order)
        indices.push_back(i);
        indices.push_back(apexIndex);
        indices.push_back(next);
    }

    // Create indices for the base face
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;

        // Base face triangle (CCW order)
        indices.push_back(i);
        indices.push_back(next);
        indices.push_back(baseCenterIndex);
    }
}

void MakeSphere(float radius, int rings, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.

    // Generate vertices
    for (int r = 0; r <= rings; ++r) {
        float theta = r * M_PI / rings;  // Polar angle (from 0 to pi)
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (int s = 0; s <= slices; ++s) {
            float phi = s * 2 * M_PI / slices;  // Azimuthal angle (from 0 to 2*pi)
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            float x = radius * sinTheta * cosPhi;
            float y = radius * cosTheta;
            float z = radius * sinTheta * sinPhi;

            vertices.push_back(glm::vec3(x, y, z));
        }
    }

    // Generate indices
    for (int r = 0; r < rings; ++r) {
        for (int s = 0; s < slices; ++s) {
            int first = (r * (slices + 1)) + s;
            int second = first + slices + 1;

            // First triangle
            indices.push_back(first + 1);
            indices.push_back(second);
            indices.push_back(first);

            // Second triangle
            indices.push_back(first + 1);
            indices.push_back(second + 1);
            indices.push_back(second);
        }
    }
}
