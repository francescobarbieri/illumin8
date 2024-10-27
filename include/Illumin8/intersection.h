#ifndef INTERSECTION_H
#define INTERSECTION_H

class Intersection
{
  private:
    float t_;
    void *object_;

  public:
    Intersection(float t);
    Intersection(float t, void *object);
    
    float t() const { return t_; }; 
    void *object() const { return object_; }; 
};

#endif