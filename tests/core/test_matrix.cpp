#include "Illumin8/matrix.h"
#include <catch2/catch_all.hpp>
#include <vector>

TEST_CASE("Constructing and inspecting a matrix", "[matrix]") {
  std::vector<float> vec = {1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10 , 11, 12, 13.5, 14.5, 15.5, 16.5};

  auto m = new Matrix(5, 5, vec);

  REQURE( m(0, 0) == Catch::Approx(1) );
  REQURE( m(0, 3) == Catch::Approx(4) );
  REQURE( m(1, 0) == Catch::Approx(5.5) );
  REQURE( m(1, 2) == Catch::Approx(7.5) );
  REQURE( m(2, 2) == Catch::Approx(11) );
  REQURE( m(3, 0) == Catch::Approx(13.5) );
  REQURE( m(3, 2) == Catch::Approx(15.5) );
}
