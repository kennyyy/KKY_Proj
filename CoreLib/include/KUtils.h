#pragma once
#include "KMath.h"
struct UVRect
{
    Vector2 m_Min;
    Vector2 m_Max;
};
struct Rect 
{
    bool  m_bEnable = true;
    float m_fWidth = 0.0f;
    float m_fHeight = 0.0f;
    Vector2 m_Point[4];
    Vector2 m_Center;
    Vector2 m_Half;
    Vector2 m_Min;
    Vector2 m_Max;
    Vector2 v;
    Vector2 s;
    bool Intersect(Rect& p, Rect& ret);
    bool operator == (Rect& p);
    bool operator != (Rect& p);
    Rect operator + (Rect& p);
    Rect operator - (Rect& p);
    Rect operator - (Vector2& p);
    Rect operator * (float fValue);
    Rect operator / (float fValue);
    void Set(Vector2 p);
    void Set(float fw, float fh);
    void Set(Vector2 p, float fw, float fh);
    void Set(float fx, float fy, float fw, float fh);

    bool ToRect(Rect& rt);
    bool ToPoint(Vector2& p);
    Rect();
    Rect(float fx, float fy, float fw, float fh);
};
struct Box 
{
    bool  m_bEnable = true;
    float m_fWidth = 0.0f;
    float m_fHeight = 0.0f;
    float m_fDepth = 0.0f;
    Vector3 m_Point[8];
    Vector3 m_Center;
    Vector3 m_Half;
    Vector3 m_Min;
    Vector3 m_Max;
    Vector3 v;
    Vector3 s;

    bool operator == (Box& p);
    bool operator != (Box& p);
    // union
    Box operator + (Box& p);
    Box operator - (Box& p);
    Box operator - (Vector3& p);
    Box operator * (float fValue);
    Box operator / (float fValue);
    void Set(Vector3 p);
    void Set(float fSizeX, float fSizeY, float fSizeZ);
    void Set(Vector3 p, float fw, float fh, float fz);
    void Set(float fx, float fy, float fz, float fw, float fh, float fd);

    bool ToBox(Box& rt);
    bool ToPoint(Vector3& p);
    Box();

    Box(float fx, float fy, float fz,
        float fw, float fh, float fd);
};

struct Sphere
{
    Vector3 vCenter;
    float    fRadius;
};
struct Circle
{
    Vector2 vCenter;
    float    fRadius;
};
class KUtils
{
};

