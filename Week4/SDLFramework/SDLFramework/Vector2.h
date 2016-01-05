#pragma once
#include <cmath>
struct Vector2
{
	float x;
	float y;

	Vector2(float _x, float _y) {
		x = _x;
		y = _y;
	}

	Vector2 operator/(double scale) {
		Vector2 ret = Vector2(x, y);
		ret.x = x / scale;
		ret.y = y / scale;
		return ret;
	}

	Vector2 operator*(double scale) {
		Vector2 ret = Vector2(x, y);
		ret.x = x*scale;
		ret.y = y*scale;
		return ret;
	}

	Vector2 operator+=(Vector2 vec) {
		x = x + vec.x;
		y = y + vec.y;
		return *this;
	}

	Vector2 operator/=(double num) {
		x = num / x;
		y = num / y;
		return *this;
	}

	Vector2 operator-=(Vector2 vec) {
		x - vec.x;
		y - vec.y;
		return *this;
	}

	Vector2 operator-(Vector2 vec) {
		Vector2 ret = Vector2(x, y);
		ret.x = x - vec.x;
		ret.y = y - vec.y;
		return ret;
	}

	void truncate(double maxSpeed) 
	{
		if (length() == 0) return;
		double mod = maxSpeed / length();
		x *= mod;
		y *= mod;
	}

	double length()
	{
		return (double)std::sqrt((x*x) + (y*y));
	}

	Vector2 normalized()
	{
		Vector2 v = Vector2(x, y);
		v.truncate(1);
		return v;
	}


	Vector2 perpendicular()
	{
		return (x > 0) ? Vector2(-x, y) : Vector2(x, -y);
	}

	static double dist(Vector2 first, Vector2 second)
	{
		return Vector2(first.x - second.x, first.y - second.y).length();
	}

	void wrap()
	{
		x = (x > 800) ? x - 800 : (x < 0) ? x + 800 : x;
		y = (y > 600) ? y - 600 : (y < 0) ? y + 600 : y;
	}
};