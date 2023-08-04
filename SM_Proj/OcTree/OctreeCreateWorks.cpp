#include "Octree.h"

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
    if (pNode->mDepth > 1)  return;

    Vector3 vHalf = pNode->mbx.mHalf;
    vHalf = vHalf * 0.5f;

    //0~3
    Node* pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x, pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

    pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

    pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

    pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z - vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

    //4~7
    pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x, pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

   pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y + vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

   pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x + vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

    pNewNode = CreateNode(pNode, pNode->mbx.mCenterPoint.x - vHalf.x, pNode->mbx.mCenterPoint.y - vHalf.y, pNode->mbx.mCenterPoint.z + vHalf.z,
        pNode->mbx.mHalf.x, pNode->mbx.mHalf.y, pNode->mbx.mHalf.z);
    pNode->mChild.push_back(pNewNode);
    mQctNodeList.push_back(pNode);

    for (int i = 0; i < pNode->mChild.size(); i++) {
        BuildTree(pNode->mChild[i]);
    }
}


Node* Octree::FindNode(Node* pNode, Object* obj) {
    if (pNode == nullptr)
        return nullptr;
    do {
        for (int i = 0; i < pNode->mChild.size(); i++) {
            if (pNode->mChild[i] != nullptr) {
                if (Collision::BoxToBox(pNode->mChild[i]->mbx, obj->mbx)) {
                    mQueue.push(pNode->mChild[i]);
                    break;
                }
            }
        }
        if (mQueue.empty()) break;
        pNode = mQueue.front();
        mQueue.pop();
    } while (pNode);
    return pNode;
}

Node* Octree::StaticAddObject(Object* obj) {
    Node* pFindNode = FindNode(mRootNode, obj);
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
