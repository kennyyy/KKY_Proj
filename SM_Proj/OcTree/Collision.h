#pragma once
#include "Utils.h"


class Collision
{
public:
	/*static bool RectToRect(Rect& rt1, Rect& rt2) {
		Rect sum = rt1 + rt2;
	}*/
	static bool RecToPoint(Rect& rt1, Rect& rt2);
};

