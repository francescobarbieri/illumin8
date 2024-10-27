#include <catch2/catch_all.hpp>
#include "Illumin8/intersections.h"
#include "Illumin8/intersection.h"
#include "Illumin8/sphere.h"

TEST_CASE("Aggregating intersections", "[intersection]") {
  Sphere s = Sphere();
  Intersection i1 = Intersection(1, &s);
  Intersection i2 = Intersection(2, &s);

  Intersections xs = Intersections(std::vector<Intersection>{i1, i2});

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(1) );
  REQUIRE( xs[1].t() == Catch::Approx(2) );
}