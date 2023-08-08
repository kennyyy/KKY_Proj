#pragma once
#include "Object.h"

class Node {
public:
    int mIndex = 0;
    int mDepth = 0;
    Node* mpParentNode = nullptr;
    Box mbx;
    std::vector< Node*> mChild; 
    std::vector<Object*> mDynamicObjectList;//��念�� �ȿ� �ִ� ����������Ʈ ����Ʈ
    std::vector<Object*> mStaticObjectList;//��念�� �ȿ� �ִ� ����������Ʈ ����Ʈ

    void SetParent(Node* pParent);
  
    Node(int id) : mIndex(id) {}
    virtual ~Node() {
        for (int i = 0; i < mChild.size(); i++) {
            delete mChild[i];
        }
    }
};







