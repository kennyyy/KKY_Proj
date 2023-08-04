#include "Timer.h"

bool Timer::Init() {
	mfGameTimer = 0.0f;
	mfSecondPerFrame = 0.0f;
	mfFramePerSecond = 0.0f;
	mdwBeforeTime = timeGetTime();
	return true;
}

int Timer::GetFPS() {
	static int FPS = 0;
	if (mfSecondPerFrame >= 1.0f) {
		miFPS = FPS;
		FPS = 0;
		mfSecondPerFrame -= 1.0f;
	}
	FPS++;
	return miFPS;
}

bool Timer::Frame() {
	DWORD dwCurrnetTime = timeGetTime();
	DWORD dwElapseTime = dwCurrnetTime - mdwBeforeTime;
	mfSecondPerFrame = dwElapseTime / 1000.0f;
	mdwBeforeTime = dwCurrnetTime;
	mfGameTimer += mfSecondPerFrame;
	return true;
}

bool Timer::Render() {
	std::cout << "[FPS]" << GetFPS() << "[GAMETIME]" << mfGameTimer << "[SPF]" << mfSecondPerFrame << std::endl;
	return true;
}
bool Timer::Release() {
	return true;
}
