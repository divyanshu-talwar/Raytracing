//Reference: http://woo4.me/wootracer/cylinder-intersection/

#include <iostream>
#include <cstdio>

#include <GLFW/glfw3.h>
#include <algorithm>

#define  GLM_FORCE_RADIANS
#define  GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include "cylinder.h"

bool Cylinder::intersect(Ray& r) const
{
    double a = r.getDirection().X() * r.getDirection().X() + r.getDirection().Z() * r.getDirection().Z();
    double b = 2 * r.getOrigin().X() * r.getDirection().X() + 2* r.getOrigin().Z() * r.getDirection().Z();
    double c = r.getOrigin().X() * r.getOrigin().X() + r.getOrigin().Z() * r.getOrigin().Z() - radius*radius;
    double discriminant = b*b - 4.0*a*c;

    if(discriminant >=0.0)
    {
        double D = sqrt(discriminant);
        double t1 = (-b +D)/(2.0*a);
        double t2 = (-b -D)/(2.0*a);

        if (t1 > t2) {
            double temp = t1;
            t1 = t2;
            t2 = temp;
        }

        double h1 = r.getOrigin().Y() + t1*r.getDirection().Y();
        double h2 = r.getOrigin().Y() + t2*r.getDirection().Y();

        if (h1 > 1) {
            if (h2 <= 1) {
                double t = t1 + (t2 - t1)*(h1-1)/(h1-h2);
                if (t <= 0) return false;

                bool b = r.setParameter(t, this);

                if (b == true) {
                    r.setNormal(unitVector(Vector3D(0, 1, 0)));
                    return true;
                }
            }
        }
        else if (h1 >= -1 && h1 <= 1) {
            if (t1 > 0) {
                bool b = r.setParameter(t1, this);

                if (b == true) {
                    r.setNormal(unitVector(Vector3D(r.getPosition().X(), 0, r.getPosition().Z())));
                    return true;
                }
            }
        }
        else if (h1 < -1) {
            if (h2 >= -1) {
                double t = t1 + (t2-t1)*(h1+1)/(h1-h2);
                if (t > 0) {
                    bool b = r.setParameter(t, this);

                    if (b == true) {
                        r.setNormal(unitVector(Vector3D(0, -1, 0)));
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
