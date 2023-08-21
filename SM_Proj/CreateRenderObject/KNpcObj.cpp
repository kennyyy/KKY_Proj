#include "KNpcObj.h"

void KNpcObj::SetDirection(Vector3 d) {
	m_vDirection = d - m_vPosition;
	float fDistance = m_vDirection.Length();
	m_vDirection /= fDistance;
}
void KNpcObj::Move(float fSecond) {
	//Vector3 vVelocity = mDirection * mfSpeed * fSecond;
	Vector3 vVelocity = m_vDirection * 500.0f * fSecond;
	m_vPosition = m_vPosition + vVelocity;
	
	if (m_vPosition.x < -1000.0f) {
		m_vDirection.x *= -1.0f;
		m_vPosition.x = -1000.0f;
	}
	if (m_vPosition.x > 1000.0f) {
		m_vDirection.x *= -1.0f;
		m_vPosition.x = 1000.0f;
	}
	if (m_vPosition.y < -1000.0f) {
		m_vDirection.y *= -1.0f;
		m_vPosition.y = -1000.0f;
	}
	if (m_vPosition.y > 1000.0f) {
		m_vDirection.y *= -1.0f;
		m_vPosition.y = 1000.0f;
	}
}
bool KNpcObj::Frame() {
	Matrix mtxScale, mtxRotation, mtxTranslate;
	mtxScale.Sclae(m_vScale);
	mtxRotation.ZRotate(m_vRotation.z);
	mtxTranslate.Translation(m_vPosition);
	m_mtxWorld = mtxScale * mtxRotation * mtxTranslate;
	return true;
}