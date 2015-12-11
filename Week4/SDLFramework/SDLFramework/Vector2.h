#pragma once
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
};