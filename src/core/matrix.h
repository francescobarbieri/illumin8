#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "tuple.h"

class Matrix {
  public:
    Matrix(int w, int h, std::vector<float> values);

    float operator() (int row, int col) const;
    bool operator== (const Matrix& other) const;
    Matrix operator* (const Matrix& other) const;
    Tuple operator* (const Tuple& other) const;

    void toConsole();

  private:
    int w_, h_;
    std::vector<std::vector<float>> values;
};

Matrix IdentityMatrix(int dim);

#endif