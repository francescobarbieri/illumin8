#include <catch2/catch_all.hpp>
#include "Illumin8/intersections.h"
#include "Illumin8/intersection.h"
#include "Illumin8/sphere.h"

#include <iostream>

TEST_CASE("Aggregating intersections", "[intersection]") {
  Sphere s = Sphere();
  Intersection i1 = Intersection(1, &s);
  Intersection i2 = Intersection(2, &s);
  Intersections xs = Intersections(std::vector<Intersection>{i1, i2});

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(1) );
  REQUIRE( xs[1].t() == Catch::Approx(2) );
}

TEST_CASE("The hit, when all intersections have positive t", "[intersections]") {
  Sphere s = Sphere();
  Intersection i1 = Intersection(1, &s);
  Intersection i2 = Intersection(2, &s);
  Intersections xs = Intersections(std::vector<Intersection>{i1, i2});

  REQUIRE( xs.Hit().value() == i1 );
}

TEST_CASE("The hit, when some intersections have negative t", "[intersections]") {
  Sphere s = Sphere();
  Intersection i1 = Intersection(-1, &s);
  Intersection i2 = Intersection(2, &s);
  Intersections xs = Intersections(std::vector<Intersection>{i1, i2});

  REQUIRE( xs.Hit().value() == i2 );
}

TEST_CASE("The hit, when all intersections have negative t", "[intersections]") {
  Sphere s = Sphere();
  Intersection i1 = Intersection(-2, &s);
  Intersection i2 = Intersection(-1, &s);
  Intersections xs = Intersections(std::vector<Intersection>{i1, i2});

  REQUIRE( !xs.Hit().has_value() );
}

TEST_CASE("The hit is always the lowest nonnegative intersection", "[intersections]") {
  Sphere s = Sphere();
  Intersection i1 = Intersection(5, &s);
  Intersection i2 = Intersection(7, &s);
  Intersection i3 = Intersection(-3, &s);
  Intersection i4 = Intersection(2, &s);
  Intersections xs = Intersections(std::vector<Intersection>{i1, i2, i3, i4});

  REQUIRE( xs.Hit().value() == i4 );
}