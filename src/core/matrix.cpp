#include "matrix.h"

Matrix::Matrix(int w, int h, std::vector<float> values)
{
  this->w_ = w;
  this->h_ = h;

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
