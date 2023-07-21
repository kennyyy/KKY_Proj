#pragma once
#include "Collision.h"


class Object
{
public:
	std::wstring mName;
	Point mPosition;
	Rect mtRT;
	virtual void Move(float fSecond) {};
	virtual void SetTarget(Point& t) {};
	virtual void SetRect(Point& r, float w, float h) {
		mtRT.Set(r, w, h);
	}
	
};

class StaticObject : public Object {
public:
	void Move(float fSecond) {};
};


class DynamicObject : public Object {
public:
	float mfSpeed = 100.0f;
	Point mDirection;
	Point mTarget;
public:
	void Move(float fSecond);
	void SetTarget(Point& t);

public:
	DynamicObject() {
		mDirection.x = 0.0f;
		mDirection.y = 0.0f;
	}

};

void DynamicObject::SetTarget(Point& t) {
	mTarget = t;
	mDirection = t - mPosition;
	float fDistance = mDirection.GetDistance();
	mDirection /= fDistance;
}

void  DynamicObject::Move(float fSecond) {
	Point vVelocity = mDirection * mfSpeed * fSecond;
	mPosition = mPosition + vVelocity;

	//충돌시 방향 전환
	if (mPosition.x < 0.0f) {
		mDirection.x *= -1.0f;
		mPosition.x = 0.0f;
	}
}


