#ifndef SHPERE_H
#define SHPERE_H

#include "Illumin8/intersections.h"
#include "Illumin8/matrix.h"
#include "Illumin8/tuple.h"
#include "Illumin8/ray.h"
#include <vector>

class Sphere  {
  private:
    Tuple origin_;
    Matrix transfrom_ = IdentityMatrix(4);

  public:
    Sphere();
    ~Sphere() = default;

    Intersections Intersect(Ray r);
    void SetTransform(Matrix m) { transfrom_ = m; };
    Matrix Transform() const { return transfrom_; };
    Tuple Normal(Tuple world_point);
};

#endif