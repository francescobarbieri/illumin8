#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
  public:
    Matrix(int w, int h, std::vector<float> values);

    float operator() (int row, int col) const;
    bool operator== (const Matrix& other) const;

    void toConsole();

  private:
    int w_, h_;
    std::vector<std::vector<float>> values;
};

#endif