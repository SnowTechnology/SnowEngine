#define _USE_MATH_DEFINES

#include <math.h>
#include "mathf.h"

namespace SnowEngine { namespace Maths {

	float Mathf::toRadians(float angle)
	{
		return (angle * M_PI) / 180.0f;
	}

	float Mathf::toDegrees(float angle)
	{
		return (angle / M_PI) * 180.0f;
	}

	float Mathf::sqrt(float angle)
	{
		return (float) sqrtf(angle);
	}

	float Mathf::sin(float angle)
	{
		return (float)sinf(angle);
	}

	float Mathf::cos(float angle)
	{
		return (float)cosf(angle);
	}

	float Mathf::tan(float angle)
	{
		return (float)tanf(angle);
	}

} }