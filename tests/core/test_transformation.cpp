#include "Illumin8/transformation.h"
#include "Illumin8/tuple.h"
#include "Illumin8/matrix.h"
#include <math.h>
#include <catch2/catch_all.hpp>

TEST_CASE("Multiplying by a translation matrix", "[transformation]") {
  Matrix t = Translation(5, -3, 2);
  Tuple p = Point(-3, 4, 5);

  REQUIRE( t * p == Point(2, 1, 7) );
}

TEST_CASE("Multiplying by the inverse of a translation matrix", "[transformation]") {
  Matrix t = Translation(5, -3, 2);
  Matrix inv = t.Inverse();
  Tuple p = Point(-3, 4, 5);

  REQUIRE( inv * p == Point(-8, 7, 3) );
}

TEST_CASE("Translation does not affect vectors", "[transformation]") {
  Matrix t = Translation(5, -3, 2);
  Tuple v = Vector(-3, 4, 5);

  REQUIRE( t * v == v );
}

TEST_CASE("A scaling matrix applied to a point", "[transformation]") {
  Matrix t = Scaling(2, 3, 4);
  Tuple p = Point(-4, 6, 8);

  REQUIRE( t * p == Point(-8, 18, 32) );
}

TEST_CASE("A scaling matrix applied to a vector", "[transformation]") {
  Matrix t = Scaling(2, 3, 4);
  Tuple v = Vector(-4, 6, 8);

  REQUIRE( t * v == Vector(-8, 18, 32) );
}

TEST_CASE("Multiplying by the inverse of a scaling matrix", "[transformation]") {
  Matrix t = Scaling(2, 3, 4);
  Matrix inv = t.Inverse();
  Tuple v = Vector(-4, 6, 8);

  REQUIRE( inv * v == Vector(-2, 2, 2) );
}

TEST_CASE("Reflection is scaling by a negative value", "[transformation]") {
  Matrix t = Scaling(-1, 1, 1);
  Tuple p = Point(2, 3, 4);

  REQUIRE( t * p == Point(-2, 3, 4) );
}

TEST_CASE("Rotating a point around the x axis", "[transformation]") {
  Matrix half_quarter = RotationX(M_PI/4);
  Matrix full_quarter = RotationX(M_PI/2);
  Tuple p = Point(0, 1, 0);

  REQUIRE( half_quarter * p == Point(0, sqrt(2)/2, sqrt(2)/2) );
  REQUIRE( full_quarter * p == Point(0, 0, 1) );
}

TEST_CASE("The inverse of an x-rotation rotates in the opposite direction", "[transformation]") {
  Matrix half_quarter = RotationX(M_PI/4);
  Tuple p = Point(0, 1, 0);
  Matrix inv = half_quarter.Inverse();

  REQUIRE( inv * p == Point(0, sqrt(2)/2, -sqrt(2)/2) );
}

TEST_CASE("Rotating a point around the y axis", "[transformation]") {
  Matrix half_quarter = RotationY(M_PI/4);
  Matrix full_quarter = RotationY(M_PI/2);
  Tuple p = Point(0, 0, 1);
  
  REQUIRE( half_quarter * p == Point(sqrt(2)/2, 0, sqrt(2)/2) );
  REQUIRE( full_quarter * p == Point(1, 0, 0) );
}

TEST_CASE("Rotating a point around the z axis", "[transformation]") {
  Matrix half_quarter = RotationZ(M_PI/4);
  Matrix full_quarter = RotationZ(M_PI/2);
  Tuple p = Point(0, 1, 0);
  
  REQUIRE( half_quarter * p == Point(-sqrt(2)/2, sqrt(2)/2, 0) );
  REQUIRE( full_quarter * p == Point(-1, 0, 0) );
}

TEST_CASE("A shearing transformation moves x in proportion to y", "[transformation]") {
  Matrix s = Shearing(1, 0, 0, 0, 0, 0);
  Tuple p = Point(2, 3, 4);
  
  REQUIRE( s * p == Point(5, 3, 4) );
}

TEST_CASE("A shearing transformation moves x in proportion to z", "[transformation]") {
  Matrix s = Shearing(0, 1, 0, 0, 0, 0);
  Tuple p = Point(2, 3, 4);
  
  REQUIRE( s * p == Point(6, 3, 4) );
}

TEST_CASE("A shearing transformation moves y in proportion to x", "[transformation]") {
  Matrix s = Shearing(0, 0, 1, 0, 0, 0);
  Tuple p = Point(2, 3, 4);
  
  REQUIRE( s * p == Point(2, 5, 4) );
}

TEST_CASE("A shearing transformation moves y in proportion to z", "[transformation]") {
  Matrix s = Shearing(0, 0, 0, 1, 0, 0);
  Tuple p = Point(2, 3, 4);
  
  REQUIRE( s * p == Point(2, 7, 4) );
}

TEST_CASE("A shearing transformation moves z in proportion to x", "[transformation]") {
  Matrix s = Shearing(0, 0, 0, 0, 1, 0);
  Tuple p = Point(2, 3, 4);
  
  REQUIRE( s * p == Point(2, 3, 6) );
}

TEST_CASE("A shearing transformation moves z in proportion to y", "[transformation]") {
  Matrix s = Shearing(0, 0, 0, 0, 0, 1);
  Tuple p = Point(2, 3, 4);
  
  REQUIRE( s * p == Point(2, 3, 7) );
}