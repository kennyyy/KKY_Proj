#pragma once
#include "Object.h"

class Node {
public:
    int mIndex = 0;
    int mDepth = 0;
    Node* mpParentNode = nullptr;
    Box mbx;
    std::vector< Node*> mChild; 
    std::vector<Object*> mDynamicObjectList;//노드영역 안에 있는 동적오브젝트 리스트
    std::vector<Object*> mStaticObjectList;//노드영역 안에 있는 정적오브젝트 리스트

    void SetParent(Node* pParent);
  
    Node(int id) : mIndex(id) {}
    virtual ~Node() {
        for (int i = 0; i < mChild.size(); i++) {
            delete mChild[i];
        }
    }
};







