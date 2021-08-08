#include "world.h"
#include <iostream>

using namespace std;

double eta = 1.35;
double eta_air = 1.0;

Vector3D refract(Vector3D d, Vector3D n, double refrac_index){
    double n_dot_d = dotProduct(d, n);
    Vector3D t = unitVector(((d - n*n_dot_d)/refrac_index) - (n*sqrt(1 - ((1 - pow(n_dot_d, 2))/pow(refrac_index, 2)))));
    return t;
}

bool tir_check(Vector3D d, Vector3D n, double refrac_index){
    double n_dot_d = dotProduct(d, n);
    double undertheroot = 1 - (pow(eta_air, 2)*(1 - pow(n_dot_d, 2)))/pow(refrac_index, 2);
    if(undertheroot < 0){
        return true;
    }
    return false;
}

float World::firstIntersection(Ray& ray)
{
	for(int i=0; i<objectList.size(); i++)
		objectList[i]->intersect(ray);
	return ray.getParameter();
}

Color World::shade_ray(Ray& ray, int count)
{
	firstIntersection(ray);
	if(ray.didHit()) {
        if (count <= 10) {
            if(ray.intersected()->isSolid == true){
                Vector3D n = ray.getNormal();
                Vector3D d = ray.getDirection();
                double n_dot_d = dotProduct(d, n);

                Vector3D r = unitVector(d - (2 * n_dot_d * n));
                Ray reflectedRay(ray.getPosition(), r);
                return ((ray.intersected())->shade(ray) + Color(0.3, 0.3, 0.3)*shade_ray(reflectedRay, count + 1));
            }
            else{
                Color k(0);
                double c;

                Vector3D n = ray.getNormal();
                Vector3D d = ray.getDirection();
                double n_dot_d = dotProduct(d, n);

                Vector3D r = unitVector(d - (2 * n_dot_d * n));
                Ray reflectedRay(ray.getPosition(), r);

                if(n_dot_d < 0){
                    Vector3D t = refract(d, n, eta);
                    c = -1 * n_dot_d;

                    double at = ray.getParameter();
                    // double ar = exp(-1*0.019*at);
                    // double ag = exp(-1*0.010*at);
                    // double ab = exp(-1*0.019*at);

                    // k = Color(ar, ag, ab);

                    k = Color(1.0, 1.0, 1.0);

                    Ray refractedRay(ray.getPosition(), t);

                    double r0 = pow((eta - 1.0), 2)/pow((eta + 1.0), 2);
                    double r_factor = r0 + (1 - r0)*pow((1-c), 5);
                    return k*(1 - r_factor)*shade_ray(refractedRay, count+1) + k*r_factor*shade_ray(reflectedRay, count+1); 
                }
                else{
                    k = Color(1.0, 1.0, 1.0);
                    if(!tir_check(d, -1 * n, 1.0/eta)){
                        Vector3D t = refract(d, -1 * n, 1.0/eta);
                        c = dotProduct(t, n);
                        Ray refractedRay(ray.getPosition(), t);
                        double r0 = pow((eta - 1.0), 2)/pow(eta + 1.0, 2);
                        double r_factor = r0 + (1 - r0)*pow((1-c), 5);
                        return k*(1 - r_factor)*shade_ray(refractedRay, count + 1) + k*r_factor*shade_ray(reflectedRay, count + 1); 
                    }
                    else{
                        return k*shade_ray(reflectedRay, count+1);
                    }
                }
            }
        }
        return (ray.intersected()->shade(ray));
    }
	return background;
}
