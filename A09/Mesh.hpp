

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

void MakeSquare(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
	vertices = {
				   {-size/2.0f, 0.0f, -size/2.0f,0.0f, 1.0f, 0.0f},
				   {-size/2.0f, 0.0f,  size/2.0f,0.0f, 1.0f, 0.0f},
				   { size/2.0f, 0.0f, -size/2.0f,0.0f, 1.0f, 0.0f},
				   { size/2.0f, 0.0f,  size/2.0f,0.0f, 1.0f, 0.0f}};
	indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong

    float halfSize = size / 2.0f;
    // Vertices for the cube
    vertices = {
        // Front face
        {-halfSize, -halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        { halfSize, -halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        { halfSize,  halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        {-halfSize,  halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        // Back face
        {-halfSize, -halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        {-halfSize,  halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        { halfSize,  halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        { halfSize, -halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        // Top face
        {-halfSize,  halfSize, -halfSize, 0.0f, 1.0f, 0.0f},
        {-halfSize,  halfSize,  halfSize, 0.0f, 1.0f, 0.0f},
        { halfSize,  halfSize,  halfSize, 0.0f, 1.0f, 0.0f},
        { halfSize,  halfSize, -halfSize, 0.0f, 1.0f, 0.0f},
        // Bottom face
        {-halfSize, -halfSize, -halfSize, 0.0f, -1.0f, 0.0f},
        { halfSize, -halfSize, -halfSize, 0.0f, -1.0f, 0.0f},
        { halfSize, -halfSize,  halfSize, 0.0f, -1.0f, 0.0f},
        {-halfSize, -halfSize,  halfSize, 0.0f, -1.0f, 0.0f},
        // Right face
        { halfSize, -halfSize, -halfSize, 1.0f, 0.0f, 0.0f},
        { halfSize,  halfSize, -halfSize, 1.0f, 0.0f, 0.0f},
        { halfSize,  halfSize,  halfSize, 1.0f, 0.0f, 0.0f},
        { halfSize, -halfSize,  halfSize, 1.0f, 0.0f, 0.0f},
        // Left face
        {-halfSize, -halfSize, -halfSize, -1.0f, 0.0f, 0.0f},
        {-halfSize, -halfSize,  halfSize, -1.0f, 0.0f, 0.0f},
        {-halfSize,  halfSize,  halfSize, -1.0f, 0.0f, 0.0f},
        {-halfSize,  halfSize, -halfSize, -1.0f, 0.0f, 0.0f},
    };

    // Indices for the cube (12 triangles)
    indices = {
        0,  1,  2,  2,  3,  0,    // Front face
        4,  5,  6,  6,  7,  4,    // Back face
        8,  9, 10, 10, 11,  8,    // Top face
        12, 13, 14, 14, 15, 12,   // Bottom face
        16, 17, 18, 18, 19, 16,   // Right face
        20, 21, 22, 22, 23, 20    // Left face
    };

}

void MakeCylinder(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson

    // Create vertices for the top and bottom caps
    for (int i = 0; i < slices; ++i) {
        float angle = 2.0f * M_PI * i / slices;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Top cap (normal pointing up)
        vertices.push_back({ x, height / 2.0f, z, 0.0f, 1.0f, 0.0f });

        // Bottom cap (normal pointing down)
        vertices.push_back({ x, -height / 2.0f, z, 0.0f, -1.0f, 0.0f });

        // Lateral surface (normal pointing outwards, top vertex)
        vertices.push_back({ x, height / 2.0f, z, x / radius, 0.0f, z / radius });

        // Lateral surface (normal pointing outwards, bottom vertex)
        vertices.push_back({ x, -height / 2.0f, z, x / radius, 0.0f, z / radius });
    }

    // Top and bottom center vertices
    int topCenterIndex = vertices.size();
    vertices.push_back({ 0.0f, height / 2.0f, 0.0f, 0.0f, 1.0f, 0.0f }); // Top center

    int bottomCenterIndex = vertices.size();
    vertices.push_back({ 0.0f, -height / 2.0f, 0.0f, 0.0f, -1.0f, 0.0f }); // Bottom center

    // Top cap indices
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(topCenterIndex);              // Top cap vertex
        indices.push_back(next * 4);           // Next top cap vertex
        indices.push_back(i * 4);     // Center vertex
    }

    // Bottom cap indices
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(bottomCenterIndex);       // Next bottom cap vertex
        indices.push_back(i * 4 + 1);          // Bottom cap vertex
        indices.push_back(next * 4 + 1);  // Center vertex
    }

    // Lateral surface indices
    for (int i = 0; i < slices; ++i) {
        int currentTop = i * 4 + 2;
        int nextTop = ((i + 1) % slices) * 4 + 2;
        int currentBottom = i * 4 + 3;
        int nextBottom = ((i + 1) % slices) * 4 + 3;

        // First triangle of the side
        indices.push_back(currentTop);
        indices.push_back(nextTop);
        indices.push_back(currentBottom);

        // Second triangle of the side
        indices.push_back(nextTop);
        indices.push_back(nextBottom);
        indices.push_back(currentBottom);
    }
}

void MakeCone(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson

    // Compute the normal for the side, pointing perpendicular to the cone surface
    float sideNormalY = radius / sqrt(pow(radius, 2) + pow(height, 2));
    float sideNormalXZ = height / sqrt(pow(radius, 2) + pow(height, 2));

    // Create vertices for the base and the lateral surface
    for (int i = 0; i < slices; ++i) {
        float angle = 2.0f * M_PI * i / slices;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glm::vec3 normalVector = normalize(glm::vec3(height * cos(angle), radius, height * sin(angle)));


        // Base vertex with 0,0,0 normals
        vertices.push_back({ x, -height / 2.0f, z, 0.0f, 0.0f, 0.0f });

        // Lateral surface vertex (normal pointing outwards)       
        vertices.push_back({ x, -height / 2.0f, z, normalVector[0], normalVector[1], normalVector[2] });
    }

    // Apex vertex needs 0, 0, 0, normal
    int apexIndex = vertices.size();
    vertices.push_back({ 0.0f, height / 2.0f, 0.0f, 0.0f, 0.0f, 0.0f });

    // Base center vertex
    int baseCenterIndex = vertices.size();
    vertices.push_back({ 0.0f, -height / 2.0f, 0.0f, 0.0f, -1.0f, 0.0f });

    // Base indices
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(baseCenterIndex);           // Center of the base
        indices.push_back(i * 2);                     // Current base vertex
        indices.push_back(next * 2);                  // Next base vertex
    }

    // Side indices
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(apexIndex);                 // Apex vertex
        indices.push_back(next * 2 + 1);              // Next lateral surface vertex
        indices.push_back(i * 2 + 1);                 // Current lateral surface vertex
    }
}

void MakeSphere(float radius, int rings, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.

    // Add top pole vertex with outward normal
    vertices.push_back({ 0.0f, radius, 0.0f, 0.0f, 1.0f, 0.0f });

    // Add vertices for rings
    int ringStartIndex = 1;
    for (int i = 0; i < rings; ++i) {
        float theta = M_PI * (i + 1) / (rings + 1);
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (int j = 0; j < slices; ++j) {
            float phi = 2.0f * M_PI * j / slices;

            float x = radius * sinTheta * cos(phi);
            float y = radius * cosTheta;
            float z = radius * sinTheta * sin(phi);

            // Normals point outward
            float nx = x / radius;
            float ny = y / radius;
            float nz = z / radius;

            vertices.push_back({ x, y, z, nx, ny, nz });
        }
    }

    // Add bottom pole vertex with outward normal
    int bottomPoleIndex = vertices.size();
    vertices.push_back({ 0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f });

    // Top cap indices
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(ringStartIndex + next); // Top pole
        indices.push_back(ringStartIndex + i);
        indices.push_back(0);
    }

    // Bottom cap indices
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(ringStartIndex + i + (rings - 1) * slices); // Bottom pole
        indices.push_back(ringStartIndex + next + (rings - 1) * slices);
        indices.push_back(bottomPoleIndex);
    }

    // Side indices
    for (int i = 0; i < rings - 1; ++i) {
        int rowStart = ringStartIndex + i * slices;
        int nextRowStart = rowStart + slices;

        for (int j = 0; j < slices; ++j) {
            int current = rowStart + j;
            int next = rowStart + (j + 1) % slices;
            int belowCurrent = nextRowStart + j;
            int belowNext = nextRowStart + (j + 1) % slices;

            indices.push_back(current);
            indices.push_back(next);
            indices.push_back(belowCurrent);

            indices.push_back(next);
            indices.push_back(belowNext);
            indices.push_back(belowCurrent);
        }
    }
}
