#include "KLinkedList.h"
//미완성
template <class T>
class KSort
{
	//원본 유지, 훼손x, 제2의 버퍼에 저장,  정렬 검색 파일 입 출력  따로 구현 고려
	public:
	KLinkedList<T> KSortList;
	//정렬
	void AscendSortNode();//버블정렬을 이용하여 총점기준 오른차순 만들기
	void DescendSortNode();//버블정렬을 이용하여 총점기준 내림차순 만들기
};

template <class T>
void KSort<T>::DescendSortNode() {

	if (KSortList.head.nb_Next->nb_Next == nullptr) {
		printf("정렬할 노드가 없습니다.\n");
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
		printf("정렬할 노드가 없습니다.\n");
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
