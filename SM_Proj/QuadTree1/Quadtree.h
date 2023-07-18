#pragma once
#include "Node.h"
class Quadtree
{
public:
	std::queue<Node*> gQueue;
	Node* RootNode = nullptr;
	int mNodeCounter = 0;

public:
	Node* GetRootNode();
public:
	void Bulidtree(Node* pNode);
	void BuildQuadtree();
	Node* CreateNode(Node* pParent);
	Node* FindNode(Node* pNode);
};

Node* Quadtree::CreateNode(Node* pParent) {
	Node* pNode = new Node(pParent);
	pNode->mIndex = mNodeCounter++;
	return pNode;
}

void Quadtree::BuildQuadtree() {
	Node* RootNode = new Node(nullptr);
	Bulidtree(RootNode);
}


void Quadtree::Bulidtree(Node* pNode) {
	if (pNode->mDepth > 1) {
		return;
	}

	Node* pNewNode = CreateNode(pNode);
	pNode->mpChild.push_back(pNewNode);
	pNewNode = CreateNode(pNode);
	pNode->mpChild.push_back(pNewNode);
	pNewNode = CreateNode(pNode);
	pNode->mpChild.push_back(pNewNode);
	pNewNode = CreateNode(pNode);
	pNode->mpChild.push_back(pNewNode);

	for (int i = 0; i < pNode->mpChild.size(); i++) {
		Bulidtree(pNode->mpChild[i]);
	}
}

Node* Quadtree::FindNode(Node* pNode) {
	if (pNode == nullptr) {
		return nullptr;
	}
	do {
		for (int i = 0; i < pNode->mpChild.size(); i++) {
			if (pNode->mpChild[i] != nullptr) { //자식들과 체크
				break;
			}
		}
		if (gQueue.empty())break;
		pNode = gQueue.front();
		gQueue.pop();
	} while (pNode);//노드가 null이 아니면 계속 돌아감
	return pNode;
}


