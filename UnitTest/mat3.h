#pragma once
#include "vec3.h"
#include "vec2.h"

/*
my matrix orientation
 x y z   x  y  z     x    y    z
[1 4 7] [x1 y1 z1] [m[0] m[3] m[6]]
[2 5 8] [x2 y2 y3] [m[1] m[4] m[7]]
[3 6 9] [x3 y3 z3] [m[2] m[5] m[8]]
*/

struct mat3
{
public:
	union
	{
		struct
		{
			vec3 xAxis;
			vec3 yAxis;
			vec3 zAxis;
		};
		vec3 axis[3];
		struct
		{
			float x1, x2, x3,
				  y1, y2, y3,
				  z1, z2, z3;

		};
		struct
		{
			float m[9];
		};
		struct
		{
			float mm[3][3];
		};
	};

	mat3();
	mat3(float *ptr);
	mat3(float x1, float x2, float x3,
		float y1, float y2, float y3,
		float z1, float z2, float z3);


	// implicit operator to convert mat3 into a float array
	operator float *();

	// returns vec3 objects when accessing by subscript operator
	vec3 &operator[](const int index);

	// concatenates two matrices together and returns the result
	mat3  operator*(const mat3 &rhs) const;
	// concatenates and assigns the result to the matrix
	mat3 &operator*=(const mat3 &rhs);

	// returns true if the matrices are equal
	bool operator==(const mat3 &rhs) const;
	// returns true if the matrices are inequal
	bool operator!=(const mat3 &rhs) const;

	// returns a 3x3 identity matrix
	static mat3 identity();

	// updates the matrix elements with the given values
	void set(float x1, float x2, float x3,
		float y1, float y2, float y3,
		float z1, float z2, float z3);

	// updates the matrix elements with the given values from the given array
	void set(float *ptr);

	// transposes the matrix
	void transpose();
	// returns a transposed copy of the matrix
	mat3 getTranspose();

	//returns determinant  of 2x2 matrix
	float determinant(int index1, int index2);

	//returns a inverse copy of the matrix
	mat3 getInverse() const;

	// returns a translation matrix with the given changes for each axis
	static mat3 translation(float x, float y);
	// returns a translation matrix with the given changes for each axis
	static mat3 translation(const vec2 &vec);
	// returns a rotation matrix with the given rotation
	static mat3 rotation(float rot);
	// returns a translation matrix with the given changes for each axis
	static mat3 scale(float xScale, float yScale);
	static mat3 scale(const vec2 &vec);

	// transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
	vec3 operator*(const vec3 &rhs) const;
	// convenience function for transforming a 2D vector
	vec2 operator*(const vec2 &rhs) const;

};