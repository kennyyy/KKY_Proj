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
			if (sum.mfHeight <= fY)
				return true;

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

	static bool BoxToBox(Box& bx1, Box& bx2) {
		if (bx1.mMin.x <= bx2.mMin.x && bx1.mMax.x >= bx2.mMax.x)
			if (bx1.mMin.y <= bx2.mMin.y && bx1.mMax.y >= bx2.mMax.y)
				if (bx1.mMin.z <= bx2.mMin.z && bx1.mMax.z >= bx2.mMax.z)
					return true;

				return false;
	}

	static bool BoxToPoint(Rect& rt, Vector2& p)
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

