#pragma once
#include "KPlaneObj.h"
class KNpcObj : public KPlaneObj
{
	Vector3 m_vDirection;
public:
	void SetDirection(Vector3 d);
	void Move(float fSecond);
	virtual bool Frame();
	virtual ~KNpcObj() {};
};

