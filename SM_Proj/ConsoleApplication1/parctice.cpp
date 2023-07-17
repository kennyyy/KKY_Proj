/*
*  연습장
*/
#include <iostream>

struct TNode
{
	int value = -1;
	TNode* LeftChild = nullptr;
	TNode* RightChild = nullptr;
	TNode(int i) : value(i) {

	}
};
TNode* g_pRootNode = nullptr;

int   g_iData[] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
int   g_iIndex = 0;

//재귀함수의 탈출조건? = 자식왼쪽,오른쪽에 조건식이 부합하지 않으면 됨
void AddNode(TNode* ParentNode, TNode* pNewNode) {//부모노드와, 새노드 전달
	if (ParentNode->value >= pNewNode->value) { //새노드가 부모보다 작으면

		if (ParentNode->LeftChild == nullptr) {// 부모 왼쪽이 값이 없으면

			ParentNode->LeftChild = pNewNode;// 부모의 왼쪽이 새노드 위치임
		}
		else { // 부모 왼쪽에 값이 있다? 
			AddNode(ParentNode->LeftChild, pNewNode);  //재귀함수 호출( 자식 왼쪽으로가서 계속 비교)
			
		}
	}
	else {
		if (ParentNode->RightChild == nullptr) {
			ParentNode->RightChild = pNewNode;
		}
		else {
			AddNode(ParentNode->RightChild, pNewNode);
		}

	}
}

TNode* Find(TNode* PresentNode, int iFind)
{
	if (PresentNode->value == iFind)
	{
		return PresentNode;
	}
	else
	{
		if (PresentNode->value > iFind)
		{
			if (PresentNode->LeftChild != nullptr)
			{
				Find(PresentNode->LeftChild, iFind);
			}
			else
			{
				return nullptr;
			}
		}
		else
		{
			if (PresentNode->RightChild != nullptr)
			{
				Find(PresentNode->RightChild, iFind);
			}
			else
			{
				return nullptr;
			}
		}
	}
}


int main()
{
	g_pRootNode = new TNode(g_iData[g_iIndex++]);
	int ICnt = _countof(g_iData);

	for (int i = 1; i < ICnt; i++) {
		TNode* newNode = new TNode(g_iData[i]);
		AddNode(g_pRootNode, newNode);
	}

}

