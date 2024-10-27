#include "Illumin8/intersections.h"
#include "sphere.h"
#include "math.h"

Sphere::Sphere()
{
  origin_ = Point(0, 0, 0);
}

Intersections Sphere::Intersect(Ray original_ray)
{
  Ray ray = original_ray.Transform(transfrom_.Inverse());

  Tuple sphere_to_ray = ray.origin() - origin_; 
  float a = ray.direction().dot(ray.direction());
  float b = 2 * ray.direction().dot(sphere_to_ray);
  float c = sphere_to_ray.dot(sphere_to_ray) - 1;

  float discriminant = b * b - 4 * a * c;

  if(discriminant < 0) 
    return Intersections(std::vector<Intersection>{});

  float sqrt_discriminant = sqrt(discriminant);

  Intersection t1 = Intersection( (- b - sqrt_discriminant) / (2 * a), this);
  Intersection t2 = Intersection( (- b + sqrt_discriminant) / (2 * a), this);

  std::vector<Intersection> intersections;
  intersections.push_back(t1);
  intersections.push_back(t2);

  return Intersections(intersections);
}
