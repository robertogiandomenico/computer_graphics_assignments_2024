

void SetTransform(A02 *A) {
/**************
 Using A->SetMatrix(i, M, focus) where:
 i -> index of the matrix to set (0 .. 14)
 M -> transform matrix to use
 focus -> true if you want to add the focus to that piece (only one please)
 
 solve the puzzle. Piece 0 is alread in place, and the correct transform to put in place piece 1, is
 the identity matrix. Find the correct transformations to place the other 13 pieces (i = 2..14).
 The suggestion is to work on the pieces one at a time, setting the focus to the one you are working on.
 The piece with the focus, will be displayed in red. Moreover, its origin, and the orientation and size
 of its axis will be shown. This is necessary because not all the pieces have their center in the origin,
 but remember that the transformations, assumes that the center is in the origin. Some pieces (especially
 the ones with a high index) will require a combination of transformations, since the transform is not
 centered with the origin or the main axes.
 
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

	// this is the only one in place, and that should not be modified
	M = glm::mat4(1.0f);
	A->SetMatrix(0,  M, false);

	// this is an example on how to highlight a piece and move it.
	// to put it in place, just replace the following line with an identity matrix,
	// that is: A->SetMatrix(0,  M, false);
	//M = glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.0f, -1.6f)),
	//				glm::radians(15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	M = glm::mat4(1.0f);			// to put this piece in places, uncomment this line and delete the two above
	A->SetMatrix(1, M, false);

	// FROM THIS POINT ON, you have to find the correct transform to solve the puzzle.
	M = glm::scale(glm::vec3(3.0, 3.0, 3.0));
	M *= glm::translate(glm::vec3(-2.0, 0.0, -1.0));
	A->SetMatrix(2, M, false);
	
	M = glm::rotate(glm::radians<float>(-15.0), glm::vec3(0.0, 0.0, 1.0));
	M *= glm::translate(glm::vec3(0.0, 0.0, 1.0));
	A->SetMatrix(3,  M, false);
	
	M = glm::scale(glm::vec3(-1.0, 1.0, 1.0));
	M *= glm::translate(glm::vec3(-2.0, 0.0, 1.0));
	A->SetMatrix(4,  M, false);
	
	M = glm::translate(glm::vec3(4.0, 0.0, 4.0));
	A->SetMatrix(5,  M, false);
	
	M = glm::scale(glm::vec3(2.0, 1.0, 1.25));
	M *= glm::translate(glm::vec3(0.0, 0.0, -1.0));
	A->SetMatrix(6,  M, false);
	
	M = glm::shearZ3D(glm::mat4(1.0), -0.5f, 0.0f);
	M *= glm::translate(glm::vec3(2.0, 0.0, -1.0));
	A->SetMatrix(7,  M, false);
	
	M = glm::rotate(glm::radians<float>(90.0), glm::vec3(0.0, 1.0, 0.0));
	M = glm::shearX3D(M, 0.0f, -0.5f);
	M = glm::shearZ3D(M, -0.65f, 0.0f);
	M *= glm::scale(glm::vec3(2.0, 1.0, 1.5));
	M *= glm::translate(glm::vec3(-0.34, 2.0, 1.0 / 3.0));
	A->SetMatrix(8,  M, false);
	
	M = glm::mat4(1.0f);
	A->SetMatrix(9,  M, false);
	
	M = glm::rotate(glm::radians<float>(90.0), glm::vec3(0.0, 1.0, 0.0));
	M *= glm::scale(glm::vec3(2.0, 2.0, 2.0));
	M *= glm::translate(glm::vec3(-1.0, 1.0, 1.5));
	A->SetMatrix(10, M, false);
	
	M = glm::rotate(glm::radians<float>(135.0), glm::vec3(0.0, 1.0, 0.0));
	M *= glm::translate(glm::vec3(-2.71, 2.0, -0.875));
	A->SetMatrix(11, M, false);
	
	M = glm::rotate(glm::radians<float>(90.0), glm::vec3(0.0, 1.0, 0.0));
	M *= glm::scale(glm::vec3(0.5, 1.0, 1.0));
	M *= glm::translate(glm::vec3(1.0, 2.0, 0.0));
	A->SetMatrix(12, M, false);
	
	M = glm::rotate(glm::radians<float>(45.0), glm::vec3(0.0, 1.0, 0.0));
	M *= glm::rotate(glm::radians<float>(-45.0), glm::vec3(0.0, 0.0, 1.0));
	M *= glm::rotate(glm::radians<float>(-90.0), glm::vec3(1.0, 0.0, 0.0));
	M *= glm::translate(glm::vec3(-0.92, -0.7, 0.92));
	A->SetMatrix(13, M, false);
	
	M = glm::rotate(glm::radians<float>(150), glm::vec3(0.0, 1.0, 0.0));
	M *= glm::translate(glm::vec3(2.225, 2.0, 0.14));
	A->SetMatrix(14, M, false);
}
