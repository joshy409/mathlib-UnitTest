#include "mat3.h"

mat3::mat3()
{
	xAxis = { 1,0,0 };
	yAxis = { 0,1,0 };
	zAxis = { 0,0,1 };
}

mat3::mat3(float * ptr)
{
	std::copy(ptr, ptr + 9, m);
}

mat3::mat3(float _x1, float _x2, float _x3,
	float _y1, float _y2, float _y3,
	float _z1, float _z2, float _z3)
{
	xAxis = { _x1,_x2,_x3 };
	yAxis = { _y1,_y2,_y3 };
	zAxis = { _z1,_z2,_z3 };
}

mat3::operator float*()
{	
	return m;
}

vec3 & mat3::operator[](const int index)
{
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 temp;
	temp.xAxis = vec3{ x1*rhs.x1 + y1 * rhs.x2 + z1 * rhs.x3,
		               x2*rhs.x1 + y2 * rhs.x2 + z2 * rhs.x3,
		               x3*rhs.x1 + y3 * rhs.x2 + z3 * rhs.x3 };

	temp.yAxis = vec3{ x1*rhs.y1 + y1 * rhs.y2 + z1 * rhs.y3,
					   x2*rhs.y1 + y2 * rhs.y2 + z2 * rhs.y3,
					   x3*rhs.y1 + y3 * rhs.y2 + z3 * rhs.y3 };

	temp.zAxis = vec3{ x1*rhs.z1 + y1 * rhs.z2 + z1 * rhs.z3,
					   x2*rhs.z1 + y2 * rhs.z2 + z2 * rhs.z3,
					   x3*rhs.z1 + y3 * rhs.z2 + z3 * rhs.z3 };

	return temp;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	mat3 temp;
	temp.xAxis = vec3{ x1*rhs.x1 + y1 * rhs.x2 + z1 * rhs.x3,
		x2*rhs.x1 + y2 * rhs.x2 + z2 * rhs.x3,
		x3*rhs.x1 + y3 * rhs.x2 + z3 * rhs.x3 };

	temp.yAxis = vec3{ x1*rhs.y1 + y1 * rhs.y2 + z1 * rhs.y3,
		x2*rhs.y1 + y2 * rhs.y2 + z2 * rhs.y3,
		x3*rhs.y1 + y3 * rhs.y2 + z3 * rhs.y3 };

	temp.zAxis = vec3{ x1*rhs.z1 + y1 * rhs.z2 + z1 * rhs.z3,
		x2*rhs.z1 + y2 * rhs.z2 + z2 * rhs.z3,
		x3*rhs.z1 + y3 * rhs.z2 + z3 * rhs.z3 };

	xAxis = temp.xAxis;
	yAxis = temp.yAxis;
	zAxis = temp.zAxis;

	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	bool result = true;
	for (int i = 0; i < 9; i++) {
		if (m[i] != rhs.m[i]) {
			result = false;
		}
	}
	return result;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	bool result = true;
	for (int i = 0; i < 9; i++) {
		if (m[i] == rhs.m[i]) {
			result = false;
		}
	}
	return result;
}

mat3 mat3::identity()
{
	return mat3(1,0,0,0,1,0,0,0,1);
}

void mat3::set(float _x1, float _x2, float _x3,
	float _y1, float _y2, float _y3,
	float _z1, float _z2, float _z3)
{
	xAxis = { _x1,_x2,_x3 };
	yAxis = { _y1,_y2,_y3 };
	zAxis = { _z1,_z2,_z3 };
}

void mat3::set(float * ptr)
{
	std::copy(ptr, ptr + 9, m);
}

void mat3::transpose()
{
	float temp[9];
	std::copy(m, m + 9, temp);
	xAxis = { temp[0],temp[3],temp[6] };
	yAxis = { temp[1],temp[4],temp[7] };
	zAxis = { temp[2],temp[5],temp[8] };
}

mat3 mat3::getTranspose()
{
	mat3 temp;
	temp.xAxis = { m[0],m[3],m[6] };
	temp.yAxis = { m[1],m[4],m[7] };
	temp.zAxis = { m[2],m[5],m[8] };
	return temp;
}


//TODO
float mat3::determinant(int index1, int index2)
{
	return 0.0f;
}


//TODO
mat3 mat3::getInverse() const
{
	return mat3();
}


mat3 mat3::translation(float x, float y)
{
	return mat3(1, 0, 0, 0, 1, 0, x, y, 1);
}

mat3 mat3::translation(const vec2 & vec)
{
	return mat3(1,0,0,0,1,0,vec.x,vec.y,1);
}

mat3 mat3::rotation(float rot) //rot in radians
{
	return mat3(cos(rot),sin(rot),0,-sin(rot),cos(rot),0,0,0,1);
}

mat3 mat3::scale(float xScale, float yScale)
{
	return mat3(xScale,0,0,0,yScale,0,0,0,1);
}

mat3 mat3::scale(const vec2 & vec)
{
	return mat3(vec.x, 0, 0, 0, vec.y, 0, 0, 0, 1);
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 temp = { x1 * rhs.x + y1 * rhs.y + z1  * rhs.z, x2 * rhs.x + y2 * rhs.y + z2 * rhs.z, x3 * rhs.x + y3 * rhs.y + z3 * rhs.z };
	return temp;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	vec2 temp = { x1 * rhs.x + y1 * rhs.y + z1 * 1, x2 * rhs.x + y2 * rhs.y + z2 * 1};
	return temp;
}
