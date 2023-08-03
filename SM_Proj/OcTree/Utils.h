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

bool Rect::operator == (Rect& rt) {
	if (fabs(v.x - rt.v.x) < _EPSILON)
		if (fabs(v.y - rt.v.y) < _EPSILON)
			if(fabs(mfWidth- rt.mfWidth) < _EPSILON)
				if(fabs(mfHeight- rt.mfHeight < _EPSILON))
					return true;
	return false;
}
bool Rect::operator != (Rect& rt) {
	return !(*this == rt);
}
; //충돌여부 판정 = 합집합 
Rect Rect::operator + (Rect& rt) {
	Rect NewRect;
	float fminX = min(v.x, rt.v.x);
	float fminY = min(v.y, rt.v.y);
	float fmaxX = max(mMax.x, rt.mMax.x);
	float fmaxY = max(mMax.y, rt.mMax.y);
	NewRect.Set(fminX, fminY, fmaxX - fminX, fmaxY - fminY);
	return NewRect;
}
//충돌여부 판정 = 교집합
Rect Rect::operator - (Rect& rt) {
	Rect NewRect;
	if (Collision::RectToRect(*this, rt)) {
		float fminX = mMin.x > rt.mMin.x ? mMin.x : rt.mMin.x;
		float fminY = mMin.y > rt.mMin.y ? mMin.y : rt.mMin.y;
		float fmaxX = mMax.x > rt.mMax.x ? mMax.x : rt.mMax.x;
		float fmaxY = mMax.y > rt.mMax.y ? mMax.y : rt.mMax.y;
		NewRect.Set(fminX, fminY, fmaxX - fminX, fmaxY - fminY);
	}
	return NewRect;
}
Rect Rect::operator - (Vector2& vertex) {
	return Rect(v.x - vertex.x, v.y - vertex.y, mfWidth, mfHeight);
}
Rect Rect::operator * (float fValue) {
	if (fValue <= 0.0f)
		return *this;
	mfWidth *= fValue;
	mfHeight *= fValue;
	return Rect(v.x, v.y, mfWidth, mfHeight);
}
Rect Rect::operator / (float fValue) {
	if (fValue <= 0.0f)
		return *this;
	mfWidth /= fValue;
	mfHeight /= fValue;
	return Rect(v.x, v.y, mfWidth, mfHeight);
}

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


bool Box::operator == (Box& bx) {
	if (fabs(v.x - bx.v.x) < _EPSILON)
		if (fabs(v.y - bx.v.y) < _EPSILON)
			if (fabs(v.z - bx.v.z) < _EPSILON)
				if (fabs(mfWidth - bx.mfWidth) < _EPSILON)
					if (fabs(mfHeight - bx.mfHeight) < _EPSILON)
						if (fabs(mfDepth - bx.mfDepth) < _EPSILON)
							return true;
	return false;
}
bool  Box::operator != (Box& bx) {
	return !(*this == bx);
}
//충돌여부 판정 = 합집합 
Box  Box::operator + (Box& bx) {
	Box newBx;
	float fminX = min(v.x, bx.v.x);
	float fminY = min(v.y, bx.v.y);
	float fminZ = min(v.z, bx.v.z);
	float fmaxX = max(v.x, bx.v.x);
	float fmaxY = max(v.y, bx.v.y);
	float fmaxZ = max(v.z, bx.v.z);

	newBx.Set(fminX, fminY, fminZ, fmaxX - fminX, fmaxY - fminY, fmaxZ - fminZ);
	return newBx;
}
//충돌여부 판정 = 교집합
Box  Box::operator - (Box& bx){
	Box newBx;
	if (Collision::BoxToBox(*this, bx)) {
		float fminX = mMin.x > bx.mMin.x ? mMin.x : bx.mMin.x;
		float fminY = mMin.y > bx.mMin.y ? mMin.y : bx.mMin.y;
		float fminZ = mMin.z > bx.mMin.z ? mMin.z : bx.mMin.z;
		float fmaxX = mMax.x > bx.mMax.x ? mMax.x : bx.mMax.x;
		float fmaxY = mMax.y > bx.mMax.y ? mMax.y : bx.mMax.y;
		float fmaxZ = mMax.z > bx.mMax.z ? mMax.z : bx.mMax.z;
		newBx.Set(fminX, fminY, fminZ, fmaxX - fminX, fmaxY - fminY, fmaxZ - fminZ);
	}
	return newBx;
}
Box  Box::operator - (Vector3& vertex) {
	return Box(v.x - vertex.x, v.y - vertex.y, v.z - vertex.z, mfWidth, mfHeight, mfDepth);
}

Box  Box::operator * (float fValue) {
	return Box(v.x, v.y, v.z, mfWidth * fValue, mfHeight * fValue, mfDepth * fValue);
}
Box  Box::operator / (float fValue) {
	return Box(v.x, v.y, v.z, mfWidth / fValue, mfHeight / fValue, mfDepth / fValue);
}

class Utils
{
};

