#include "KSample.h"


bool  KSample::Init()
{
    std::wstring textname[] = { L"kgcabk.bmp" };
   /* for (int i = 0; i < 100; i++) {
        KObject* pObj = new KObject;
        pObj->Set(m_pDevice, m_pImmediateContext);
        pObj->Init(textname[0]);
        m_ObjList.push_back(pObj);
    }*/
 
        KObject* pObj = new KObject;
        pObj->Set(m_pDevice, m_pImmediateContext);
        pObj->Init(textname[0]);
        m_ObjList.push_back(pObj);
        KObject* pObj1 = new KObject;
        pObj1->Set(m_pDevice, m_pImmediateContext);
        pObj1->Init(textname[0]);
        m_ObjList.push_back(pObj1);

    return true;
}
bool  KSample::Frame()
{
    for (auto obj : m_ObjList) {
        obj->Frame();
    }
    return true;
}
bool  KSample::Render()
{
    for (auto obj : m_ObjList) {
        obj->Render();
    }
    return true;
}
bool  KSample::Release()
{
    for (auto obj : m_ObjList) {
        obj->Release();
        delete obj;
    }
    m_ObjList.clear();
    return true;
}

KGAME(L"kgca", 800, 600)