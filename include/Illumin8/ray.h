#ifndef RAY_H
#define RAY_H
#include "tuple.h"

class Ray {
  public:
    Ray(Tuple origin, Tuple direction);

    Tuple origin() const { return origin_; };
    Tuple direction() const { return direction_; };

    Tuple Position(float time);

  private:
    Tuple origin_, direction_;
};

#endif