#include "Octree.h"
#include "Timer.h"
std::vector<Object*> StaticObjectList;
std::vector<Object*> DynamicObjectList;

void SetStaticObject(Octree& tree) {
	if (tree.mRootNode == nullptr) return;
	int  iMaxWidth = (int)tree.mRootNode->mbx.mfWidth;
	int  iMaxHeight = (int)tree.mRootNode->mbx.mfHeight;
	int  iMaxDepth = (int)tree.mRootNode->mbx.mfDepth;
	for (int i = 0; i < 5; i++) {
		Object* obj = new StaticObject();
		obj->mName = L"StaticObject";
		obj->mName += std::to_wstring(i);
		obj->mPosition = { (float)randstep(-iMaxWidth / 2.0f, iMaxWidth / 2.0f), (float)randstep(-iMaxHeight / 2.0f, iMaxHeight / 2.0f) ,
			(float)randstep(-iMaxDepth / 2.0f, iMaxDepth / 2.0f) };

		obj->SetBox(obj->mPosition, (float)((rand() % 10) + 1.0f), (float)((rand() % 10) + 1.0f), (float)((rand() % 10) + 1.0f));
		Vector3  TargetPos = { (float)randstep(-iMaxWidth / 2.0f, iMaxWidth / 2.0f), (float)randstep(-iMaxHeight / 2.0f, iMaxHeight / 2.0f) , 
			(float)randstep(-iMaxDepth / 2.0f, iMaxDepth / 2.0f) };
		obj->SetTarget(TargetPos);
		tree.StaticAddObject(obj);
		StaticObjectList.push_back(obj);
	}
}
void SetDynamicObject(Octree& tree) {
	if (tree.mRootNode == nullptr) return;
	int  iMaxWidth = (int)tree.mRootNode->mbx.mfWidth;
	int  iMaxHeight = (int)tree.mRootNode->mbx.mfHeight;
	int  iMaxDepth = (int)tree.mRootNode->mbx.mfDepth;
	for (int i = 0; i < 5; i++) {
		Object* obj = new DynamicObject();
		obj->mName = L"DynamicObject";
		obj->mName += std::to_wstring(i);
		obj->mPosition = { (float)randstep(-iMaxWidth / 2.0f, iMaxWidth / 2.0f), (float)randstep(-iMaxHeight / 2.0f, iMaxHeight / 2.0f) ,
			(float)randstep(-iMaxDepth / 2.0f, iMaxDepth / 2.0f) };

		obj->SetBox(obj->mPosition, (float)((rand() % 10) + 1.0f), (float)((rand() % 10) + 1.0f), (float)((rand() % 10) + 1.0f));
		Vector3  TargetPos = { (float)randstep(-iMaxWidth / 2.0f, iMaxWidth / 2.0f), (float)randstep(-iMaxHeight / 2.0f, iMaxHeight / 2.0f) ,
			(float)randstep(-iMaxDepth / 2.0f, iMaxDepth / 2.0f) };
		obj->SetTarget(TargetPos);
		tree.DyamicAddObject(obj);
		DynamicObjectList.push_back(obj);
	}
}



int main()
{
	Octree octree;
	Timer timer;
	timer.Init();//초기화
	octree.Init();//원점 기준으로 octree세팅

	SetStaticObject(octree);
	SetDynamicObject(octree);

	while (1) {
		timer.Frame();//시간계산
		octree.PreFrame();
		for (int i = 0; i < DynamicObjectList.size(); i++) {
			Object* obj = DynamicObjectList[i];
			obj->Move(timer.mfSecondPerFrame);
			octree.DyamicAddObject(obj);
		}

		octree.Frame();//x
		octree.Render(octree.mRootNode);//LevelOrder 방식 순회 출력
		timer.Render();//시간출력
		Sleep(1);
		
	}
	timer.Release();//x

	for (int i = 0; i < StaticObjectList.size(); i++)
	{
		delete StaticObjectList[i];
	}
	StaticObjectList.clear();
	for (int i = 0; i < DynamicObjectList.size(); i++)
	{
		delete DynamicObjectList[i];
	}
	DynamicObjectList.clear();

	octree.Release();//x
	return 0;
}

