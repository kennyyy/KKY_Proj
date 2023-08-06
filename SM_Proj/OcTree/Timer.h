#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")
class Timer
{
public:
	float mfGameTimer; //���ӽð�
	float mfSecondPerFrame; 
	float mfFramePerSecond;
	DWORD mdwBeforeTime; //�����ð� ����
	int miFPS = 0;

	int GetFPS();

	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};


