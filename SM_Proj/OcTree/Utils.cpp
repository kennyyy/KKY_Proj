#include "Collision.h"

//Rect
bool Rect::operator == (Rect& rt) {
	if (fabs(v.x - rt.v.x) < _EPSILON)
		if (fabs(v.y - rt.v.y) < _EPSILON)
			if (fabs(mfWidth - rt.mfWidth) < _EPSILON)
				if (fabs(mfHeight - rt.mfHeight < _EPSILON))
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

//Box

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
Box  Box::operator - (Box& bx) {
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