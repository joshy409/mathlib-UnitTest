#include "mat4.h"

mat4::mat4()
{
	xAxis = { 1,0,0,0 };
	yAxis = { 0,1,0,0 };
	zAxis = { 0,0,1,0 };
	wAxis = { 0,0,0,1 };
}

mat4::mat4(float * ptr)
{
	std::copy(ptr, ptr + 16, m);
}

mat4::mat4(float x1, float x2, float x3, float x4,
	float y1, float y2, float y3, float y4,
	float z1, float z2, float z3, float z4,
	float w1, float w2, float w3, float w4)
{
	xAxis = { x1,x2,x3,x4 };
	yAxis = { y1,y2,y3,y4 };
	zAxis = { z1,z2,z3,z4 };
	wAxis = { w1,w2,w3,w4 };
}

mat4 mat4::identity()
{
	return mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
}

mat4 mat4::translation(float x, float y, float z)
{
	return mat4(1,0,0,0,0,1,0,0,0,0,1,0,x,y,z,1);
}

mat4 mat4::translation(const vec3 & vec)
{
	return mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, vec.x, vec.y, vec.z, 1);
}

mat4 mat4::rotation(float x, float y, float z)
{
	mat4 rotationMatrix;
	mat4 xRotationMatrix = mat4::rotationX(x);
	mat4 yRotationMatrix = mat4::rotationY(y);
	mat4 zRotationMatrix = mat4::rotationZ(z);

	rotationMatrix = xRotationMatrix * yRotationMatrix;
	rotationMatrix *= zRotationMatrix;
	return rotationMatrix;
}

mat4 mat4::rotationX(float x)
{
	return mat4(1,0,0,0,0,cos(x),sin(x),0,0,-sin(x),cos(x),0,0,0,0,1);
}

mat4 mat4::rotationY(float y)
{
	return mat4(cos(y),0,-sin(y),0,0,1,0,0,sin(y),0,cos(y),0,0,0,0,1);
}

mat4 mat4::rotationZ(float z)
{
	return mat4(cos(z),sin(z),0,0,-sin(z),cos(z),0,0,0,0,1,0,0,0,0,1);
}

mat4 mat4::scale(float xScale, float yScale, float zScale)
{
	return mat4(xScale,0,0,0,0,yScale,0,0,0,0,zScale,0,0,0,0,1);
}

void mat4::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16)
{
	xAxis = { x1,x2,x3,x4 };
	yAxis = { y1,y2,y3,y4 };
	zAxis = { z1,z2,z3,z4 };
	wAxis = { w1,w2,w3,w4 };
}

void mat4::set(float * ptr)
{
	std::copy(ptr, ptr + 16, m);
}

void mat4::transpose()
{
	float temp[9];
	std::copy(m, m + 9, temp);
	xAxis = { temp[0],temp[4],temp[8],temp[12] };
	yAxis = { temp[1],temp[5],temp[9],temp[13] };
	zAxis = { temp[2],temp[6],temp[10],temp[14] };
	wAxis = { temp[3],temp[7],temp[11],temp[15] };
}

mat4 mat4::getTranspose() const
{
	mat4 temp;
	temp.xAxis = { m[0],m[4],m[8],m[12] };
	temp.yAxis = { m[1],m[5],m[9],m[13] };
	temp.zAxis = { m[2],m[6],m[10],m[14] };
	temp.wAxis = { m[3],m[7],m[11],m[15] };
	return temp;
}

mat4::operator float*()
{
	return m;
}

mat4::operator const float*() const
{
	return m;
}

vec4 & mat4::operator[](const int index)
{
	return axis[index];
}

const vec4 & mat4::operator[](const int index) const
{
	return axis[index];
}

mat4 mat4::operator*(const mat4 & rhs) const
{
	mat4 temp;
	temp.xAxis = vec4{ x1*rhs.x1 + y1 * rhs.x2 + z1 * rhs.x3 + w1 * rhs.x4,
					   x2*rhs.x1 + y2 * rhs.x2 + z2 * rhs.x3 + w2 * rhs.x4,
					   x3*rhs.x1 + y3 * rhs.x2 + z3 * rhs.x3 + w3 * rhs.x4,
					   x4*rhs.x1 + y4 * rhs.x2 + z4 * rhs.x3 + w4 * rhs.x4 };

	temp.yAxis = vec4{ x1*rhs.y1 + y1 * rhs.y2 + z1 * rhs.y3 + w1 * rhs.y4,
					   x2*rhs.y1 + y2 * rhs.y2 + z2 * rhs.y3 + w2 * rhs.y4,
		               x3*rhs.y1 + y3 * rhs.y2 + z3 * rhs.y3 + w3 * rhs.y4,
					   x4*rhs.y1 + y4 * rhs.y2 + z4 * rhs.y3 + w4 * rhs.y4 };

	temp.zAxis = vec4{ x1*rhs.z1 + y1 * rhs.z2 + z1 * rhs.z3 + w1 * rhs.z4,
					   x2*rhs.z1 + y2 * rhs.z2 + z2 * rhs.z3 + w2 * rhs.z4,
					   x3*rhs.z1 + y3 * rhs.z2 + z3 * rhs.z3 + w3 * rhs.z4,
					   x4*rhs.z1 + y4 * rhs.z2 + z4 * rhs.z3 + w4 * rhs.z4 };

	temp.wAxis = vec4{ x1*rhs.w1 + y1 * rhs.w2 + z1 * rhs.w3 + w1 * rhs.w4,
					   x2*rhs.w1 + y2 * rhs.w2 + z2 * rhs.w3 + w2 * rhs.w4,
					   x3*rhs.w1 + y3 * rhs.w2 + z3 * rhs.w3 + w3 * rhs.w4,
					   x4*rhs.w1 + y4 * rhs.w2 + z4 * rhs.w3 + w4 * rhs.w4 };

	return temp;
}

mat4 & mat4::operator*=(const mat4 & rhs)
{
	mat4 temp;
	temp.xAxis = vec4{ x1*rhs.x1 + y1 * rhs.x2 + z1 * rhs.x3 + w1 * rhs.x4,
		x2*rhs.x1 + y2 * rhs.x2 + z2 * rhs.x3 + w2 * rhs.x4,
		x3*rhs.x1 + y3 * rhs.x2 + z3 * rhs.x3 + w3 * rhs.x4,
		x4*rhs.x1 + y4 * rhs.x2 + z4 * rhs.x3 + w4 * rhs.x4 };

	temp.yAxis = vec4{ x1*rhs.y1 + y1 * rhs.y2 + z1 * rhs.y3 + w1 * rhs.y4,
		x2*rhs.y1 + y2 * rhs.y2 + z2 * rhs.y3 + w2 * rhs.y4,
		x3*rhs.y1 + y3 * rhs.y2 + z3 * rhs.y3 + w3 * rhs.y4,
		x4*rhs.y1 + y4 * rhs.y2 + z4 * rhs.y3 + w4 * rhs.y4 };

	temp.zAxis = vec4{ x1*rhs.z1 + y1 * rhs.z2 + z1 * rhs.z3 + w1 * rhs.z4,
		x2*rhs.z1 + y2 * rhs.z2 + z2 * rhs.z3 + w2 * rhs.z4,
		x3*rhs.z1 + y3 * rhs.z2 + z3 * rhs.z3 + w3 * rhs.z4,
		x4*rhs.z1 + y4 * rhs.z2 + z4 * rhs.z3 + w4 * rhs.z4 };

	temp.wAxis = vec4{ x1*rhs.w1 + y1 * rhs.w2 + z1 * rhs.w3 + w1 * rhs.w4,
		x2*rhs.w1 + y2 * rhs.w2 + z2 * rhs.w3 + w2 * rhs.w4,
		x3*rhs.w1 + y3 * rhs.w2 + z3 * rhs.w3 + w3 * rhs.w4,
		x4*rhs.w1 + y4 * rhs.w2 + z4 * rhs.w3 + w4 * rhs.w4 };

	xAxis = temp.xAxis;
	yAxis = temp.yAxis;
	zAxis = temp.zAxis;
	wAxis = temp.wAxis;
	return *this;
}

vec4 mat4::operator*(const vec4 & rhs) const
{
	vec4 temp = { x1 * rhs.x + y1 * rhs.y + z1 * rhs.z + w1 * rhs.t, x2 * rhs.x + y2 * rhs.y + z2 * rhs.z + w2 * rhs.t, x3 * rhs.x + y3 * rhs.y + z3 * rhs.z + w3 * rhs.t, x4 * rhs.x + y4 * rhs.y + z4 *rhs.z + w4 * rhs.t };
	return temp;
}

vec3 mat4::operator*(const vec3 & rhs) const
{
	vec3 temp = { x1 * rhs.x + y1 * rhs.y + z1 * rhs.z, x2 * rhs.x + y2 * rhs.y + z2 * rhs.z, x3 * rhs.x + y3 * rhs.y + z3 * rhs.z };
	return temp;
}

bool mat4::operator==(const mat4 & rhs) const
{
	bool result = true;
	for (int i = 0; i < 16; i++) {
		if (m[i] != rhs.m[i]) {
			result = false;
		}
	}
	return result;
}

bool mat4::operator!=(const mat4 & rhs) const
{
	bool result = true;
	for (int i = 0; i < 16; i++) {
		if (m[i] == rhs.m[i]) {
			result = false;
		}
	}
	return result;
}
