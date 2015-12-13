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
		x = x / scale;
		y = y / scale;
		return *this;
	}

	Vector2 operator*(double scale) {
		x = x*scale;
		y = y*scale;
		return *this;
	}

	Vector2 operator+=(Vector2 vec) {
		x = x + vec.x;
		y = y + vec.y;
		return *this;
	}


	Vector2 operator-(Vector2 vec) {
		x = x - vec.x;
		y = y - vec.y;
		return *this;
	}
	void truncate(double maxSpeed) 
	{
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
};