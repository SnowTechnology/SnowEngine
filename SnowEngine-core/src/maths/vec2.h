#pragma once

#include "mathf.h"

namespace SnowEngine { namespace Maths {

	struct vec2
	{
		float x, y;

		vec2();
		vec2(float x, float y);

		vec2* add(vec2 other);
		vec2* subtract(vec2 other);
		vec2* multiply(vec2 other);
		vec2* divide(vec2 other);

		vec2* add(float value);
		vec2* subtract(float value);
		vec2* multiply(float value);
		vec2* divide(float value);

		vec2* lerp(vec2 destination, float factor);

		vec2* normalize();

		inline float getLengthSquared() const { return x * x + y * y; }
		inline float getLength() const { Mathf::sqrt(getLengthSquared()); }

		inline float getX() const { return x; }
		inline float getY() const { return y; }
	};

} }