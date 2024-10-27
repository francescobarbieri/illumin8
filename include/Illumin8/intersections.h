#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include <vector>
#include "helpers/intersection.h"

class Intersections {
  private:
    std::vector<Intersection> intersections_;
  
  public:
    Intersections(std::vector<Intersection> intersections);
    std::optional<Intersection> Hit() const;
    std::size_t Size() const { return intersections_.size(); };
    void Merge(Intersections xs);

    const std::vector<Intersection> &intersections() const { return intersections_; };
}

#endif