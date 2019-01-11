#pragma once
#include <cfloat>
#include "utils.h"

struct vec2
{
#ifdef RAYLIB_H
	// constructor vec2 from Vector2
	vec2(Vector2 vec)
	{
		x = vec.x;
		y = vec.y;
	}

	// convert from Vector2 to vec2
	vec2& operator =(const Vector2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;

		return *this;
	}

	// convert from vec2 to Vector2
	operator Vector2()
	{
		return { x , y };
	}
#endif
	float x, y;

	vec2();
	vec2(float x, float y);

	vec2 operator+(const vec2 &rhs) const;
	vec2 operator-(const vec2 &rhs) const;
	vec2 operator*(const float rhs) const;
	friend vec2 operator*(const float lhs, const vec2 &rhs);
	vec2 operator/(const float rhs) const;

	vec2 &operator+=(const vec2 &rhs);
	vec2 &operator-=(const vec2 &rhs);
	vec2 &operator*=(const float rhs);
	vec2 &operator/=(const float rhs);

	bool operator==(const vec2 &rhs) const;
	bool operator!=(const vec2 &rhs) const;

	vec2 operator-() const;

	operator float *();
	operator const float *() const;

	float magnitude() const;
	float dot(const vec2 &rhs) const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	vec2 getPerpCW() const;
	vec2 getPerpCCW() const;

	float angleBetween(const vec2 &rhs) const;



};

vec2 operator*(const float lhs, const vec2 &rhs);
