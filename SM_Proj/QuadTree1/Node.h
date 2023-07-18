#pragma once
#include "Utils.h"
class Node
{
public:
	int mIndex;
	int mDepth = 0;
	Node* mpParent = nullptr;
	std::vector<Node*> mpChild;
public: 
	void SetParent(Node* pParent);
	Node(Node* pParent) : mpParent(pParent){

	}
	~Node() {
		if (mpChild.size() != 0) {
			delete mpChild[0];
			delete mpChild[1];
			delete mpChild[2];
			delete mpChild[3];
		}
	}
};

void Node::SetParent(Node* pParent) {
	if (pParent == nullptr)
		return;
	mpParent = pParent;
	mDepth = pParent->mDepth + 1;
}

