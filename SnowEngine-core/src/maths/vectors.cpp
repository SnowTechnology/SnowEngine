#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace SnowEngine { namespace Maths {

	/* vec2 functions */

	vec2::vec2()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	vec2::vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	vec2* vec2::add(vec2 other)
	{
		this->x += other.x;
		this->y += other.y;

		return this;
	}

	vec2* vec2::subtract(vec2 other)
	{
		this->x -= other.x;
		this->y -= other.y;

		return this;
	}

	vec2* vec2::multiply(vec2 other)
	{
		this->x *= other.x;
		this->y *= other.y;

		return this;
	}

	vec2* vec2::divide(vec2 other)
	{
		this->x /= other.x;
		this->y /= other.y;

		return this;
	}

	vec2* vec2::add(float value)
	{
		this->x += value;
		this->y += value;

		return this;
	}

	vec2* vec2::subtract(float value)
	{
		this->x -= value;
		this->y -= value;

		return this;
	}

	vec2* vec2::multiply(float value)
	{
		this->x *= value;
		this->y *= value;

		return this;
	}

	vec2* vec2::divide(float value)
	{
		this->x /= value;
		this->y /= value;

		return this;
	}

	vec2* vec2::lerp(vec2 destination, float factor)
	{
		return destination.subtract(*this)->multiply(factor)->add(*this);
	}

	vec2* vec2::normalize()
	{
		return this->divide(this->getLength());
	}

	/* vec3 functions */

	vec3::vec3()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	vec3::vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3* vec3::add(vec3 other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;

		return this;
	}

	vec3* vec3::subtract(vec3 other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;

		return this;
	}

	vec3* vec3::multiply(vec3 other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;

		return this;
	}

	vec3* vec3::divide(vec3 other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;

		return this;
	}

	vec3* vec3::add(float value)
	{
		this->x += value;
		this->y += value;
		this->z += value;

		return this;
	}

	vec3* vec3::subtract(float value)
	{
		this->x -= value;
		this->y -= value;
		this->z -= value;

		return this;
	}

	vec3* vec3::multiply(float value)
	{
		this->x *= value;
		this->y *= value;
		this->z *= value;

		return this;
	}

	vec3* vec3::divide(float value)
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;

		return this;
	}

	vec3* vec3::lerp(vec3 destination, float factor)
	{
		return destination.subtract(*this)->multiply(factor)->add(*this);
	}

	vec3* vec3::normalize()
	{
		return this->divide(this->getLength());
	}

	/* vec4 functions */

	vec4::vec4()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	vec4::vec4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4* vec4::add(vec4 other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;

		return this;
	}

	vec4* vec4::subtract(vec4 other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;

		return this;
	}

	vec4* vec4::multiply(vec4 other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;

		return this;
	}

	vec4* vec4::divide(vec4 other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;

		return this;
	}

	vec4* vec4::add(float value)
	{
		this->x += value;
		this->y += value;
		this->z += value;
		this->w += value;

		return this;
	}

	vec4* vec4::subtract(float value)
	{
		this->x -= value;
		this->y -= value;
		this->z -= value;
		this->w -= value;

		return this;
	}

	vec4* vec4::multiply(float value)
	{
		this->x *= value;
		this->y *= value;
		this->z *= value;
		this->w *= value;

		return this;
	}

	vec4* vec4::divide(float value)
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;
		this->w /= value;

		return this;
	}

	vec4* vec4::lerp(vec4 destination, float factor)
	{
		return destination.subtract(*this)->multiply(factor)->add(*this);
	}

	vec4* vec4::normalize()
	{
		return this->divide(this->getLength());
	}

} }