#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "object.h"
#include "ray.h"
#include "vector3D.h"
#include "color.h"

class Triangle : public Object
{
private:
	Vector3D v1, v2, v3;

public:
	Triangle(const Vector3D& pos1, const Vector3D& pos2, const Vector3D& pos3, Material* mat): 
		Object(mat), v1(pos1), v2(pos2), v3(pos3)
	{

		isSolid = true;
	}
	
	virtual bool intersect(Ray& r) const;
};
#endif
