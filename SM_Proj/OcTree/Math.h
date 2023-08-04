#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <windows.h>
#include <string>

#define PI (3.141592f)
#define _EPSILON ( 0.0001f)
#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)* rand() / RAND_MAX)

struct Float2 {
	union {
		struct {
			float x;
			float y;
		};
		float vertex[2];
	};
};

struct Float3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};
		float vertex[3];
	};
};

class Vector2 : public Float2 {
public:
	bool operator == (Vector2& vertex);
	bool operator != (Vector2& vertex);
	Vector2 operator + (Vector2& vertex);
	Vector2 operator - (Vector2& vertex);
	Vector2 operator * (float Value);
	Vector2 operator / (float Value);
	Vector2& operator /= (float Value);
	float Length();
	static float Length(Vector2& p);
	Vector2() {}
	Vector2(float fx, float fy) {
		x = fx;
		y = fy;
	}
};

class Vector3 : public Float3 {
public:
	float operator  | (Vector3& vertex);
	Vector3 operator ^ (Vector3& vertex);
	bool operator == (Vector3& vertex);
	bool operator != (Vector3 vertex);
	Vector3 operator + (Vector3& vertex);
	Vector3 operator - (Vector3& vertex);
	Vector3 operator * (float Value);
	Vector3 operator / (float Value);
	Vector3& operator /= (float Value);
	static float Length(Vector3& p);
	float Length();

	Vector3() {}
	Vector3(float fx, float fy, float fz) {
		x = fx;
		y = fy;
		z = fz;
	}
};

class Math
{
};

