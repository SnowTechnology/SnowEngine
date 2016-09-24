#include "mat4.h"
#include "mathf.h"

namespace SnowEngine { namespace Maths {

	mat4::mat4()
	{
		this->elements[16];

		for (int i = 0; i < 16; i++)
		{
			this->elements[i] = 0.0f;
		}
	}

	mat4::mat4(float diagonal)
	{
		this->elements[16];

		for (int i = 0; i < 16; i++)
		{
			if (i % 4 == 0)
			{
				this->elements[i] = diagonal;
			}
			else
			{
				this->elements[i] = 0.0f;
			}
		}
	}

	mat4* mat4::multiply(mat4* other)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				float sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += this->elements[i + e * 4] * other->elements[e + j * 4];
				}
				this->elements[i + j * 4] = sum;
			}
		}

		return this;
	}

	mat4* mat4::identity()
	{
		return new mat4(1.0f);
	}

	mat4* mat4::orthographic(float left, float right, float top, float bottom, float near, float far)
	{
		mat4 *result = new mat4(1.0f);
		float width = right - left;
		float height = top - bottom;
		float depth = far - near;

		result->elements[0 + 0 * 4] = 2.0f / width;
		result->elements[1 + 1 * 4] = 2.0f / height;
		result->elements[2 + 2 * 4] = -2.0f / depth;

		result->elements[0 + 3 * 4] = (-right - left) / width;
		result->elements[1 + 3 * 4] = (-top - bottom) / height;
		result->elements[2 + 3 * 4] = (-far - near) / depth;

		return result;
	}

	mat4* mat4::perspective(float fov, float aspectRatio, float near, float far)
	{
		mat4 *result = new mat4();
		float tanHalfFOV = Mathf::tan(Mathf::toRadians(fov / 2.0f));
		float range = far - near;

		result->elements[0 + 0 * 4] = 1.0f / (tanHalfFOV * aspectRatio);
		result->elements[1 + 1 * 4] = 1.0f / tanHalfFOV;
		result->elements[2 + 2 * 4] = (-far - near) / range;
		result->elements[2 + 3 * 4] = 2 * (near * far) / range;
		result->elements[3 + 2 * 4] = -1.0f;

		return result;
	}

	mat4* mat4::translate(vec3 position)
	{
		mat4 *result = new mat4(1.0f);

		result->elements[0 + 3 * 4] = position.x;
		result->elements[1 + 3 * 4] = position.y;
		result->elements[2 + 3 * 4] = position.z;

		return result;
	}

	mat4* mat4::rotate(vec3 rotation)
	{
		mat4 *rotationX = new mat4(1.0f), *rotationY = new mat4(1.0f), *rotationZ = new mat4(1.0f);

		float x = Mathf::toRadians(rotation.x),
			  y = Mathf::toRadians(rotation.y),
			  z = Mathf::toRadians(rotation.z);

		float sinX = Mathf::sin(x),
			  sinY = Mathf::sin(y),
			  sinZ = Mathf::sin(z);

		float cosX = Mathf::cos(x),
			  cosY = Mathf::cos(y),
			  cosZ = Mathf::cos(z);

		rotationX->elements[1 + 1 * 4] = cosX;
		rotationX->elements[1 + 2 * 4] = -sinX;
		rotationX->elements[2 + 1 * 4] = sinX;
		rotationX->elements[2 + 2 * 4] = cosX;

		rotationY->elements[0 + 0 * 4] = cosY;
		rotationY->elements[0 + 2 * 4] = sinY;
		rotationY->elements[2 + 0 * 4] =-sinY;
		rotationY->elements[2 + 2 * 4] = cosY;

		rotationZ->elements[0 + 0 * 4] = cosZ;
		rotationZ->elements[0 + 1 * 4] =-sinZ;
		rotationZ->elements[1 + 0 * 4] = sinZ;
		rotationZ->elements[1 + 1 * 4] = cosZ;

		return rotationZ->multiply(rotationY->multiply(rotationX));
	}

	mat4* mat4::scale(vec3 scale)
	{
		mat4 *result = new mat4(1.0f);

		result->elements[0 + 0 * 4] = scale.x;
		result->elements[1 + 1 * 4] = scale.y;
		result->elements[2 + 2 * 4] = scale.z;

		return result;
	}

} }