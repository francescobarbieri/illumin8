#include "Illumin8/transformation.h"
#include "Illumin8/tuple.h"
#include "Illumin8/matrix.h"
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