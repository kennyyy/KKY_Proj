#pragma once
#include "TObject.h"
class TNode
{
public:
    int    m_iIndex; //인덱스
    TRect  m_rt; // 노드범위
    int    m_iDepth = 0; //레벨
    TNode* m_pParent = nullptr; //부모 여부
    std::vector<TNode*> m_pChild; //자식 노드= 4개
    std::vector<TObject*> m_StaticObjectList; //노드안에 정적obj 여부
    std::vector<TObject*> m_DynamicObjectList; //노드안에 동적obj 여부
public:    
    void   SetParent(TNode* pParent);
    TNode(TNode* pParent, 
        float x,
        float y, 
        float fWidth,
        float fHeight) : m_pParent(pParent)
    {
        m_rt.Set(x, y, fWidth, fHeight);
        SetParent(pParent);
    }
    ~TNode()
    {
        if (m_pChild.size() != 0)
        {
            delete m_pChild[0];
            delete m_pChild[1];
            delete m_pChild[2];
            delete m_pChild[3];
        }
    }
};

