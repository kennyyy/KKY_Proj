#include "KLinkedList.h"

template <class T>
class KInsert
{
	public:
	KLinkedList<T>* KInsertList;

	void PushInsert(NodeBox<T>* newNode, int nodeNum); //���� : head�������� ���° ��带 ����(����)����
};


template <class T>
void KInsert<T>::PushInsert(NodeBox<T>* newNode, int nodeNum) {//head�������� ���° ����� Next�� ������带 ����(����) 
	NodeBox<T>* findNode = KInsertList->head.nb_Next;
	
	
		for (int i = 1; i < nodeNum; i++)//���° ������ ���� ��ȸ
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
