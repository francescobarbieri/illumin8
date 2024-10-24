#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

class Matrix;

Matrix Translation(float x, float y, float z);
Matrix Scaling(float x, float y, float z);
Matrix RotationX(float radians);
Matrix RotationY(float radians);
Matrix RotationZ(float radians);

#endif