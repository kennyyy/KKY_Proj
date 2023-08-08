#include "Node.h"

void Node::SetParent(Node* pParent) {
    if (pParent == nullptr)
        return;
    mpParentNode = pParent;
    mDepth = pParent->mDepth + 1;
}