#ifndef INTERSECTION_H
#define INTERSECTION_H

class intersection
{
  private:
    float t_, u_, v_;
    const void *object_;

  public:
    Intersection(float t, float u, float v, const void *object);
    bool operator==(Intersection other) const;
    
    float t() const { return t_; };
    float u() const { return u_; };
    float v() const { return v_; };
    const void *object() const { return object_; };
};

#endif