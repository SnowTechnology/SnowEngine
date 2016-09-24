#pragma once

#include "mathf.h"

namespace SnowEngine { namespace Maths {

	struct vec4
	{
		float x, y, z, w;

		vec4();
		vec4(float x, float y, float z, float w);

		vec4* add(vec4 other);
		vec4* subtract(vec4 other);
		vec4* multiply(vec4 other);
		vec4* divide(vec4 other);

		vec4* add(float value);
		vec4* subtract(float value);
		vec4* multiply(float value);
		vec4* divide(float value);

		vec4* lerp(vec4 destination, float factor);

		vec4* normalize();

		inline float getLengthSquared() const { return x * x + y * y + z * z + w * w; }
		inline float getLength() const { Mathf::sqrt(getLengthSquared()); }

		inline float getX() const { return x; }
		inline float getY() const { return y; }
		inline float getZ() const { return z; }
		inline float getW() const { return w; }
	};

} }