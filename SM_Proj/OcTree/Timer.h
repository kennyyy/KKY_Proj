#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")
class Timer
{
public:
	float mfGameTimer; //게임시간
	float mfSecondPerFrame; 
	float mfFramePerSecond;
	DWORD mdwBeforeTime; //이전시간 저장
	int miFPS = 0;

	int GetFPS();

	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};


