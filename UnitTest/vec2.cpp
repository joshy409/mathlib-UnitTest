#include "vec2.h"

vec2::vec2()
{
	x = 0;
	y = 0;
}

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	return vec2(x + rhs.x, y + rhs.y);
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	return vec2(x - rhs.x, y - rhs.y);
}

vec2 vec2::operator*(const float rhs) const
{
	return vec2(x * rhs, y * rhs);
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	return vec2(rhs.x * lhs, rhs.y * lhs);
}


vec2 vec2::operator/(const float rhs) const
{
	return vec2(x / rhs, y / rhs);
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	x += rhs.x ; y += rhs.y;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	x -= rhs.x; y -= rhs.y;
	return *this;
}

vec2 & vec2::operator*=(const float rhs)
{
	x *= rhs; y *= rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	x /= rhs; y /= rhs;
	return *this;
}

bool vec2::operator==(const vec2 & rhs) const
{
	return (abs(x - rhs.x) == FLT_EPSILON && abs(y - rhs.y) == FLT_EPSILON) ? true: false;
}

bool vec2::operator!=(const vec2 & rhs) const
{
	return (abs(x - rhs.x) == FLT_EPSILON && abs(y - rhs.y) == FLT_EPSILON) ? false : true;
}

vec2 vec2::operator-() const
{
	return vec2(x * -1, y * -1);
}


vec2::operator float*()
{
	return &x;
}


vec2::operator const float*() const
{
	return &x;
}

float vec2::magnitude() const
{
	return sqrt(x*x + y * y);
}

float vec2::dot(const vec2 & rhs) const
{
	return x * rhs.x + y * rhs.y;
}

vec2 & vec2::normalize()
{
	
	if (x == 0 || y == 0) {
		return *this;
	}
	else {
		float mag = magnitude();
		x /= mag; y /= mag;
		return *this;
	}
}

vec2 vec2::getNormalized() const
{
	float mag = magnitude();
	return vec2(x / mag, y / mag);
}

vec2 & vec2::scale(const vec2 & rhs)
{
	x*=rhs.x; y*=rhs.y;
	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	return vec2(x* rhs.x, y * rhs.y);
}

vec2 vec2::getPerpCW() const
{
	return vec2(y,-x);
}

vec2 vec2::getPerpCCW() const
{
	return vec2(-y,x);
}

float vec2::angleBetween(const vec2 & rhs) const
{

	float temp = this->dot(rhs);
	float mag = this->magnitude();
	float rhsMag = rhs.magnitude();
	float angle = acos(temp / (mag*rhsMag)) * RAD_TO_DEG2;
	if (rhs.y < y) {
		return angle;
	}
	else {
		return 360 - angle;
		//return 2*PI2-angle;
	}

}


