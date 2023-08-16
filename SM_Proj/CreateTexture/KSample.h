#pragma once
#include "KCore.h"
#include "KObject.h"


class KSample : public KCore{

	std::vector<KObject*> m_ObjList;

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

