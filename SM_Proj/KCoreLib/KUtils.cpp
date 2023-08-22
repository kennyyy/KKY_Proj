#include "KUtils.h"
bool Rect::Intersect(Rect& p, Rect& ret)
{
    return false;
}
bool Rect::operator == (Rect& p)
{
    if (fabs(v.x - p.v.x) > 0.0001f)
    {
        if (fabs(v.y - p.v.y) > 0.0001f)
        {
            if (fabs(m_fWidth - p.m_fWidth) > 0.0001f)
            {
                if (fabs(m_fHeight - p.m_fHeight) > 0.0001f)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool Rect::operator != (Rect& p)
{
    return !(*this == p);
}
Rect Rect::operator + (Rect& p)
{
    Rect rt;
    float fMinX = min(m_Min.x, p.m_Min.x);
    float fMinY = min(m_Min.y, p.m_Min.y);
    float fMaxX = max(m_Max.x, p.m_Max.x);
    float fMaxY = max(m_Max.y, p.m_Max.y);
    Vector2 centerPos = { (fMinX + fMaxX)*0.5f , (fMinY+ fMaxY) * 0.5f };
    rt.Set(centerPos, fMaxX - fMinX, fMaxY - fMinY);
    return rt;
}
Rect Rect::operator - (Rect& p)
{
    Rect rt;
    rt.m_bEnable = false;
    if (ToRect(p))
    {
        //left, top          right
        //      bottom
        float fMinX = (m_Min.x > p.m_Min.x) ? m_Min.x : p.m_Min.x;
        float fMinY = (m_Min.y > p.m_Min.y) ? m_Min.y : p.m_Min.y;
        float fMaxX = (m_Max.x < p.m_Max.x) ? m_Max.x : p.m_Max.x;
        float fMaxY = (m_Max.y < p.m_Max.y) ? m_Max.y : p.m_Max.y;
        Vector2 centerPos = { (fMinX + fMaxX) * 0.5f , (fMinY + fMaxY) * 0.5f };
        rt.Set(centerPos, fMaxX - fMinX, fMaxY - fMinY);
        rt.m_bEnable = true;
    }
    return rt;
}
Rect Rect::operator - (Vector2& p)
{
    v.x -= p.x;
    v.y -= p.y;
    return Rect(v.x, v.y, m_fWidth, m_fHeight);
}
Rect Rect::operator * (float fValue)
{
    if (fValue <= 0.0f)
    {
        return *this;
    }
    m_fWidth *= fValue;
    m_fHeight *= fValue;
    return Rect(v.x, v.y, m_fWidth, m_fHeight);
}
Rect Rect::operator / (float fValue)
{
    if (fValue <= 0.0f)
    {
        return *this;
    }
    m_fWidth /= fValue;
    m_fHeight /= fValue;
    return Rect(v.x, v.y, m_fWidth, m_fHeight);
}
void Rect::Set(Vector2 p)
{
    m_Center = p;
    v = { p.x, p.y };
    s = { m_fWidth, m_fHeight };
    Set(m_fWidth, m_fHeight);
}
void Rect::Set(float fw, float fh)
{
    m_fWidth = fw;
    m_fHeight = fh;
    m_Half = { m_fWidth * 0.5f,m_fHeight * 0.5f };
    m_Point[0] = { v.x - m_fWidth, v.y + m_fHeight };
    m_Point[1] = { v.x + m_fWidth, v.y + m_fHeight };
    m_Point[2] = { v.x + m_fWidth, v.y - m_fHeight };
    m_Point[3] = { v.x - m_fWidth, v.y - m_fHeight  };
    m_Min = m_Point[3];
    m_Max = m_Point[1];
}
void Rect::Set(Vector2 p, float fw, float fh)
{
    m_Center = p;
    v = p;
    s = { fw, fh };
    Set(fw, fh);
}
void Rect::Set(float fx, float fy, float fw, float fh)
{
    m_Center.x = fx;
    m_Center.y = fy;
    v = { fx, fy };
    s = { fw, fh };
    Set(fw, fh);
}

bool Rect::ToRect(Rect& rt)
{
    Rect sum = (*this) + rt;
    float fX = m_fWidth + rt.m_fWidth;
    float fY = m_fHeight + rt.m_fHeight;
    if (sum.m_fWidth <= fX)
    {
        if (sum.m_fHeight <= fY)
        {
            return true;
        }
    }
    return false;
}
bool Rect::ToPoint(Vector2& p)
{
    if (m_Min.x <= p.x && m_Max.x >= p.x &&
        m_Min.y <= p.y && m_Max.y >= p.y)
    {
        return true;
    }
    return false;
}
Rect::Rect() : m_bEnable(true) {}

Rect::Rect(float fx, float fy, float fw, float fh)
{
    m_bEnable = true;
    Set(fx, fy, fw, fh);
}


///
/////
bool Box::operator == (Box& p)
{
    if (fabs(v.x - p.v.x) > 0.0001f)
    {
        if (fabs(v.y - p.v.y) > 0.0001f)
        {
            if (fabs(v.z - p.v.z) > 0.0001f)
            {
                if (fabs(m_fWidth - p.m_fWidth) > 0.0001f)
                {
                    if (fabs(m_fHeight - p.m_fHeight) > 0.0001f)
                    {
                        if (fabs(m_fDepth - p.m_fDepth) > 0.0001f)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool Box::operator != (Box& p)
{
    return !(*this == p);
}
// union
Box Box::operator + (Box& p)
{
    Box rt;
    float fMinX = min(v.x, p.v.x);
    float fMinY = min(v.y, p.v.y);
    float fMinZ = min(v.z, p.v.z);
    float fMaxX = max(m_Max.x, p.m_Max.x);
    float fMaxY = max(m_Max.y, p.m_Max.y);
    float fMaxZ = max(m_Max.z, p.m_Max.z);
    Vector3 pos = { fMinX, fMinY, fMinZ };
    rt.Set(pos, fMaxX - fMinX, fMaxY - fMinY, fMaxZ - fMinZ);
    return rt;
}
Box Box::operator - (Box& p)
{
    Box rt;
    rt.m_bEnable = false;
    if (ToBox(p))
    {
        //left, top          right
        //      bottom
        float fx = (m_Min.x > p.m_Min.x) ? m_Min.x : p.m_Min.x;
        float fy = (m_Min.y > p.m_Min.y) ? m_Min.y : p.m_Min.y;
        float fz = (m_Min.z > p.m_Min.z) ? m_Min.z : p.m_Min.z;

        float right = (m_Max.x < p.m_Max.x) ? m_Max.x : p.m_Max.x;
        float bottom = (m_Max.y < p.m_Max.y) ? m_Max.y : p.m_Max.y;
        float depth = (m_Max.z < p.m_Max.z) ? m_Max.z : p.m_Max.z;
        rt.Set(fx, fy, fz, right - fx, bottom - fy, depth - fz);
        rt.m_bEnable = true;
    }
    return rt;
}
Box Box::operator - (Vector3& p)
{
    v.x -= p.x;
    v.y -= p.y;
    v.z -= p.z;
    return Box(v.x, v.y, v.z, m_fWidth, m_fHeight, m_fDepth);
}
Box Box::operator * (float fValue)
{
    if (fValue <= 0.0f)
    {
        return *this;
    }
    m_fWidth *= fValue;
    m_fHeight *= fValue;
    m_fDepth *= fValue;
    return Box(v.x, v.y, v.z, m_fWidth, m_fHeight, m_fDepth);
}
Box Box::operator / (float fValue)
{
    if (fValue <= 0.0f)
    {
        return *this;
    }
    m_fWidth /= fValue;
    m_fHeight /= fValue;
    m_fDepth /= fValue;
    return Box(v.x, v.y, v.z, m_fWidth, m_fHeight, m_fDepth);
}
void Box::Set(Vector3 p)
{
    v = p;
    s = { m_fWidth, m_fHeight, m_fDepth };
    Set(m_fWidth, m_fHeight, m_fDepth);
}
void Box::Set(float fSizeX, float fSizeY, float fSizeZ)
{
    m_fWidth = fSizeX;
    m_fHeight = fSizeY;
    m_fDepth = fSizeZ;
    m_Half = { m_fWidth * 0.5f,m_fHeight * 0.5f, m_fDepth * 0.5f };
    m_Point[0] = { v.x - m_Half.x, v.y + m_Half.y, v.z - m_Half.z };
    m_Point[1] = m_Point[0];
    m_Point[1].x += m_fWidth;
    m_Point[2] = m_Point[1];
    m_Point[2].y -= m_fHeight;
    m_Point[3] = m_Point[2];
    m_Point[3].x = m_Point[0].x;

    m_Point[4] = { v.x - m_Half.x, v.y + m_Half.y, v.z + m_Half.z };
    m_Point[5] = m_Point[4];
    m_Point[5].x += m_fWidth;
    m_Point[6] = m_Point[5];
    m_Point[6].y -= m_fHeight;
    m_Point[7] = m_Point[6];
    m_Point[7].x = m_Point[4].x;

    m_Min = m_Point[3];
    m_Max = m_Point[5];
    m_Center = (m_Max + m_Min) * 0.5f;
}
void Box::Set(Vector3 p, float fw, float fh, float fz)
{
    v = p;
    s = { fw, fh, fz };
    Set(fw, fh, fz);
}
void Box::Set(float fx, float fy, float fz, float fw, float fh, float fd)
{
    v = { fx, fy, fz };
    s = { fw, fh, fd };
    Set(fw, fh, fd);
}

bool Box::ToBox(Box& rt)
{
    Box sum = (*this) + rt;
    float fX = m_fWidth + rt.m_fWidth;
    float fY = m_fHeight + rt.m_fHeight;
    float fZ = m_fDepth + rt.m_fDepth;
    if (sum.m_fWidth <= fX)
    {
        if (sum.m_fHeight <= fY)
        {
            if (sum.m_fDepth <= fZ)
            {
                return true;
            }
        }
    }
    return false;
}
bool Box::ToPoint(Vector3& p)
{
    if (m_Min.x <= p.x && m_Max.x >= p.x &&
        m_Min.y <= p.y && m_Max.y >= p.y &&
        m_Min.z <= p.z && m_Max.z >= p.z)
    {
        return true;
    }
    return false;
}
Box::Box() : m_bEnable(true) {}

Box::Box(float fx, float fy, float fz,
    float fw, float fh, float fd)
{
    m_bEnable = true;
    Set(fx, fy, fz, fw, fh, fz);
}
