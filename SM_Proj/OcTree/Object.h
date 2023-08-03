#pragma once
#include "Collision.h"


class Object
{
public:
	std::wstring mName;
	Vector3 mPosition;
	Box  mbx;
	virtual void Move(float fSecond) {};
	virtual void SetTarget(Vector3& t) {};
	virtual void SetBox(Vector3& vertex, float w, float h, float d) {}
	
};
void Object:: SetBox(Vector3& vertex, float w, float h, float d) {
	mbx.Set(vertex, w, h, d);
}

class StaticObject : public Object {
public:
	void Move(float fSecond) {};
};

class DynamicObject : public Object {
public:
	float mfSpeed = 100.0f;
	Vector3 mDirection;
	Vector3 mTarget;
public:
	void Move(float fSecond);
	void SetTarget(Vector3& t);

public:
	DynamicObject() {
		mDirection.x = 0.0f;
		mDirection.y = 0.0f;
		mDirection.z = 0.0f;
	}

};

void DynamicObject::SetTarget(Vector3& t) {
	mTarget = t;
	mDirection = t - mPosition;
	float fDistance = mDirection.Length();
	mDirection /= fDistance;
}

void  DynamicObject::Move(float fSecond) {
	Vector3 vVelocity = mDirection * mfSpeed * fSecond;
	mPosition = mPosition + vVelocity;

	//충돌시 방향 전환
	if (mPosition.x < 0.0f) {
		mDirection.x *= -1.0f;
		mPosition.x = 0.0f;
	}
	if (mPosition.y < 0.0f) {
		mDirection.y *= -1.0f;
		mPosition.y = 0.0f;
	}
	if (mPosition.z < 0.0f) {
		mDirection.z *= -1.0f;
		mPosition.z = 0.0f;
	}
	if (mPosition.x > 800.0f) {
		mDirection.x *= -1.0f;
		mPosition.x = 800.0f;
	}
	if (mPosition.y > 600.0f) {
		mDirection.y *= -1.0f;
		mPosition.y = 600.0f;
	}
	if (mPosition.z > 600.0f) {
		mDirection.z *= -1.0f;
		mPosition.z = 600.0f;
	}
}


