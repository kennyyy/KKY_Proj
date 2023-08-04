#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")
class Timer
{
public:
	float mfGameTimer;
	float mfSecondPerFrame;
	float mfFramePerSecond;
	DWORD mdwBeforeTime;
	int miFPS = 0;
public:
	int GetFPS();
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};


