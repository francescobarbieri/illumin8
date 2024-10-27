#include <catch2/catch_all.hpp>
#include "Illumin8/transformation.h"
#include "Illumin8/intersections.h"
#include "Illumin8/sphere.h"
#include "Illumin8/ray.h"

#include <vector>

TEST_CASE("A ray intersects a sphere at two points", "[sphere]") {
  Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  Sphere s = Sphere();

  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(4.0) );
  REQUIRE( xs[1].t() == Catch::Approx(6.0) );
}

TEST_CASE("A ray intersects a sphere at a tangent", "[sphere]") {
  Ray r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
  Sphere s = Sphere();

  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(5.0) );
  REQUIRE( xs[1].t() == Catch::Approx(5.0) );
}

TEST_CASE("A ray misses a sphere", "[sphere]") {
  Ray r = Ray(Point(0, 2, -5), Vector(0, 0, 1));
  Sphere s = Sphere();

  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 0 );
}

TEST_CASE("A ray originates inside a sphere", "[sphere]") {
  Ray r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
  Sphere s = Sphere();

  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(-1.0) );
  REQUIRE( xs[1].t() == Catch::Approx(1.0) );
}

TEST_CASE("A sphere is behind a ray", "[sphere]") {
  Ray r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
  Sphere s = Sphere();

  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(-6.0) );
  REQUIRE( xs[1].t() == Catch::Approx(-4.0) );
}

TEST_CASE("An intersection encapsulates t and object", "[sphere]") {
  Ray r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
  Sphere s = Sphere();

  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(-6.0) );
  REQUIRE( xs[1].t() == Catch::Approx(-4.0) );
}

TEST_CASE("Intersect sets the object on the intersection", "[sphere]") {
  Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  Sphere s = Sphere();

  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].object() == &s );
  REQUIRE( xs[1].object() == &s );
}

TEST_CASE("A sphere's default transformation", "[sphere]") {
  Sphere s = Sphere();

  REQUIRE( s.Transform() == IdentityMatrix(4) );
}

TEST_CASE("Changing a sphere's transformation", "[sphere]") {
  Sphere s = Sphere();
  Matrix t = Translation(2, 3, 4);
  s.SetTransform(t);

  REQUIRE( s.Transform() == t );
}

TEST_CASE("Intersecting a scaled sphere with a ray", "[sphere]") {
  Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  Sphere s = Sphere();
  s.SetTransform(Scaling(2, 2, 2));
  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 2 );
  REQUIRE( xs[0].t() == Catch::Approx(3) );
  REQUIRE( xs[1].t() == Catch::Approx(7) );
}

TEST_CASE("Intersecting a translated sphere with a ray", "[sphere]") {
  Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
  Sphere s = Sphere();
  s.SetTransform(Translation(5, 0, 0));
  Intersections xs = s.Intersect(r);

  REQUIRE( xs.Size() == 0 );
}
