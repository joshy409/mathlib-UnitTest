#pragma once
#include "vec3.h"
#include "vec4.h"

struct mat4
{
	union
	{
		struct
		{
			vec4 xAxis;
			vec4 yAxis;
			vec4 zAxis;
			vec4 wAxis;
		};
		vec4 axis[4];
		struct
		{
			float x1, x2, x3, x4,
				y1, y2, y3, y4,
				z1, z2, z3, z4,
				w1, w2, w3, w4;
		};
		struct
		{
			float m[16];
		};
		struct
		{
			float mm[4][4];
		};
	};

	mat4();
	mat4(float *ptr);
	mat4(float x1, float x2, float x3, float x4,
		float y1, float y2, float y3, float y4,
		float z1, float z2, float z3, float z4,
		float w1, float w2, float w3, float w4);
	
	static mat4 identity();
	static mat4 translation(float x, float y, float z);
	static mat4 translation(const vec3 &vec);
	static mat4 rotation(float x, float y, float z);
	static mat4 rotationX(float x);
	static mat4 rotationY(float y);
	static mat4 rotationZ(float z);
	static mat4 scale(float xScale, float yScale, float zScale);

	// rebuild the matrix
	void set(float x1, float x2, float x3, float x4,
		float y1, float y2, float y3, float y4,
		float z1, float z2, float z3, float z4,
		float w1, float w2, float w3, float w4);

	// rebuild the matrix - expects pointer to array of 9 floats
	void set(float *ptr);

	void transpose();
	mat4 getTranspose() const;

	operator float *();
	operator const float *() const;

	vec4 &operator[](const int index);
	const vec4 &operator[](const int index) const;

	mat4 operator*(const mat4 &rhs) const;
	mat4 &operator*=(const mat4 &rhs);

	// transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
	vec4 operator*(const vec4 &rhs) const;
	// convenience function for transforming a 3D vector
	vec3 operator*(const vec3 &rhs) const;

	bool operator==(const mat4 &rhs) const;
	bool operator!=(const mat4 &rhs) const;
};