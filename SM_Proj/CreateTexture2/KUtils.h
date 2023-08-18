#pragma once
#include "KMath.h"
struct KRect 
{
    bool  m_bEnable = true;
    float m_fWidth = 0.0f;
    float m_fHeight = 0.0f;
    KVector2 m_Point[4];
    KVector2 m_Center;
    KVector2 m_Half;
    KVector2 m_Min;
    KVector2 m_Max;
    KVector2 v;
    KVector2 s;
    bool Intersect(KRect& p, KRect& ret);
    bool operator == (KRect& p);
    bool operator != (KRect& p);
    KRect operator + (KRect& p);
    KRect operator - (KRect& p);
    KRect operator - (KVector2& p);
    KRect operator * (float fValue);
    KRect operator / (float fValue);
    void Set(KVector2 p);
    void Set(float fw, float fh);
    void Set(KVector2 p, float fw, float fh);
    void Set(float fx, float fy, float fw, float fh);

    bool ToRect(KRect& rt);
    bool ToPoint(KVector2& p);
    KRect();
    KRect(float fx, float fy, float fw, float fh);
};
struct KBox 
{
    bool  m_bEnable = true;
    float m_fWidth = 0.0f;
    float m_fHeight = 0.0f;
    float m_fDepth = 0.0f;
    KVector3 m_Point[8];
    KVector3 m_Center;
    KVector3 m_Half;
    KVector3 m_Min;
    KVector3 m_Max;
    KVector3 v;
    KVector3 s;

    bool operator == (KBox& p);
    bool operator != (KBox& p);
    // union
    KBox operator + (KBox& p);
    KBox operator - (KBox& p);
    KBox operator - (KVector3& p);
    KBox operator * (float fValue);
    KBox operator / (float fValue);
    void Set(KVector3 p);
    void Set(float fSizeX, float fSizeY, float fSizeZ);
    void Set(KVector3 p, float fw, float fh, float fz);
    void Set(float fx, float fy, float fz, float fw, float fh, float fd);

    bool ToBox(KBox& rt);
    bool ToPoint(KVector3& p);
    KBox();

    KBox(float fx, float fy, float fz,
        float fw, float fh, float fd);
};

struct KSphere
{
    KVector3 vCenter;
    float    fRadius;
};
struct KCircle
{
    KVector2 vCenter;
    float    fRadius;
};
class KUtils
{
};

