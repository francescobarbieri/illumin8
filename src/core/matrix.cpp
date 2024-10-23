#include <iostream>
#include "matrix.h"
#include "math.h"
#include <vector>

Matrix::Matrix(int w, int h, std::vector<float> values)
{
  this->w_ = w;
  this->h_ = h;

  this->values.resize(h);

  for(int i = 0; i < h; i++) {
    this->values[i].resize(w);
  }

  int arrayIndex = 0;
  for (int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(arrayIndex < values.size()) {
        this->values[i][j] = values[arrayIndex];
        arrayIndex++;
      } else {
        this->values[i][j] = 0;
      }
    }
  }
}

float Matrix::operator()(int row, int col) const
{
  return this->values[row][col];
}

bool Matrix::operator==(const Matrix& other) const
{
  if (this->w_ != other.w_ || this->h_ != other.h_) return false;

  for (int i = 0; i < h_; ++i) {
    for (int j = 0; j < w_; ++j) {
      if ( !epsilon_eq(this->values[i][j], other.values[i][j]) ) {
        return false;
      }
    }
  }

  return true;
}

Matrix Matrix::operator*(const Matrix &other) const
{
  // Check if matrixes can be multiplicated
  if (this->w_ != other.h_) {
    throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
  }

  Matrix result(this->w_, other.h_, std::vector<float>(this->h_ * other.w_, 0));

  for (int i = 0; i < this->h_; i++) {
    for (int j = 0; j < other.w_; j++) {
      float sum = 0;
      for (int k = 0; k < this->w_; k++) {
        sum += this->values[i][k] * other.values[k][j];
      }
      result.values[i][j] = sum;
    }
  }

  return result;
}

Tuple Matrix::operator*(const Tuple &other) const
{
  // Check if multiplycation can be done
  if (this->w_ != 4) {
    throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
  }

  float tupleValues[4] = {other.x(), other.y(), other.z(), other.w()};
  float resultValues[4] = {0, 0, 0, 0};

  for(int i = 0; i < this->h_; i++) {
    for(int j = 0; j < this->w_; j++) {
      resultValues[i] += this->values[i][j] * tupleValues[j];
    }
  }

  return Tuple(resultValues[0], resultValues[1], resultValues[2], resultValues[3]);
}

void Matrix::toConsole()
{
  for (int i = 0; i < h_; i++) {
    for (int j = 0; j < w_; j++) {
      std::cout << this->values[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

Matrix IdentityMatrix(int dim)
{
  std::vector<float> vec(dim * dim, 0);

  for(int i = 0; i < dim; i++) {
    vec[i * dim + i] = 1;
  }

  return Matrix(dim, dim, vec);
}
