#include "world.h"
#include "material.h"
#include <iostream>

Color Material::shade(const Ray& incident, const bool isSolid)
{
	Color diff(0), spec(0), amb(0);
	LightSource* light = world -> getLightSource()[0];
	Vector3D lightPos = light -> getPosition();
	Color intensity = light->getIntensity();
	Vector3D v =  -1 * unitVector(incident.getDirection());
	Vector3D norm = unitVector(incident.getNormal());

	amb = color * ka * intensity;


	Vector3D lightDir =  unitVector(lightPos - incident.getPosition());
	diff = color * kd * std::fmax(dotProduct(norm, lightDir), 0.0) * intensity;
	
	Vector3D h = unitVector(v + lightDir);

	spec = color * ks * std::fmax(pow(dotProduct(norm,h),n), 0.0) * intensity;

    Ray shadowfeeler(incident.getPosition()+0.1*lightDir, lightDir);
    world->firstIntersection(shadowfeeler);
    if (shadowfeeler.didHit()) {
        diff = Color(0);
    }
	return (amb + diff + spec);    	
}
