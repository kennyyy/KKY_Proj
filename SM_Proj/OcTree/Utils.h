#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <math.h>


struct Point {
	float x;
	float y;
	Point operator + (Point& p) {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (Point& p) {
		return Point(x - p.x, y - p.y);
	}
	Point operator * (float fValue) {
		return Point(x * fValue, y * fValue);
	}
	Point operator / (float fValue) {
		return Point(x / fValue, y / fValue);
	}
	Point& operator /= (float fValue) {
		x = x / fValue;
		y = y / fValue;
		return *this;
	}
	float GetDistance() {
		float fDistance = sqrt(x * x + y * y);
		return fDistance;
	}
	static float GetDistance(Point& p) {
		float fDistance = sqrt(p.x * p.x+ p.y * p.y);
		return fDistance;
	}

	Point(){}
	Point(float fx, float fy): x(fx), y(fy){}
	
};

struct Rect{
	float mfx;
	float mfy;
	float mfWidth;
	float mfHeight;
	Point mPoint[4];
	Point mHalf;
	Point mCenterPoint;
	Point mMin;
	Point mMax;
	Point v;
	Point s;
	Rect(){}
	Rect(float fx, float fy, float fw, float fh) {
		Set(fx, fy, fw, fh);
	}
	void Set(float fx, float fy, float fw, float fh) {
		v = { fx, fy };
		s = { fw, fh };

		mfx = fx;
		mfy = fy;
		mfWidth = fw;
		mfHeight = fh;
		mHalf = { mfWidth * 0.5f, mfHeight * 0.5f };
		mPoint[0] = { mfx, mfy };
		mPoint[1] = { mfx + mfWidth , mfy };
		mPoint[2] = { mfx +mfWidth , mfy +mfHeight};
		mPoint[3] = { mfx , mfy + mfHeight };
		mCenterPoint = ( mPoint[0] + mPoint[2]) * 0.5f;

	}


};





class Utils
{
};

