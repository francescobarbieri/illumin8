#ifndef SHPERE_H
#define SHPERE_H

#include "Illumin8/intersections.h"
#include "Illumin8/tuple.h"
#include "Illumin8/ray.h"
#include <vector>

class Sphere  {
  private:
    Tuple origin_;
    float radius_;

  public:
    Sphere();
    ~Sphere() = default;

    Intersections Intersect(Ray r);
};

#endif