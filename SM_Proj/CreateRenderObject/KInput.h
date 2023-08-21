#pragma once
#include "KStd.h"

enum KeyState {
	KEY_FREE = 0,
	KEY_UP = 1, //Å°¸¦ ´­·¶´Ù ¶®À»¶§
	KEY_PUSH = 2,
	KEY_HOLD = 3,
};

class KInput
{
public:
	POINT m_MousePos;
	DWORD m_dwKeyState[256];
	static KInput& GetInstance() {
		static KInput input;
		return input;
	}

public:
	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();
private:
	KInput() {};
public:
	~KInput() {}
};

