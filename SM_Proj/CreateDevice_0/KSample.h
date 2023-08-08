#pragma once
#include "KCore.h"

class KSample : public KCore
{
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

