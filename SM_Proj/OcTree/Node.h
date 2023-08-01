#pragma once
#include "Object.h"

class Node {
public:
    int mIndex = 0;
    int mDepth = 0;
    Node* mpParent = nullptr;
    Rect mRt;
    std::vector< Node*> mChild;
    std::vector<Object*> mDynamicObjectList;
    std::vector<Object*> mStaticObjectList;

    void SetParent(Node* pParent) {
        if (pParent == nullptr)
            return;
        mpParent = pParent;
        mDepth = pParent->mDepth + 1;
    }

    Node(int id) : mIndex(id) {}

    virtual ~Node() {
        for (int i = 0; i < mChild.size(); i++) {
            delete mChild[i];
        }
    }
};







