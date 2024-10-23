#include <iostream>
#include "matrix.h"
#include "math.h"

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

void Matrix::toConsole()
{
  for (int i = 0; i < h_; i++) {
    for (int j = 0; j < w_; j++) {
      std::cout << this->values[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
