#pragma once
#include "Node.h"

class QuadTree  {
public:
    Node* mRootNode = nullptr;
    int miNodeCounter = 0;
    std::set<Node*> mDynamicObjectNodeList;
    std::vector<Node*> mNodeArrayList;

    void BuildQuadTree(float x, float y, float w, float h);
    void BuildTree(Node* pParent);
    Node* CreateNode(Node* pParent, float x, float y, float fWIdth, float fHeight);
        
    ~QuadTree() {
      
    }
};

Node* QuadTree::CreateNode(Node* pParent, float x, float y, float fWIdth, float fHeight) {

}

void QuadTree::BuildQuadTree(float x, float y, float w, float h) {
    mRootNode = CreateNode(nullptr, x, y, w, h);
    BuildTree(mRootNode);
}
