#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "Illumin8/intersection.h"
#include <vector>

class Intersections {
  private:
    std::vector<Intersection> intersections_;
  
  public:
    Intersections(std::vector<Intersection> intersections);
    std::size_t Size() const { return intersections_.size(); };

    Intersection operator[](int);
};

#endif