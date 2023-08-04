#include "Octree.h"

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

//프로세스
bool Octree::Init() {
	//원점 기준으로 octree 세팅
	BuildOctree(0, 0, 0, gfMapSize, gfMapSize, gfMapSize);
	return true;
}
bool Octree::PreFrame() {
	for (auto node : mDynamicObjectNodeList) {
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
	std::wcout << L"[" << pNode->mDepth << L"]"
		<< pNode->mbx.v.x << L","
		<< pNode->mbx.v.y << L","
		<< pNode->mbx.v.z << L","
		<< pNode->mbx.mfWidth << L","
		<< pNode->mbx.mfHeight << L","
		<< pNode->mbx.mfDepth << L","
		<< pNode->mStaticObjectList.size() << L","
		<< pNode->mDynamicObjectList.size() << std::endl;
	for (int iobj = 0; iobj < pNode->mDynamicObjectList.size(); iobj++)
	{
		std::wcout << L"      " << L"<" << iobj << L">"
			<< pNode->mDynamicObjectList[iobj]->mName << L","
			<< pNode->mDynamicObjectList[iobj]->mPosition.x << L","
			<< pNode->mDynamicObjectList[iobj]->mPosition.y << L","
			<< pNode->mDynamicObjectList[iobj]->mPosition.z
			<< std::endl;
	}
	for (int i = 0; i < pNode->mChild.size(); i++) {
		if (pNode->mChild[i] != nullptr) {
			mQueue.push(pNode);
		}
	}
	if (mQueue.empty()) {
		Node* pNode = mQueue.front();
		mQueue.pop();
		PreOrder(pNode);
	}
}
bool Octree::Release() {
	return true;
}