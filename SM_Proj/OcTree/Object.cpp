#include "Object.h"

void  DynamicObject::Move(float fSecond) {
	Vector3 vVelocity = mDirection * mfSpeed * fSecond;
	mPosition = mPosition + vVelocity;
	mbx.Set(mPosition, mbx.mfWidth, mbx.mfHeight, mbx.mfDepth);

	//충돌시 방향 전환
	if (mPosition.x < -gfMapSize * 0.5) {
		mDirection.x *= -1.0f;
		mPosition.x = -gfMapSize * 0.5;
	}
	if (mPosition.y < -gfMapSize * 0.5) {
		mDirection.y *= -1.0f;
		mPosition.y = -gfMapSize * 0.5;
	}
	if (mPosition.z < -gfMapSize * 0.5) {
		mDirection.z *= -1.0f;
		mPosition.z = -gfMapSize * 0.5;
	}

	if (mPosition.x > gfMapSize * 0.5) {
		mDirection.x *= -1.0f;
		mPosition.x = gfMapSize * 0.5;
	}
	if (mPosition.y > gfMapSize * 0.5) {
		mDirection.y *= -1.0f;
		mPosition.y = gfMapSize * 0.5;
	}
	if (mPosition.z > gfMapSize * 0.5) {
		mDirection.z *= -1.0f;
		mPosition.z = gfMapSize * 0.5;
	}
}

void DynamicObject::SetTarget(Vector3& t) {
	mTarget = t;
	mDirection = t - mPosition;
	float fDistance = mDirection.Length();
	mDirection /= fDistance;
}

void Object::SetBox(Vector3& vertex, float w, float h, float d) {
	mbx.Set(vertex, w, h, d);
}