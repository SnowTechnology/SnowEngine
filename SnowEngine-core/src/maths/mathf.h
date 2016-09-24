#pragma once

namespace SnowEngine { namespace Maths {

	struct Mathf
	{
	private:
		Mathf();
	public:
		static float toRadians(float angle);
		static float toDegrees(float angle);

		static float sqrt(float angle);

		static float sin(float angle);
		static float cos(float angle);
		static float tan(float angle);
	};

} }