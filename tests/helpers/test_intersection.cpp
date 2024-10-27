#include <catch2/catch_all.hpp>
#include "Illumin8/intersection.h"
#include "Illumin8/sphere.h"

TEST_CASE("An intersection encapsulates t and object", "[intersection]") {
  Sphere s = Sphere();
  Intersection i = Intersection(3.5, &s);

  REQUIRE( i.t() == 3.5 );
  REQUIRE( i.object() == &s );
}