#pragma once
#include "KObject.h"
#include"KInput.h"
class KPlaneObj : public KObject
{
public:
	virtual bool CreateVertexBuffer() override;
	virtual bool	CreateIndexBuffer() override;
	virtual bool Frame();
};

