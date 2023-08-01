#pragma once
#include "Utils.h"


class Collision
{
public:
	static bool RectToRect(Rect& rt1, Rect& rt2)
	{
		Rect sum = rt1 + rt2;
		float fX = rt1.mfWidth + rt2.mfWidth;
		float fY = rt1.mfHeight + rt2.mfHeight;
		if (sum.mfWidth <= fX)
		{
			if (sum.mfHeight <= fY)
			{
				return true;
			}
		}
		return false;
	}
	static bool RectToPoint(Rect& rt, Vector2& p)
	{
		if (rt.mMin.x <= p.x && rt.mMax.x >= p.x
			&&
			rt.mMin.y <= p.y && rt.mMax.y >= p.y)
		{
			return true;
		}
		return false;
	}
};

