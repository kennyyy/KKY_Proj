#include "KMath.h"
bool Vector2::operator == (Vector2& p)
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
bool Vector2::operator != (Vector2& p)
{
    return !(*this == p);
}
Vector2 Vector2::operator + (Vector2& p)
{
    return Vector2(x + p.x, y + p.y);
}
Vector2 Vector2::operator - (Vector2& p)
{
    return Vector2(x - p.x, y - p.y);
}
Vector2 Vector2::operator * (float fValue)
{
    return Vector2(x * fValue, y * fValue);
}
Vector2 Vector2::operator / (float fValue)
{
    return Vector2(x / fValue, y / fValue);
}
Vector2& Vector2::operator /= (float fValue)
{
    x = x / fValue;
    y = y / fValue;
    return *this;
}
float Vector2::Length()
{
    float fDistance = sqrt(x * x + y * y);
    return fDistance;
}
static float Length(Vector2& p)
{
    float fDistance = sqrt(p.x * p.x + p.y * p.y);
    return fDistance;
}
Vector2::Vector2() {}
Vector2::Vector2(float fx, float fy)
{
    x = fx;
    y = fy;
}
float Vector3::operator | (Vector3 const& v)
{
    return x * v.x + y * v.y + z * v.z;
}
Vector3 Vector3::operator ^ (Vector3 const& v)
{
    return Vector3( y * v.z - z*v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
}
bool Vector3::operator == (Vector3& p)
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
bool Vector3::operator != (Vector3& p)
{
    return !(*this == p);
}
Vector3 Vector3::operator + (Vector3& p)
{
    return Vector3(x + p.x, y + p.y, z + p.z);
}
Vector3 Vector3::operator - (Vector3& p)
{
    return Vector3(x - p.x, y - p.y, z - p.z);
}
Vector3 Vector3::operator * (float fValue)
{
    return Vector3(x * fValue, y * fValue, z * fValue);
}
Vector3 Vector3::operator / (float fValue)
{
    return Vector3(x / fValue, y / fValue, z / fValue);
}
Vector3& Vector3::operator /= (float fValue)
{
    x = x / fValue;
    y = y / fValue;
    z = z / fValue;
    return *this;
}
float Vector3::Length()
{
    float fDistance = sqrt(x * x + y * y + z * z);
    return fDistance;
}
static float GetDistance(Vector3& p)
{
    float fDistance = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
    return fDistance;
}
Vector3::Vector3() {}
Vector3::Vector3(float fx, float fy, float fz) 
{
    x = fx;
    y = fy;
    z = fz;
}
Vector3 Vector3::operator * (Matrix const& m)
{
    Vector4 t;
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
    return Vector3(t.x, t.y, t.z);
}
void Vector3::Normalize()
{
    float fInvertLength = 1.0f / Length();
    x = x * fInvertLength;
    y = y * fInvertLength;
    z = z * fInvertLength;
}
Vector3 Vector3::NormalVector()
{
    float fInvertLength = 1.0f / Length();    
    return (*this) * fInvertLength;
}
float Vector3::Angle(Vector3& v)
{
    // ¡§±‘»≠
    Vector3 a = NormalVector();
    Vector3 b = v.NormalVector();
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