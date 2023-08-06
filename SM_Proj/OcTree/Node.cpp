#include "Node.h"

void Node::SetParent(Node* pParent) {
    if (pParent == nullptr)
        return;
    mpParent = pParent;
    mDepth = pParent->mDepth + 1;
}