#pragma once
#include "Math.h"

struct Rect {
	float mfWidth = 0.0f;
	float mfHeight = 0.0f;
	Vector2 mPoint[4];
	Vector2 mHalf;
	Vector2 mCenterPoint;
	Vector2 mMin;
	Vector2 mMax;
	Vector2 v;
	Vector2 s;

	bool operator == (Rect& rt);
	bool operator != (Rect& rt);
	Rect operator + (Rect& rt); //충돌여부 판정 = 합집합 
	Rect operator - (Vector2& vertex); //충돌여부 판정 = 교집합
	Rect operator - (Rect& rt);
	Rect operator * (float fValue);
	Rect operator / (float fValue);

	void Set(float x, float y, float fw, float fh);
	void Set(Vector2 vertex, float fw, float fh);
	void Set(float fw, float fh);

	Rect() {}
	Rect(float x, float y, float fw, float fh) {
		Set(x, y, fw, fh);
	}
};

class Box {
public:
	float mfWidth = 0.0f;
	float mfHeight = 0.0f;
	float mfDepth = 0.0f;
	Vector3 mPoint[8];
	Vector3 mHalf;
	Vector3 mCenterPoint;
	Vector3 mMin;
	Vector3 mMax;
	Vector3 v; //vertex
	Vector3 s; //size

	bool operator == (Box& bx);
	bool operator != (Box& bx);
	Box operator + (Box& bx); //충돌여부 판정 = 합집합 
	Box operator - (Vector3& vertex); //충돌여부 판정 = 교집합
	Box operator - (Box& bx);
	Box operator * (float fValue);
	Box operator / (float fValue);

	void Set(float x, float y, float z, float fw, float fh, float fd);
	void Set(Vector3 vertex, float fw, float fh, float fd);
	void Set(float fw, float fh, float fd);

	Box() {}
	Box(float x, float y, float z, float fw, float fh, float fd) {
		Set(x, y, z, fw, fh, fd);
	}
};

class Utils
{
};

