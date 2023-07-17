#pragma once
#include "TObject.h"
class TNode
{
public:
    int    m_iIndex; //�ε���
    TRect  m_rt; // ������
    int    m_iDepth = 0; //����
    TNode* m_pParent = nullptr; //�θ� ����
    std::vector<TNode*> m_pChild; //�ڽ� ���= 4��
    std::vector<TObject*> m_StaticObjectList; //���ȿ� ����obj ����
    std::vector<TObject*> m_DynamicObjectList; //���ȿ� ����obj ����
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

