#pragma once
#include "TNode.h"
class TQuadtree
{    
  public:

    std::queue<TNode*> g_Queue;   //��ȸ�� ���� ť
    TNode* g_pRootNode = nullptr; //�θ���
    int     m_iNumNodeCounter = 0; //��� �� Ȯ��
    std::set<TNode*> g_DynamicObjectNodeList; //��忡 �ִ� ����obj ������ ���� ��� set����Ʈ ==�ߺ����X, �ڵ� �������� ����
    std::vector<TNode*> g_DynamicNodeList; //����obj�� �ִ� ��帮��Ʈ


public:
    TNode* GetRootNode();
public:
    void Buildtree(TNode* pNode);
    void BuildQuadtree();
    TNode* CreateNode(TNode* pParent, float x,
        float y,
        float fWidth,
        float fHeight);

    TNode* StaticAddObject(TObject* obj);
    TNode* DynamicAddObject(TObject* obj);
    TNode* FindNode(TNode* pNode, TObject* obj);
public:
    void PreOrder(TNode* pNode);
    void PostOrder(TNode* pNode);
    void LevelOrder(TNode* pNode);
public:
    bool	Init();		// �ʱ�ȭ �۾�
    bool	PreFrame();	// �ǽð� ���
    bool	Frame();	// �ǽð� ���
    bool	PostFrame();	// �ǽð� ���
    bool	Render();	// �ǽð� ������, ��ο�
    bool	Release();	// ��ü�� �Ҹ� �۾�
public:
    ~TQuadtree()
    {
        delete g_pRootNode;
    }
};

