#pragma once
#include "Node.h"

class QuadTree  {
public:
    Node* mRootNode = nullptr;
    int miNodeCounter = 0;
    Rect mRt;
    std::set<Node*> mDynamicObjectNodeList;
    std::vector<Node*> mNodeArrayList;

    void BuildQuadTree(float x, float y, float w, float h);
    void BuildTree(Node* pParent);
    Node* CreateNode(Node* pNode, float x, float y, float fWIdth, float fHeight);

    Node* FindNode(Node* pNode, Object* obj);
    Node* StaticAddObject(Object* obj);
    Node* DyamicAddObject(Object* obj);
    
        
    ~QuadTree() {
      
    }
};

Node* QuadTree::CreateNode(Node* pParent, float x, float y, float fWIdth, float fHeight) {
    Node* pNode = new Node(miNodeCounter++);
    pNode->SetParent(pParent);
    pNode->mRt.Set(x, y, fWIdth, fHeight);
    return pNode;
}


void QuadTree::BuildQuadTree(float x, float y, float w, float h) {
    mRootNode = CreateNode(nullptr, x, y, w, h);
    BuildTree(mRootNode);
}

void QuadTree::BuildTree(Node* pNode) {
    if (pNode->mDepth >1) { return; }

    Point vTopCenter = { pNode->mRt.mCenterPoint.x, pNode->mRt.mMin.y};
    Point vBottomCenter = { pNode->mRt.mCenterPoint.x, pNode->mRt.mMax.y};
    Point vLeftCenter = { pNode->mRt.mMin.x, pNode->mRt.mCenterPoint.y };
    Point vRightCenter = {pNode->mRt.mMax.x, pNode->mRt.mCenterPoint.y };

    Node* pNewNode = CreateNode(pNode, mRt.mMin.x, mRt.mMin.y, pNode->mRt.mCenterPoint.x, pNode->mRt.mCenterPoint.y);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    pNewNode = CreateNode(pNode, vTopCenter.x, vTopCenter.y, pNode->mRt.mHalf.x, pNode->mRt.mHalf.y);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    pNewNode = CreateNode(pNode, mRt.mCenterPoint.x, mRt.mCenterPoint.y, pNode->mRt.mHalf.x, pNode->mRt.mHalf.y);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    pNewNode = CreateNode(pNode, vLeftCenter.x, vLeftCenter.y, pNode->mRt.mHalf.x, pNode->mRt.mHalf.y);
    pNode->mChild.push_back(pNewNode);
    mNodeArrayList.push_back(pNode);

    for (int i = 0; i < pNode->mChild.size(); i++) {
        BuildTree(pNode->mChild[i]);
    }
}
Node* QuadTree::FindNode(Node* pNode, Object* obj) {
    if (pNode == nullptr)
        return;
    do {
        for (int i = 0; pNode->mChild.size(); i++) {
            if (pNode->mChild[i] != nullptr) {
                if(Collision::RectToRect(pNode->mChild[i]->mRt, obj->mtRT)){}
            }
        }

    } while (pNode);
    return pNode;

}

Node* QuadTree::StaticAddObject(Object* obj) {
    Node* pFindNode =  FindNode(mRootNode, obj);
    if (pFindNode != nullptr) {
        pFindNode->mDynamicObjectList.push_back(obj);
        mDynamicObjectNodeList.insert(pFindNode);
        return pFindNode;
    }
    return nullptr;
}
