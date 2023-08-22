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
	 
	
	if (m_vPosition.x < -(g_fMapSizeX / 2.0f) + (m_vScale.x / 2.0f)) {
		m_vDirection.x *= -1.0f;
		m_vPosition.x = -(g_fMapSizeX / 2.0f)+ (m_vScale.x / 2.0f);
	}
	if (m_vPosition.x > (g_fMapSizeX / 2.0f) - (m_vScale.x / 2.0f)) {
		m_vDirection.x *= -1.0f;
		m_vPosition.x = (g_fMapSizeX / 2.0f) - (m_vScale.x / 2.0f);
	}
	if (m_vPosition.y < -(g_fMapSizeY/ 2.0f) + (m_vScale.y/ 2.0f)) {
		m_vDirection.y *= -1.0f;
		m_vPosition.y = -(g_fMapSizeY / 2.0f) + (m_vScale.y / 2.0f);
	}
	if (m_vPosition.y > (g_fMapSizeY / 2.0f) - (m_vScale.y / 2.0f)) {
		m_vDirection.y *= -1.0f;
		m_vPosition.y = (g_fMapSizeY / 2.0f) - (m_vScale.y / 2.0f);
	}
}
bool KNpcObj::Frame() {
	Matrix mtxScale, mtxRotation, mtxTranslate;
	mtxScale.Scale(m_vScale);
	mtxRotation.ZRotate(m_vRotation.z);
	mtxTranslate.Translation(m_vPosition);
	m_mtxWorld = mtxScale * mtxRotation * mtxTranslate;
	return true;
}