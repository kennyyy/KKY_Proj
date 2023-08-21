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

	//뷰 좌표를 원점으로 만들기위해 이동한 카메라 포지션만큼 -해줘야 한다.
	m_mtxView._41 = -m_vCameraPos.x;
	m_mtxView._42 = -m_vCameraPos.y;
	m_mtxView._43 = -m_vCameraPos.z;


	//모든뷰는 -좌표, +좌표 두개이고
	//투영좌표는 범위가-> - 1 ~0 ~ + 1 이기때문에  2/windowLength 만큼 투영해서 값을 넣어줘야한다.
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
