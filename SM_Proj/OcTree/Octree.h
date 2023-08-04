#pragma once
#include "Node.h"


class Octree {
public:
    Node* mRootNode = nullptr;
    int miNodeCounter = 0;
    std::queue<Node*> mQueue;
    std::set<Node*> mDynamicObjectNodeList;
    std::vector<Node*> mQctNodeList;

    //��������
    void BuildOctree(float x, float y, float z,  float w, float h, float d);
    void BuildTree(Node* pParent);
    Node* CreateNode(Node* pParent, float x, float y, float z, float fWIdth, float fHeight, float fDepth);

    //������Ʈ ����
    Node* FindNode(Node* pNode, Object* obj);
    Node* StaticAddObject(Object* obj);
    Node* DyamicAddObject(Object* obj);

    // ��ȸ
    void PreOrder(Node* pNode);
    void LevelOrder(Node* pNode);

    //���μ���
    bool Init();
    bool PreFrame();
    bool Frame();
    bool PostFrame();
    bool Render(Node* pNode);
    bool Release();

    Octree() {}
    virtual ~Octree() {
        delete mRootNode;
    }
};

