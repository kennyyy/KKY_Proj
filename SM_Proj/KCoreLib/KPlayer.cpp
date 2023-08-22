#include "KPlayer.h"
#include "KInput.h"

bool KPlayer::Frame()
{
    if (KInput::GetInstance().m_dwKeyState['A'] > KEY_UP)
    {
        m_vPosition.x -= 500.0f * g_fSecondPerFrame;
    }
    if (KInput::GetInstance().m_dwKeyState['D'] > KEY_UP)
    {
        m_vPosition.x += 500.0f * g_fSecondPerFrame;
    }
    if (KInput::GetInstance().m_dwKeyState['W'] > KEY_UP)
    {
        m_vPosition.y += 500.0f * g_fSecondPerFrame;
    }
    if (KInput::GetInstance().m_dwKeyState['S'] > KEY_UP)
    {
        m_vPosition.y -= 500.0f * g_fSecondPerFrame;
    }

    float fSizeHalfWidth = m_vScale.x;
    float fSizeHalfHeight = m_vScale.y;
    if (m_vPosition.x < -g_fMapSizeX + fSizeHalfWidth)
    {
        m_vPosition.x = -g_fMapSizeX + fSizeHalfWidth;
    }
    if (m_vPosition.y < -g_fMapSizeY + fSizeHalfHeight)
    {
        m_vPosition.y = -g_fMapSizeY + fSizeHalfHeight;
    }
    if (m_vPosition.x > g_fMapSizeX - fSizeHalfWidth)
    {
        m_vPosition.x = g_fMapSizeX - fSizeHalfWidth;
    }
    if (m_vPosition.y > g_fMapSizeY - fSizeHalfHeight)
    {
        m_vPosition.y = g_fMapSizeY - fSizeHalfHeight;
    }

    Matrix mtxScale, mtxRotation, mtxTranslate;
    mtxScale.Scale(m_vScale);
    mtxRotation.ZRotate(m_vRotation.z);
    mtxTranslate.Translation(m_vPosition);
    m_mtxWorld = mtxScale * mtxRotation * mtxTranslate;
    return true;
}
bool KPlayer::Init()
{
    return true;
}
bool KPlayer::Render()
{
    KPlaneObj::Render();
    return true;
}
bool KPlayer::Release()
{
    return true;
}