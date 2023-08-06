#pragma once
#include "Node.h"


class Octree {
public:
    Node* mRootNode = nullptr;
    int miNodeCounter = 0;
    std::queue<Node*> mQueue; //순회용 큐
    std::set<Node*> mDynamicObjectNodeList; //동적오브젝트가 들어있는 노드만 저장 
    std::vector<Node*> mQctNodeList; //전체노드 리스트

    //공간분할
    void BuildOctree(float x, float y, float z,  float w, float h, float d);
    void BuildTree(Node* pParent);
    Node* CreateNode(Node* pParent, float x, float y, float z, float fWIdth, float fHeight, float fDepth);

    //오브젝트 생성
    Node* FindNode(Node* pNode, Object* obj);
    Node* StaticAddObject(Object* obj);
    Node* DyamicAddObject(Object* obj);

    // 순회
    void PreOrder(Node* pNode);
    void LevelOrder(Node* pNode);

    //프로세스
    bool Init();
    bool PreFrame();
    bool Frame();
    bool PostFrame();
    void Render(Node* pNode);
    bool Release();

    Octree() {}
    virtual ~Octree() {
        delete mRootNode;
    }
};

