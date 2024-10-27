#include "intersection.h"

intersection::Intersection(float t, float u, float v, const void *object)
{
  t_ = t;
  u_ = u;
  v_ = v;
  object_ = object;
}

bool intersection::operator==(Intersection other) const
{
  return object_ == other.object() && t_ == other.t();
}
