#pragma once

#include "vec3.h"

namespace SnowEngine { namespace Maths {

	struct mat4
	{
		float elements[16];

		mat4();
		mat4(float diagonal);

		mat4* multiply(mat4* other);

		static mat4* identity();

		static mat4* orthographic(float left, float right, float top, float bottom, float near, float far);
		static mat4* perspective(float fov, float aspectRatio, float near, float far);

		static mat4* translate(vec3 position);
		static mat4* rotate(vec3 rotation);
		static mat4* scale(vec3 scale);
	};

} }