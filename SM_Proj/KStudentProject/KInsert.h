#include "KLinkedList.h"

template <class T>
class KInsert
{
	public:
	KLinkedList<T>* KInsertList;

	void PushInsert(NodeBox<T>* newNode, int nodeNum); //삽입 : head기준으로 몇번째 노드를 삽입(연결)할지
};


template <class T>
void KInsert<T>::PushInsert(NodeBox<T>* newNode, int nodeNum) {//head기준으로 몇번째 노드의 Next에 양방향노드를 삽입(연결) 
	NodeBox<T>* findNode = KInsertList->head.nb_Next;
	
	
		for (int i = 1; i < nodeNum; i++)//몇번째 노드까지 갈지 순회
		{
			if (findNode->nb_Next == nullptr) { 
				break;
			}
			else {
				findNode = findNode->nb_Next;
			}
		}
		NodeBox<T>* findPrevNode = findNode->nb_Prev;

		findPrevNode->nb_Next = newNode;
		newNode->nb_Prev = findPrevNode;

		newNode->nb_Next = findNode;
		findNode->nb_Prev = newNode;

	KInsertList->iCounter++;

}
