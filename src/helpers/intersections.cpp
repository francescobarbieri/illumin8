#include "intersections.h"

#include <cassert>

Intersections::Intersections(std::vector<Intersection> intersections)
{
  intersections_ = intersections;
}

std::optional<Intersection> Intersections::Hit() const
{
  if(!intersections_.size()) {
    return NULL;
  }

  
}

void Intersections::Merge(Intersections xs)
{
}
