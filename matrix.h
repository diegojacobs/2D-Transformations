
coord multiply(double x, double y, double firstMatrix[3][3]);
coord translation(double x, double y, coord ref);
coord rotation(coord rotateCoord, coord rotateRef, int angle);
coord scale(coord ref, coord rotateRef, double scale_x, double scale_y);

coord multiply(double x, double y, double firstMatrix[3][3])
{
  int i, j, k;
  coord p;
  double secondMatrix[3][1];
  double mult[3][1];
  secondMatrix[0][0] = x;
  secondMatrix[1][0] = y; 
  secondMatrix[2][0] = 1;

  // Initializing elements of matrix mult to 0.
  for(i = 0; i < 3; ++i)
  {
    for(j = 0; j < 1; ++j)
    {
      mult[i][j] = 0;
    }
  }

  // Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
  for(i = 0; i < 3; ++i)
  {
    for(j = 0; j < 1; ++j)
    {
      for(k=0; k < 3; ++k)
      {
        mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
      }
    }
  }

  p.x = mult[0][0];
  p.y = mult[1][0];
  p.z = mult[2][0];
  return p;
}

coord translation(double x, double y, coord ref) {
  double matrix[3][3];
  
  matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = x;
  matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = y;
  matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;

  return multiply(ref.x, ref.y, matrix);
}

coord rotation(coord rotateCoord, coord rotateRef, int angle) {
  double matrix[3][3];
  double val;
  double radians = angle*PI	 / 180.0;
  
  matrix[0][0] =  cos(radians);
  matrix[0][1] = -sin(radians);
  matrix[0][2] = -rotateRef.x*cos(radians) + rotateRef.y*sin(radians) + rotateRef.x;

  matrix[1][0] = sin(radians);
  matrix[1][1] = cos(radians);
  matrix[1][2] = -rotateRef.x*sin(radians) -rotateRef.y*cos(radians) + rotateRef.y;

  matrix[2][0] = 0; 
  matrix[2][1] = 0; 
  matrix[2][2] = 1;

  return multiply(rotateCoord.x, rotateCoord.y, matrix);
}

coord scale(coord ref, coord rotateRef, double scale_x, double scale_y) {
  double matrix[3][3];

  matrix[0][0] = scale_x;
  matrix[0][1] = 0; 
  matrix[0][2] = -rotateRef.x*scale_x + rotateRef.x;

  matrix[1][0] = 0; 
  matrix[1][1] = scale_y; 
  matrix[1][2] = -rotateRef.y*scale_y + rotateRef.y; 

  matrix[2][0] = 0;
  matrix[2][1] = 0; 
  matrix[2][2] = 1;

  return multiply(ref.x, ref.y, matrix);
}

coord shear(double shear_x, double shear_y, coord ref, coord pivot) {
  double matrix[3][3];

  matrix[0][0] = 1; 
  matrix[0][1] = shear_x; 
  matrix[0][2] = -pivot.x*shear_x;

  matrix[1][0] = shear_y; 
  matrix[1][1] = 1; 
  matrix[1][2] = -pivot.y*shear_y;

  matrix[2][0] = 0; 
  matrix[2][1] = 0; 
  matrix[2][2] = 1;

  return multiply(ref.x, ref.y, matrix);
}