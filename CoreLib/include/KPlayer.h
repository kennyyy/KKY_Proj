#pragma once
#include "KPlaneObj.h"
class KPlayer : public KPlaneObj
{
public:
    bool  Init();
    bool  Frame();
    bool  Render();
    bool  Release();
};

