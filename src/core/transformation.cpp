#include "transformation.h"
#include "matrix.h"

#include <vector>
#include <math.h>

Matrix Translation(float x, float y, float z)
{
  Matrix translation = IdentityMatrix(4);
  translation.Set(x, 0, 3);
  translation.Set(y, 1, 3);
  translation.Set(z, 2, 3);
  return translation;
}

Matrix Scaling(float x, float y, float z)
{
  Matrix scaling = Matrix(4, 4, std::vector<float>(4 * 4, 0));
  scaling.Set(x, 0, 0);
  scaling.Set(y, 1, 1);
  scaling.Set(z, 2, 2);
  scaling.Set(1, 3, 3);

  return scaling;
}

Matrix RotationX(float radians)
{
  Matrix rotation = Matrix(4, 4, std::vector<float>(4 * 4, 0));
  float cosR = cos(radians);
  float sinR = sin(radians);

  rotation.Set(1, 0, 0);
  rotation.Set(cosR, 1, 1);
  rotation.Set(cosR, 2, 2);
  rotation.Set(-sinR, 1, 2);
  rotation.Set(sinR, 2, 1);
  rotation.Set(1, 3, 3);

  return rotation;
}

Matrix RotationY(float radians)
{
  Matrix rotation = Matrix(4, 4, std::vector<float>(4 * 4, 0));
  float cosR = cos(radians);
  float sinR = sin(radians);

  rotation.Set(cosR, 0, 0);
  rotation.Set(1, 1, 1);
  rotation.Set(cosR, 2, 2);
  rotation.Set(-sinR, 2, 0);
  rotation.Set(sinR, 0, 2);
  rotation.Set(1, 3, 3);

  return rotation;
}

Matrix RotationZ(float radians)
{
  Matrix rotation = Matrix(4, 4, std::vector<float>(4 * 4, 0));
  float cosR = cos(radians);
  float sinR = sin(radians);

  rotation.Set(cosR, 0, 0);
  rotation.Set(-sinR, 0, 1);
  rotation.Set(sinR, 1, 0);
  rotation.Set(cosR, 1, 1);
  rotation.Set(1, 2, 2);
  rotation.Set(1, 3, 3);

  return rotation;
}

Matrix Shearing(float xy, float xz, float yx, float yz, float zx, float zy)
{
  Matrix shearing = IdentityMatrix(4);

  shearing.Set(xy, 0, 1);
  shearing.Set(xz, 0, 2);
  shearing.Set(yx, 1, 0);
  shearing.Set(yz, 1, 2);
  shearing.Set(zx, 2, 0);
  shearing.Set(zy, 2, 1);

  return shearing;
}
