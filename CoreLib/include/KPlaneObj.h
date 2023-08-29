#pragma once
#include "KObject.h"
class KPlaneObj : public KObject
{
public:
    virtual bool Load(
        ID3D11Device* pDevice,
        ID3D11DeviceContext* pContext,
        Vector3 p,
        Vector3 s,
        W_STR texFile, W_STR shaderFile);
	virtual bool CreateVertexBuffer() override;
	virtual bool	CreateIndexBuffer() override;
	virtual bool Frame();
};

