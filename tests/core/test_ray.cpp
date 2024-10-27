#include <catch2/catch_all.hpp>
#include "Illumin8/ray.h"
#include "Illumin8/tuple.h"

TEST_CASE("Creating and querying a ray", "[ray]") {
  Tuple origin = Point(1, 2, 3);
  Tuple direction = Vector(3, 5, 6);

  Ray r = Ray(origin, direction);

  REQUIRE( r.origin() == origin );
  REQUIRE( r.direction() == direction );
}

TEST_CASE("Computing a point from a distance", "[ray]") {
  Tuple origin = Point(2, 3, 4);
  Tuple direction = Vector(1, 0, 0);
  Ray r = Ray(origin, direction);

  REQUIRE( r.Position(0) == Point(2, 3, 4) );
  REQUIRE( r.Position(1) == Point(3, 3, 4) );
  REQUIRE( r.Position(-1) == Point(1, 3, 4) );
  REQUIRE( r.Position(2.5) == Point(4.5, 3, 4) );
}