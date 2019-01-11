#include "vec3.h"

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	return vec3(x + rhs.x, y + rhs.y, z + rhs.z);
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	return vec3(x - rhs.x, y - rhs.y, z - rhs.z);
}

vec3 vec3::operator*(const float rhs) const
{
	return vec3(x * rhs, y * rhs, z * rhs);
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	return vec3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}


vec3 vec3::operator/(const float rhs) const
{
	return vec3(x / rhs, y / rhs, z / rhs);
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	x += rhs.x; y += rhs.y; z += rhs.z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	x -= rhs.x; y -= rhs.y; z -= +rhs.z;
	return *this;
}

vec3 & vec3::operator*=(const float rhs)
{
	x *= rhs; y *= rhs; z *= +rhs;
	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	x /= rhs; y /= rhs; z /= +rhs;
	return *this;
}

bool vec3::operator==(const vec3 & rhs) const
{
	return (abs(x - rhs.x) == FLT_EPSILON && abs(y - rhs.y) == FLT_EPSILON && abs(z - rhs.z) == FLT_EPSILON) ? true : false;
}

bool vec3::operator!=(const vec3 & rhs) const
{
	return (abs(x - rhs.x) == FLT_EPSILON && abs(y - rhs.y) == FLT_EPSILON && abs(z - rhs.z) == FLT_EPSILON) ? false : true;
}

vec3 vec3::operator-() const
{
	return vec3(x * -1, y * -1, z * -1);
}


vec3::operator float*()
{
	return &x;
}


vec3::operator const float*() const
{
	return &x;
}

float vec3::magnitude() const
{
	return sqrt(x*x + y * y+z*z);
}

float vec3::dot(const vec3 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

vec3 vec3::cross(const vec3 & rhs) const
{
	return vec3(y*rhs.z - z * rhs.y, z*rhs.x - x * rhs.z, x*rhs.y - y * rhs.x);
}

vec3 & vec3::normalize()
{
	float mag = this->magnitude();
	x /= mag; y /= mag; z /= mag;
	return *this;
}

vec3 vec3::getNormalised() const
{
	float mag = this->magnitude();
	return  vec3(x / mag, y / mag, z/ mag);
}

vec3 & vec3::scale(const vec3 & rhs)
{
	x*=rhs.x; y*=rhs.y; z*=rhs.z;
	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	return vec3(x* rhs.x, y * rhs.y, z*rhs.z);
}


