#include "vec4.h"

#include "vec4.h"

vec4::vec4()
{
	x = 0;
	y = 0;
	z = 0;
	t = 1;
}

vec4::vec4(float _x, float _y, float _z, float _t)
{
	x = _x;
	y = _y;
	z = _z;
	t = _t;
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	return vec4(x + rhs.x, y + rhs.y, z + rhs.z, t + rhs.t);
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	return vec4(x - rhs.x, y - rhs.y, z - rhs.z, t - rhs.t);
}

vec4 vec4::operator*(const float rhs) const
{
	return vec4(x * rhs, y * rhs, z * rhs, t * rhs);
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	return vec4(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.t * lhs);
}

vec4 vec4::operator/(const float rhs) const
{
	return vec4(x / rhs, y / rhs, z / rhs, t / rhs);
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	x += rhs.x; y += rhs.y; z += rhs.z; t += rhs.t;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	x -= rhs.x; y -= rhs.y; z -= +rhs.z; t -= rhs.t;
	return *this;
}

vec4 & vec4::operator*=(const float rhs)
{
	x *= rhs; y *= rhs; z *= +rhs; t *= rhs;
	return *this;
}

vec4 & vec4::operator/=(const float rhs)
{
	x /= rhs; y /= rhs; z /= +rhs; t /= rhs;
	return *this;
}

bool vec4::operator==(const vec4 & rhs) const
{
	return (abs(x - rhs.x) == FLT_EPSILON && abs(y - rhs.y) == FLT_EPSILON && abs(z - rhs.z) == FLT_EPSILON && abs(t - rhs.t) == FLT_EPSILON) ? true : false;
}

bool vec4::operator!=(const vec4 & rhs) const
{
	return (abs(x - rhs.x) == FLT_EPSILON && abs(y - rhs.y) == FLT_EPSILON && abs(z - rhs.z) == FLT_EPSILON && abs(t - rhs.t) == FLT_EPSILON) ? false : true;
}

vec4 vec4::operator-() const
{
	return vec4(x * -1, y * -1, z * -1, t * -1);
}


vec4::operator float*()
{
	return &x;
}


vec4::operator const float*() const
{
	return &x;
}

float vec4::magnitude() const
{
	return sqrt(x*x + y * y + z * z + t*t);
}

float vec4::dot(const vec4 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z + t * rhs.t;
}

vec4 vec4::cross(const vec4 & rhs) const
{
	return vec4(y*rhs.z - z * rhs.y, z*rhs.x - x * rhs.z, x*rhs.y - y * rhs.x, 0);
}

vec4 & vec4::normalize()
{
	float mag = this->magnitude();
	x /= mag; y /= mag; z /= mag; t /= mag;
	return *this;
}

vec4 vec4::getNormalised() const
{
	float mag = this->magnitude();
	return vec4(x / mag, y / mag, z / mag, t / mag);
}

vec4 & vec4::scale(const vec4 & rhs)
{
	x*=rhs.x; y*=rhs.y; z*=rhs.z; t*=rhs.t;
	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	return vec4(x* rhs.x, y * rhs.y, z*rhs.z, t*rhs.t);
}




