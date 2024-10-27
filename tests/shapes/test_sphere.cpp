#include <catch2/catch_all.hpp>
#include "Illumin8/sphere.h"
#include "Illumin8/ray.h"
#include "Illumin8/intersection.h"

#include <vector>

TEST_CASE("A ray intersects a sphere at two points", "[sphere]") {
  Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  Sphere s = Sphere();

  std::vector<Intersection> xs = s.Intersections(r);

  REQUIRE( xs.size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(4.0) );
  REQUIRE( xs[1].t() == Catch::Approx(6.0) );
}

TEST_CASE("A ray intersects a sphere at a tangent", "[sphere]") {
  Ray r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
  Sphere s = Sphere();

  std::vector<Intersection> xs = s.Intersections(r);

  REQUIRE( xs.size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(5.0) );
  REQUIRE( xs[1].t() == Catch::Approx(5.0) );
}

TEST_CASE("A ray misses a sphere", "[sphere]") {
  Ray r = Ray(Point(0, 2, -5), Vector(0, 0, 1));
  Sphere s = Sphere();

  std::vector<Intersection> xs = s.Intersections(r);

  REQUIRE( xs.size() == 0 );
}

TEST_CASE("A ray originates inside a sphere", "[sphere]") {
  Ray r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
  Sphere s = Sphere();

  std::vector<Intersection> xs = s.Intersections(r);

  REQUIRE( xs.size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(-1.0) );
  REQUIRE( xs[1].t() == Catch::Approx(1.0) );
}

TEST_CASE("A sphere is behind a ray", "[sphere]") {
  Ray r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
  Sphere s = Sphere();

  std::vector<Intersection> xs = s.Intersections(r);

  REQUIRE( xs.size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(-6.0) );
  REQUIRE( xs[1].t() == Catch::Approx(-4.0) );
}

TEST_CASE("An intersection encapsulates t and object", "[sphere]") {
  Ray r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
  Sphere s = Sphere();

  std::vector<Intersection> xs = s.Intersections(r);

  REQUIRE( xs.size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(-6.0) );
  REQUIRE( xs[1].t() == Catch::Approx(-4.0) );
}