#pragma once

#include "mathf.h"

namespace SnowEngine { namespace Maths {

	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(float x, float y, float z);

		vec3* add(vec3 other);
		vec3* subtract(vec3 other);
		vec3* multiply(vec3 other);
		vec3* divide(vec3 other);

		vec3* add(float value);
		vec3* subtract(float value);
		vec3* multiply(float value);
		vec3* divide(float value);

		vec3* lerp(vec3 destination, float factor);

		vec3* normalize();

		inline float getLengthSquared() const { return x * x + y * y + z * z; }
		inline float getLength() const { Mathf::sqrt(getLengthSquared()); }

		inline float getX() const { return x; }
		inline float getY() const { return y; }
		inline float getZ() const { return z; }
	};

} }