#pragma once
#include "TNode.h"
class TQuadtree
{    
  public:

    std::queue<TNode*> g_Queue;   //순회를 위한 큐
    TNode* g_pRootNode = nullptr; //부모노드
    int     m_iNumNodeCounter = 0; //노드 수 확인
    std::set<TNode*> g_DynamicObjectNodeList; //노드에 있는 동적obj 삭제를 위한 노드 set리스트 ==중복허용X, 자동 오름차순 정렬
    std::vector<TNode*> g_DynamicNodeList; //동적obj가 있는 노드리스트


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
    bool	Init();		// 초기화 작업
    bool	PreFrame();	// 실시간 계산
    bool	Frame();	// 실시간 계산
    bool	PostFrame();	// 실시간 계산
    bool	Render();	// 실시간 랜더링, 드로우
    bool	Release();	// 객체의 소멸 작업
public:
    ~TQuadtree()
    {
        delete g_pRootNode;
    }
};

