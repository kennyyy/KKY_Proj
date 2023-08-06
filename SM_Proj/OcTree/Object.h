#pragma once
#include "Collision.h"

const float gfMapSize = 1000.0f;

class Object{
public:
	std::wstring mName;
	Vector3 mPosition;
	Box  mbx;

	virtual void Move(float fSecond) {};
	virtual void SetTarget(Vector3& t) {};
	virtual void SetBox(Vector3& vertex, float w, float h, float d);
};

class DynamicObject : public Object {
public:
	float mfSpeed = 100.0f;
	Vector3 mDirection;
	Vector3 mTarget;

	void Move(float fSecond);
	void SetTarget(Vector3& t);

public:
	DynamicObject() {
		mDirection.x = 0.0f;
		mDirection.y = 0.0f;
		mDirection.z = 0.0f;
	}
};

class StaticObject : public Object {
};



