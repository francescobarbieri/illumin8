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

Matrix Matrix::Transpose() const
{
  Matrix result (this->h_, this->w_, std::vector<float>(this->h_ * this->w_));

  for(int i = 0; i < this->h_; i++) {
    for(int j = 0; j < this->w_; j++) {
      result.values[j][i] = this->values[i][j];
    }
  }

  return result;
}

float Matrix::Determinant() const
{
  if(this->w_ == 2) {
    return this->operator()(0, 0) * this->operator()(1, 1) -
      this->operator()(1, 0) * this->operator()(0, 1);
  } else {
    float determinant = 0;
    for (int col = 0; col < this->w_; ++col) {
      determinant += this->operator()(0, col) * this->Cofactor(0, col);
    }
    return determinant;
  }
}

Matrix Matrix::Submatrix(int row, int col) const
{
  int y = 0;
  Matrix sub(this->h_ - 1, this->w_ - 1, std::vector<float>((this->h_ - 1) * (this->w_ - 1), 0));
  for (int r = 0; r < this->h_; ++r) {
    if (r == row) {
      continue;
    }
    int x = 0;
    for (int c = 0; c < this->w_; ++c) {
      if (c != col) {
        sub.Set(this->operator()(r, c), y, x);
        ++x;
      }
    }
    ++y;
  }
  return sub;
}

float Matrix::Minor(int row, int col) const
{
  return this->Submatrix(row, col).Determinant();
}

float Matrix::Cofactor(int row, int col) const
{
  float minor = this->Minor(row, col);
  if ((row + col) % 2 == 1) {
    return -1 * minor;
  } else {
    return minor;
  }
}

Matrix Matrix::Inverse() const
{
  float determinant = this->Determinant();
  Matrix inverse(this->h_, this->w_, std::vector<float>(this->h_ * this->w_, 0));

  for(int row = 0; row < this->h_; ++row) {
    for(int col = 0; col < this->w_; ++col) {
      float cofactor = this->Cofactor(row,col);
      inverse.Set(cofactor / determinant, col, row);
    }
  }

  return inverse;
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

void Matrix::Set(float value, const int &row, const int &col)
{
  this->values[row][col] = value;
}

bool Matrix::Invertible() const
{
  return this->Determinant() != 0;
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
