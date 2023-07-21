#pragma once
#include "Object.h"

class Node {
public:
    int mIndex = 0;
    int mDepth = 0;
    std::vector< Node*> mChild;
    std::vector<Object*> mDynamicObjectList;
    std::vector<Object*> mStaticObjectList;
    Node* mpParent = nullptr;
    Rect                   mRt;
    void SetParent(Node* pParent) {
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






