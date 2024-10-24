#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "tuple.h"

class Matrix {
  public:
    Matrix(int w, int h, std::vector<float> values);

    Matrix Transpose() const;
    float Determinant() const;
    Matrix Submatrix(int row, int col) const;
    float Minor(int row, int col) const;
    float Cofactor(int row, int col) const;
    Matrix Inverse() const;

    float operator() (int row, int col) const;
    bool operator== (const Matrix& other) const;
    Matrix operator* (const Matrix& other) const;
    Tuple operator* (const Tuple& other) const;

    void Set(float value, const int &row, const int &col);
    bool Invertible() const;
    void toConsole();

  private:
    int w_, h_;
    std::vector<std::vector<float>> values;
};

Matrix IdentityMatrix(int dim);

#endif