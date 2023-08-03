#pragma once
#include "Node.h"


class Octree {
public:
    Node* mRootNode = nullptr;
    int miNodeCounter = 0;
    std::set<Node*> mDynamicObjectNodeList;
    std::vector<Node*> mNodeArrayList;

    //공간분할
    void BuildOctree(float x, float y, float z,  float w, float h, float d);
    void BuildTree(Node* pParent);
    Node* CreateNode(Node* pParent, float x, float y, float z, float fWIdth, float fHeight, float fDepth);

    //오브젝트 생성
    Node* FindNode(Node* pNode, Object* obj);
    Node* StaticAddObject(Object* obj);
    Node* DyamicAddObject(Object* obj);
    
    virtual ~Octree() {}
};

void Octree::BuildOctree(float x, float y, float z, float w, float h, float d) {
    mRootNode = CreateNode(nullptr, x, y, z, w, h, d);
    BuildTree(mRootNode);
}

Node* Octree::CreateNode(Node* pParent, float x, float y, float z, float fWIdth, float fHeight, float fDepth) {
    Node* pNode = new Node(miNodeCounter++);
    pNode->SetParent(pParent);
    pNode->mbx.Set(x, y, z, fWIdth, fHeight, fDepth);
    return pNode;
}


void Octree::BuildTree(Node* pNode) {
    if (pNode->mDepth >1)  return;

    Vector3 vHalf = pNode->mbx.mHalf;
    vHalf = vHalf * 0.5f;

    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x , pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
                                                   pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z );
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    //
    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x, pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    for (int i = 0; i < pNode->mChild.size(); i++) {
        BuildTree(pNode->mChild[i]);
    }
}



Node* Octree::FindNode(Node* pNode, Object* obj) {
    if (pNode == nullptr)
        return;
    do {
        for (int i = 0; pNode->mChild.size(); i++) {
            if (pNode->mChild[i] != nullptr) {
                if(Collision::RectToRect(pNode->mChild[i]->mRt, obj->mbx)){}
            }
        }

    } while (pNode);
    return pNode;

}

Node* Octree::StaticAddObject(Object* obj) {
    Node* pFindNode =  FindNode(mRootNode, obj);
    if (pFindNode != nullptr) {
        pFindNode->mStaticObjectList.push_back(obj);
        return pFindNode;
    }
    return nullptr;
}

Node* Octree::DyamicAddObject(Object* obj) {
    Node* pFindNode = FindNode(mRootNode, obj);

    if (pFindNode != nullptr) {
        pFindNode->mDynamicObjectList.push_back(obj);
        mDynamicObjectNodeList.insert(pFindNode);
    }

    return nullptr;
}
