#include "Illumin8/intersections.h"
#include "Illumin8/transformation.h"
#include "Illumin8/canvas.h"
#include "Illumin8/sphere.h"
#include "Illumin8/matrix.h"
#include "Illumin8/ray.h"
#include "Illumin8/tuple.h"
#include <iostream>
#include <cmath>
using namespace std;

const float SPHERE_PADDING = 20.0;
const float SPHERE_RADIUS = 100.0;
const int CANVAS_DIMENSION = 2 * SPHERE_PADDING + 2 * SPHERE_RADIUS;
const int INSET = CANVAS_DIMENSION / 2;

void DrawPixel(Canvas *canvas, int x, int y) {
  x += INSET;
  y += INSET;
  canvas->write_pixel(x, y, Color(1, 0, 0));
}

int main(int argc, char* argv[]) {
  Canvas *canvas = new Canvas(CANVAS_DIMENSION, CANVAS_DIMENSION);
  Sphere s = Sphere();
  Matrix transform = Scaling(SPHERE_RADIUS, SPHERE_RADIUS, SPHERE_RADIUS) * Translation(0, 0, SPHERE_RADIUS * 2 + SPHERE_PADDING);
  s.SetTransform(transform);

  for(int i = -INSET; i < INSET; ++i) {
    for(int j = -INSET; j < INSET; ++j) {
      Ray r = Ray(Point(j, i, SPHERE_RADIUS * 2), Vector(0, 0, 1));
      Intersections xs = s.Intersect(r);
      if(xs.Size()) {
        DrawPixel(canvas, j, i);
      }
    }
  }

  canvas->canvas_to_ppm();

  return 1;
}