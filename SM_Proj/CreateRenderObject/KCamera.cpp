#include "KCamera.h"

bool KCamera::Create(Vector3 vCamPos, Vector2 CamSize) {
	m_vCameraPos = vCamPos;
	m_dwWindowWidth = CamSize.x;
	m_dwWindowHeight = CamSize.y;
	return true;
}
bool  KCamera::Init() {
	return true;
}
bool  KCamera::Frame() {
	float fHalfWidth = m_dwWindowWidth / 2.0f;
	float fHalfHeight = m_dwWindowHeight / 2.0f;

	if (m_vCameraPos.x < -(g_fMapSizeX / 2.0f)+fHalfWidth) {
		m_vCameraPos.x = -(g_fMapSizeX / 2.0f)+fHalfWidth;
	}
	if (m_vCameraPos.x > (g_fMapSizeX / 2.0f) - fHalfWidth) {
		m_vCameraPos.x = (g_fMapSizeX  / 2.0f) - fHalfWidth;
	}
	if (m_vCameraPos.y < -(g_fMapSizeY / 2.0f) + fHalfHeight) {
		m_vCameraPos.y = -(g_fMapSizeY / 2.0f) + fHalfHeight;
	}
	if (m_vCameraPos.y > (g_fMapSizeY / 2.0f) - fHalfHeight) {
		m_vCameraPos.y = (g_fMapSizeY / 2.0f) - fHalfHeight;
	}

	//�� ��ǥ�� �������� ��������� �̵��� ī�޶� �����Ǹ�ŭ -����� �Ѵ�.
	m_mtxView._41 = -m_vCameraPos.x;
	m_mtxView._42 = -m_vCameraPos.y;
	m_mtxView._43 = -m_vCameraPos.z;


	//����� -��ǥ, +��ǥ �ΰ��̰�
	//������ǥ�� ������-> - 1 ~0 ~ + 1 �̱⶧����  2/windowLength ��ŭ �����ؼ� ���� �־�����Ѵ�.
	m_mtxOrthoProjection._11 = 2.0f / ((float)m_dwWindowWidth);
	m_mtxOrthoProjection._22 = 2.0f / ((float)m_dwWindowHeight);
	return true;
}
bool  KCamera::Render() {
	return true;
}
bool  KCamera::Release() {
	return true;
}
