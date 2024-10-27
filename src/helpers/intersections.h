#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "Illumin8/intersection.h"
#include <vector>
#include <optional>

class Intersections {
  private:
    std::vector<Intersection> intersections_;
  
  public:
    Intersections(std::vector<Intersection> intersections);
    std::size_t Size() const { return intersections_.size(); };
    std::optional<Intersection> Hit() const;

    Intersection operator[](int);
};

#endif