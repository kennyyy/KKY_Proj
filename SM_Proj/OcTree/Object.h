#pragma once
#include "Collision.h"


class Object2D
{
public:
	std::wstring mName;
	Vector2 mPosition;
	Rect mtRT;
	virtual void Move(float fSecond) {};
	virtual void SetTarget(Vector2& t) {};
	virtual void SetRect(Vector2& r, float w, float h) {
		mtRT.Set(r, w, h);
	}
	
};

class StaticObject2D : public Object2D {
public:
	void Move(float fSecond) {};
};


class DynamicObject2D : public Object2D {
public:
	float mfSpeed = 100.0f;
	Vector2 mDirection;
	Vector2 mTarget;
public:
	void Move(float fSecond);
	void SetTarget(Vector2& t);

public:
	DynamicObject2D() {
		mDirection.x = 0.0f;
		mDirection.y = 0.0f;
	}

};

void DynamicObject2D::SetTarget(Vector2& t) {
	mTarget = t;
	mDirection = t - mPosition;
	float fDistance = mDirection.GetDistance();
	mDirection /= fDistance;
}

void  DynamicObject2D::Move(float fSecond) {
	Vector2 vVelocity = mDirection * mfSpeed * fSecond;
	mPosition = mPosition + vVelocity;

	//충돌시 방향 전환
	if (mPosition.x < 0.0f) {
		mDirection.x *= -1.0f;
		mPosition.x = 0.0f;
	}
}

class Object3D {
	int mNodeIndex = -1;
	std::wstring mName;

};

