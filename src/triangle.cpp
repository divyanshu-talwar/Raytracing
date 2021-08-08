#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "triangle.h"

using glm::mat4;
using glm::vec4;
using glm::normalize;

bool Triangle::intersect(Ray& r) const
{
	glm::vec3 va(v1.X(), v1.Y(), v1.Z());
	glm::vec3 vb(v2.X(), v2.Y(), v2.Z());
	glm::vec3 vc(v3.X(), v3.Y(), v3.Z());

	glm::vec3 origin = glm::vec3(r.getOrigin().X(), r.getOrigin().Y(), r.getOrigin().Z());
	glm::vec3 direction = glm::vec3(r.getDirection().X(), r.getDirection().Y(), r.getDirection().Z());

	glm::mat3 matrix_1 = glm::mat3(va - origin, va - vc, direction);
	glm::mat3 A = glm::mat3(va - vb, va - vc, direction);

	double beta = glm::determinant(matrix_1)/glm::determinant(A);
	matrix_1 = glm::mat3(va - vb, va - origin, direction);

	double gamma = glm::determinant(matrix_1)/glm::determinant(A);
	matrix_1 = glm::mat3(va - vb, va - vc, va - origin);

	double t = glm::determinant(matrix_1)/glm::determinant(A);

    if (beta > 0 && gamma > 0 && (beta+gamma) < 1) {
        bool res = r.setParameter(t, this);
        if (res) {
            Vector3D n = crossProduct(v3-v1, v2-v1);
            r.setNormal(unitVector(-n));
        }
        return true;
    }

    return false;
}
