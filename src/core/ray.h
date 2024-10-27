#ifndef RAY_H
#define RAY_H
#include "tuple.h"
#include "matrix.h"

class Matrix;

class Ray {
  public:
    Ray(Tuple origin, Tuple direction);

    Tuple origin() const { return origin_; };
    Tuple direction() const { return direction_; };

    Tuple Position(float time);
    Ray Transform(Matrix matrix);

  private:
    Tuple origin_, direction_;
};

#endif