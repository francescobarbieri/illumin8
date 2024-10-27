#include "ray.h"

Ray::Ray(Tuple origin, Tuple direction)
{
  origin_ = origin;
  direction_ = direction;
}

Tuple Ray::Position(float time)
{
  return origin_ + direction_ * time; 
}
