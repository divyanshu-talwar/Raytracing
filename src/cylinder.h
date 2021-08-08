#ifndef _CYLINDER_H
#define _CYLINDER_H

#include "object.h"
#include "ray.h"
#include "vector3D.h"
#include "color.h"

class Cylinder : public Object
{
private:
    Vector3D position;
    double radius;

public:
    Cylinder(const Vector3D& _pos, double _rad, Material* mat):
            Object(mat), position(_pos), radius(_rad)
    {
        isSolid = true;
    }

    virtual bool intersect(Ray& r) const;
};

#endif
