#include "intersections.h"

#include <cassert>

Intersections::Intersections(std::vector<Intersection> intersections)
{
  intersections_ = intersections;
}

Intersection Intersections::operator[](int i)
{
  return intersections_[i];
}
