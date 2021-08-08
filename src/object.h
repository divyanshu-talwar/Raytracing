//object.h
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "ray.h"
#include "vector3D.h"
#include "color.h"
#include "material.h"

class Object
{
protected:
	Material *material;
public:
	bool isSolid;
	Object(Material *mat): material(mat) {}	
	virtual bool intersect(Ray& ray) const = 0;
	// virtual bool get_isSolid(){
	// 	if(isSolid == true){
	// 		return true;
	// 	}
	// 	return false;
	// }
	virtual Color shade(const Ray& ray) const
	{
		return material->shade(ray, isSolid);
	}
};

#endif
