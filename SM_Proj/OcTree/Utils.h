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

	void Set(float x, float y, float fw, float fh) {
		v = { x, y };
		s = { fw, fh };

		Set(fw, fh);

	}
	void Set(Vector2 vertex, float fw, float fh)
	{
		v = { vertex.x, vertex.y };
		s = { fw, fh };
		Set(fw, fh);
	}
	void Set(float fw, float fh)
	{
		mfWidth = fw;
		mfHeight = fh;
		mHalf = { mfWidth * 0.5f,mfHeight * 0.5f };
		mPoint[0] = { v.x, v.y };
		mPoint[1] = { v.x + mfWidth, v.y };
		mPoint[2] = { v.x + mfWidth, v.y + mfHeight };
		mPoint[3] = { v.x, v.y + mfHeight };
		mCenterPoint = (mPoint[0] + mPoint[2]) * 0.5f;
		mMin = mPoint[0];
		mMax = mPoint[2];
	}
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

	Box() {}
	Box(float x, float y, float z, float fw, float fh, float fd) {
		Set(x, y, z, fw, fh, fd);
	}

	void Set(float x, float y, float z, float fw, float fh, float fd) {
		v = { x, y , z };
		s = { fw, fh, fd };
		Set(fw, fh, fd);
	}
	void Set(Vector3 vertex, float fw, float fh, float fd){
		v = vertex;
		s = { fw, fh, fd };
		Set(fw, fh,fd);
	}

	void Set(float fw, float fh, float fd){
		mfWidth = fw;
		mfHeight = fh;
		mfDepth = fd;
		mHalf = { mfWidth * 0.5f,mfHeight * 0.5f, mfDepth *0.5f};
		mPoint[0] = { v.x- mHalf.x, v.y + mHalf.y , v.z - mHalf.z };
		mPoint[1] = { v.x , v.y+ mHalf.y , v.z- mHalf.z};
		mPoint[2] = { v.x , v.y , v.z - mHalf.z };
		mPoint[3] = { v.x- mHalf.x , v.y , v.z - mHalf.z };

		mPoint[4] = { v.x - mHalf.x, v.y + mHalf.y , v.z + mHalf.z };
		mPoint[5] = { v.x , v.y + mHalf.y , v.z + mHalf.z };
		mPoint[6] = { v.x , v.y , v.z + mHalf.z };
		mPoint[7] = { v.x - mHalf.x , v.y , v.z + mHalf.z };
		
		mMin = mPoint[0];
		mMax = mPoint[6];
		mCenterPoint = (mMin + mMax) * 0.5f;
	}
};




class Utils
{
};

