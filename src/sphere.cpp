//sphere.cpp
#include "sphere.h"
#include <iostream>

bool Sphere::intersect(Ray& r) const
{
	Vector3D centerVector = r.getOrigin() - position;
	double a = 1.0;
	double b = 2*dotProduct(r.getDirection(), centerVector);
	double c = dotProduct(centerVector, centerVector) - radius*radius;
	double discriminant = b*b - 4.0*a*c;

    //now check if discr. is posivtive or zero, then only we have an intersection!
	if(discriminant >=0.0)
	{

		if(discriminant == 0)
		{
			double t;
			t = -b/(2.0*a);
			bool b = r.setParameter(t, this);
			if(b){
	            r.setNormal(unitVector(r.getPosition() - position));				
			}
            return b;
		}
		else
		{
			//Calculate both roots
			double D = sqrt(discriminant);
			double t1 = (-b +D)/(2.0*a);
			double t2 = (-b -D)/(2.0*a);

			bool b1 = r.setParameter(t1, this);
			bool b2 = r.setParameter(t2, this);

			if(b1||b2){
				r.setNormal(unitVector(r.getPosition() - position));
			}
			return b1||b2;    
		}
	}
	return false;

}
