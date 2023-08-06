#include "Octree.h"

//프로세스
bool Octree::Init() {
	//원점 기준으로 octree 생성
	BuildOctree(0, 0, 0, gfMapSize, gfMapSize, gfMapSize);
	return true;
}
bool Octree::PreFrame() {
	for (Node *node : mDynamicObjectNodeList) {
		node->mDynamicObjectList.clear();
	}
	mDynamicObjectNodeList.clear();
	return true;
}
bool Octree::Frame() {
	return true;
}
bool Octree::PostFrame() {
	return true;
}
void Octree::Render(Node* pNode) {
	if (pNode == nullptr)
		return;
	std::wcout << L"\n"<<L" Node[" 
		<< pNode->mIndex << L"] : { "
		<< pNode->mbx.v.x << L", "
		<< pNode->mbx.v.y << L", "
		<< pNode->mbx.v.z << L", "
		<< pNode->mbx.mfWidth << L", "
		<< pNode->mbx.mfHeight << L", "
		<< pNode->mbx.mfDepth << L" },   [StaticObjSize] : "
		<< pNode->mStaticObjectList.size() << L", [DynamicObjSize] : "
		<< pNode->mDynamicObjectList.size() << std::endl;
	for (int i = 0; i < pNode->mStaticObjectList.size(); i++)
	{						
		std::wcout << L"-----------------  ["
			<< pNode->mStaticObjectList[i]->mName << L"] : {"
			<< pNode->mStaticObjectList[i]->mPosition.x << L",  "
			<< pNode->mStaticObjectList[i]->mPosition.y << L",  "
			<< pNode->mStaticObjectList[i]->mPosition.z
			<<"}  -----------------"<< std::endl;
	}
	for (int i = 0; i < pNode->mDynamicObjectList.size(); i++)
	{
		std::wcout << L"-----------------  [" 
			<< pNode->mDynamicObjectList[i]->mName << L"] : {"
			<< pNode->mDynamicObjectList[i]->mPosition.x << L",  "
			<< pNode->mDynamicObjectList[i]->mPosition.y << L",  "
			<< pNode->mDynamicObjectList[i]->mPosition.z
			<< "}  -----------------"<< std::endl;
	}

	for (int i = 0; i < pNode->mChild.size(); i++) {
		if (pNode->mChild[i] != nullptr) {
			mQueue.push(pNode->mChild[i]);
		}
	}
	if (!mQueue.empty()) {
		Node* pNode = mQueue.front();
		mQueue.pop();
		Render(pNode);
	}
}
bool Octree::Release() {
	return true;
}

//Node순회
void Octree::PreOrder(Node* pNode) {
	if (pNode == nullptr)
		return;
	for (Node* data : pNode->mChild) {
		PreOrder(data);
	}
}
void Octree::LevelOrder(Node* pNode) {
	if (pNode == nullptr)
		return;

	for (int i = 0; i < pNode->mChild.size(); i++) {
		if (pNode->mChild[i] != nullptr) {
			mQueue.push(pNode);
		}
	}
	if (mQueue.empty()) {
		pNode = mQueue.front();
		mQueue.pop();
		PreOrder(pNode);
	}
}