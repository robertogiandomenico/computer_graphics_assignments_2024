

void SetProjections(A03 *A) {
/**************
 Using A->SetMatrix(i, M) where:
 i -> index of the matrix to set (0 .. 7)
 M -> projection matrix to use

 define eight different types of projections.
 
 0 - Ortogonal Front (already given)
 1 - Isometric
 2 - Dimetric, with an angle of 20 degree
 3 - Trimetric, with an angle of alpha of 30 degree, and beta of 60 degrees
 4 - Create a Cabinet projection, with the z axis at an angle of 45 degrees
 5 - Create a perspective projection, with a Fov-y of  90 degrees
 6 - Create a perspective projection, with a Fov-y of  30 degrees (zoom)
 7 - Create a perspective projection, with a Fov-y of 120 degrees (wide)

 Projection of type 0 is already done for you. Please create the other seven cases.
 For all the projections, the aspect ratio is supposed to be 4:3 (assuming the application
 is used on a screen with square pixels). Near plane is at 0.1 for perspective and orthogonal,
 while it is at -500 for isometric, dimetric, trimenteric and cabinet.
 The far plane is always at 500.
 For the parlallel projections, the half-width of the screen in world coordinates
 is assumed to be 20.
 
 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/
	glm::mat4 M;

	float l, r, t, b;
	float a, n, f;

	float w = 20.0f;

	l = -w;
	r = w;

	n = -500.0f;
	f =  500.0f;

	a = 4.0f/3.0f; //aspect ratio

	t = w / a;
	b = -w / a;
	

	glm::mat4 P_ort, R1, R2;	

	P_ort = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) *
			glm::ortho(l, r, b, t, n, f);


	// Ortogonal Front
	// this is the only one correct, and that should not be modified
	M = glm::mat4(1.0f / 20.0f,0,0,0,  0,-4.0f / 60.f,0,0,   0,0,1.0f/(0.1f-500.0f),0, 0,0,0.1f/(0.1f-500.0f),1);
	A->SetMatrix(0,  M);

	// Isometric
	M = glm::mat4(1.0f);
	R1 = glm::rotate(M, glm::radians(35.25f), glm::vec3(1, 0, 0));
	R2 = glm::rotate(M, glm::radians(45.0f), glm::vec3(0, 1, 0));

	M = P_ort * R1 * R2;

	A->SetMatrix(1,  M);

	// Dimetric, with an angle of 20 degree
	M = glm::mat4(1.0f);
	R1 = glm::rotate(M, glm::radians(20.0f), glm::vec3(1, 0, 0));
	R2 = glm::rotate(M, glm::radians(45.0f), glm::vec3(0, 1, 0));

	M = P_ort * R1 * R2;
	A->SetMatrix(2, M);
	
	// Trimetric, with an angle of alpha of 30 degree, and beta of 60 degrees
	M = glm::mat4(1.0f);
	R1 = glm::rotate(M, glm::radians(60.0f), glm::vec3(1, 0, 0));
	R2 = glm::rotate(M, glm::radians(30.0f), glm::vec3(0, 1, 0));

	M = P_ort * R1 * R2;
	A->SetMatrix(3,  M);
	
	// Create a Cabinet projection, with the z axis at an angle of 45 degrees
	M = glm::mat4(1.0f);
	float rho, alpha;
	rho = 0.5f;
	alpha = 45.0f;

							//per colonna
	glm::mat4 Sh = glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, -rho * cos(glm::radians(alpha)), -rho * sin(glm::radians(alpha)), 1, 0, 0, 0, 0, 1);

	M = P_ort * Sh;
	A->SetMatrix(4,  M);
	


	n = 0.1f;

	P_ort = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) *
			glm::frustum(l, r, b, t, n, f);
	
	glm::mat4 P;

	// Create a perspective projection, with a Fov-y of  90 degrees
	M = glm::perspective(glm::radians(90.f), a, n, f);
	M[1][1] *= -1;
	A->SetMatrix(5,  M);
	
	// Create a perspective projection, with a Fov-y of  30 degrees (zoom)
	M = glm::perspective(glm::radians(30.f), a, n, f);
	M[1][1] *= -1;
	A->SetMatrix(6,  M);
	
	// Create a perspective projection, with a Fov-y of 120 degrees (wide)
	M = glm::perspective(glm::radians(120.f), a, n, f);
	M[1][1] *= -1;
	A->SetMatrix(7,  M);

}
