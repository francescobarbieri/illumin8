#include "intersection.h"

Intersection::Intersection(float t)
{
  t_ = t;
}

Intersection::Intersection(float t, void *object)
{
  t_ = t;
  object_ = object;
}
