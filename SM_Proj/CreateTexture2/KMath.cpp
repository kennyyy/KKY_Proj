#include "KMath.h"
bool KVector2::operator == (KVector2& p)
{
    if (fabs(x - p.x) > T_EPSILON)
    {
        if (fabs(y - p.y) > T_EPSILON)
        {
            return true;
        }
    }
    return false;
}
bool KVector2::operator != (KVector2& p)
{
    return !(*this == p);
}
KVector2 KVector2::operator + (KVector2& p)
{
    return KVector2(x + p.x, y + p.y);
}
KVector2 KVector2::operator - (KVector2& p)
{
    return KVector2(x - p.x, y - p.y);
}
KVector2 KVector2::operator * (float fValue)
{
    return KVector2(x * fValue, y * fValue);
}
KVector2 KVector2::operator / (float fValue)
{
    return KVector2(x / fValue, y / fValue);
}
KVector2& KVector2::operator /= (float fValue)
{
    x = x / fValue;
    y = y / fValue;
    return *this;
}
float KVector2::Length()
{
    float fDistance = sqrt(x * x + y * y);
    return fDistance;
}
static float Length(KVector2& p)
{
    float fDistance = sqrt(p.x * p.x + p.y * p.y);
    return fDistance;
}
KVector2::KVector2() {}
KVector2::KVector2(float fx, float fy)
{
    x = fx;
    y = fy;
}
float KVector3::operator | (KVector3 const& v)
{
    return x * v.x + y * v.y + z * v.z;
}
KVector3 KVector3::operator ^ (KVector3 const& v)
{
    return KVector3( y * v.z - z*v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
}
bool KVector3::operator == (KVector3& p)
{
    if (fabs(x - p.x) > T_EPSILON)
    {
        if (fabs(y - p.y) > T_EPSILON)
        {
            if (fabs(z - p.z) > T_EPSILON)
            {
                return true;
            }
        }
    }
    return false;
}
bool KVector3::operator != (KVector3& p)
{
    return !(*this == p);
}
KVector3 KVector3::operator + (KVector3& p)
{
    return KVector3(x + p.x, y + p.y, z + p.z);
}
KVector3 KVector3::operator - (KVector3& p)
{
    return KVector3(x - p.x, y - p.y, z - p.z);
}
KVector3 KVector3::operator * (float fValue)
{
    return KVector3(x * fValue, y * fValue, z * fValue);
}
KVector3 KVector3::operator / (float fValue)
{
    return KVector3(x / fValue, y / fValue, z / fValue);
}
KVector3& KVector3::operator /= (float fValue)
{
    x = x / fValue;
    y = y / fValue;
    z = z / fValue;
    return *this;
}
float KVector3::Length()
{
    float fDistance = sqrt(x * x + y * y + z * z);
    return fDistance;
}
static float GetDistance(KVector3& p)
{
    float fDistance = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
    return fDistance;
}
KVector3::KVector3() {}
KVector3::KVector3(float fx, float fy, float fz) 
{
    x = fx;
    y = fy;
    z = fz;
}
KVector3 KVector3::operator * (KMatrix const& m)
{
    KVector4 t;
    t.x = x * m._11 + y * m._21 + z * m._31 + 1.0f * m._41;
    t.y = x * m._12 + y * m._22 + z * m._32 + 1.0f * m._42;
    t.z = x * m._13 + y * m._23 + z * m._33 + 1.0f * m._43;
    t.w = x * m._14 + y * m._24 + z * m._34 + 1.0f * m._44;

    if (fabs(t.w - 0.0f) > T_EPSILON)
    {
        t.x /= t.w;
        t.y /= t.w;
        t.z /= t.w;
        t.w /= t.w;
    }
    return KVector3(t.x, t.y, t.z);
}
void KVector3::Normalize()
{
    float fInvertLength = 1.0f / Length();
    x = x * fInvertLength;
    y = y * fInvertLength;
    z = z * fInvertLength;
}
KVector3 KVector3::NormalVector()
{
    float fInvertLength = 1.0f / Length();    
    return (*this) * fInvertLength;
}
float KVector3::Angle(KVector3& v)
{
    // ¡§±‘»≠
    KVector3 a = NormalVector();
    KVector3 b = v.NormalVector();
    float fCosAngle = a | b;
    float fRadian = acos(fCosAngle);
    float fDegree = RadianToDegree(fRadian);
    return fDegree;
   /* float fLength1 = Length();
    float fLength2 = v.Length();
    float fDot = *this | v;
    float fCosAngle = fDot / (fLength1 * fLength2);
    float fRadian = acos(fCosAngle);
    float fDegree = RadianToDegree(fRadian);
    return fDegree;*/
}