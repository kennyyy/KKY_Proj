#include "KLinkedList.h"
//�̿ϼ�
template <class T>
class KSort
{
	//���� ����, �Ѽ�x, ��2�� ���ۿ� ����,  ���� �˻� ���� �� ���  ���� ���� ���
	public:
	KLinkedList<T> KSortList;
	//����
	void AscendSortNode();//���������� �̿��Ͽ� �������� �������� �����
	void DescendSortNode();//���������� �̿��Ͽ� �������� �������� �����
};

template <class T>
void KSort<T>::DescendSortNode() {

	if (KSortList.head.nb_Next->nb_Next == nullptr) {
		printf("������ ��尡 �����ϴ�.\n");
		return;
	}

	NodeBox<T>* endNode = KSortList.tail.nb_Prev->nb_Next;
	T* tempNode = nullptr;

	for (NodeBox<T>* frontNode = KSortList.head.nb_Next; frontNode->nb_Next != nullptr; frontNode = frontNode->nb_Next) {
		for (NodeBox<T>* backNode = KSortList.head.nb_Next; backNode->nb_Next != endNode; backNode = backNode->nb_Next) {
			if (backNode->nb_Data->m_Total < backNode->nb_Next->nb_Data->m_Total) {
				tempNode = backNode->nb_Data;
				backNode->nb_Data = backNode->nb_Next->nb_Data;
				backNode->nb_Next->nb_Data = tempNode;
			}

		}
		endNode = endNode->nb_Prev;

	}
}


template <class T>
void KSort<T>::AscendSortNode() {
	if (KSortList.head.nb_Next->nb_Next == nullptr) {
		printf("������ ��尡 �����ϴ�.\n");
		return;
	}
	
	NodeBox<T> *endNode = KSortList.tail.nb_Prev->nb_Next;
	T* tempNode = nullptr;

	for (NodeBox<T>* frontNode = KSortList.head.nb_Next; frontNode->nb_Next != nullptr; frontNode = frontNode->nb_Next) {
		for (NodeBox<T>* backNode = KSortList.head.nb_Next; backNode->nb_Next != endNode; backNode = backNode->nb_Next) {
			if (backNode->nb_Data->m_Total > backNode->nb_Next->nb_Data->m_Total) {
				tempNode = backNode->nb_Data;
				backNode->nb_Data = backNode->nb_Next->nb_Data;
				backNode->nb_Next->nb_Data = tempNode;
			}
		
		}
		endNode = endNode->nb_Prev;

		
	}
}
