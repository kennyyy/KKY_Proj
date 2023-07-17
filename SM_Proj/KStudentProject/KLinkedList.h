#pragma once
#include <iostream>

template <class T>
struct NodeBox {
	T* nb_Data;
	NodeBox* nb_Next;
	NodeBox* nb_Prev;
	
	NodeBox() {
		nb_Data = nullptr;
		nb_Next = nullptr;
		nb_Prev = nullptr;
	}
	virtual ~NodeBox() {
		delete nb_Data;
	}
};

template <class T>
class KLinkedList {
public:
	NodeBox<T> head;
	NodeBox<T> tail;

	static int iCounter;

	//링크드리스트 순수기능
	NodeBox<T>* NewNode(); // 노드 하나를 생성
	void PushHead(NodeBox<T>* newNode); //앞쪽 삽입 : head의 Next에 양방향노드 연결 head->next
	void PushTail(NodeBox<T>* newNode); //뒤쪽 삽입 : tail의 Prev에 양방향노드 연결 tail->Prev
	void DeleteNode(int nodeNum);  //삭제 : head기준으로 몇번째 노드를 삭제할지
	void DeleteAllNode(); //전체 삭제(노드 초기화) : head->Next부터 tail->Prev까지 전체 노드 삭제

	KLinkedList() {
		head.nb_Next = &tail;
		head.nb_Prev = nullptr;
		tail.nb_Next = nullptr;
		tail.nb_Prev = &head;
	}

};

template<class T>
int  KLinkedList<T>::iCounter = 0; // 전체 노드 갯수

template <class T>
NodeBox<T>* KLinkedList<T>::NewNode() {
	NodeBox<T>* node = new NodeBox<T>;
	node->nb_Data = 0;
	node->nb_Next = nullptr;
	node->nb_Prev = nullptr;
	return node;
}


template <class T>
void KLinkedList<T>::PushHead(NodeBox<T>* newNode) {
	NodeBox<T>* tempNext = head.nb_Next;

	head.nb_Next = newNode;
	newNode->nb_Prev = &head;

	newNode->nb_Next = tempNext;
	tempNext->nb_Prev = newNode;

	iCounter++;
}


template <class T>
void KLinkedList<T>::PushTail(NodeBox<T>* newNode) {
	NodeBox<T>* tempPrev = tail.nb_Prev;

	tail.nb_Prev = newNode;
	newNode->nb_Next = &tail;

	newNode->nb_Prev = tempPrev;
	tempPrev->nb_Next = newNode;

	iCounter++;
}


template <class T>
void KLinkedList<T> ::DeleteNode(int nodeNum) {
	NodeBox<T>* findNode = head.nb_Next;

	//노드 전체 길이로 범위 체크
	if (nodeNum >= 1 && iCounter >= nodeNum) {
		for (int i = 1; i < nodeNum; i++) {//몇번째 노드까지 갈지 순회
			findNode = findNode->nb_Next;
		}
		NodeBox<T>* nextNode = findNode->nb_Next;
		NodeBox<T>* prevNode = findNode->nb_Prev;

		prevNode->nb_Next = nextNode;
		nextNode->nb_Prev = prevNode;

		delete findNode;
		findNode = nullptr;
	}
	else {
		printf("노드 삭제 실패 : 노드 범위 밖을 검색하셨습니다.\n");
	}
	iCounter--;
}


template <class T>
void KLinkedList<T> ::DeleteAllNode() {
	if (head.nb_Next == &tail) {
		return;
	}
	NodeBox<T>* DelNode = head.nb_Next;
	head.nb_Next = &tail;
	tail.nb_Prev = &head;

	while (DelNode->nb_Next != &tail) {
		DelNode = DelNode->nb_Next;
		delete DelNode->nb_Prev;
	}

	printf("전체노드 삭제완료\n");
	iCounter = 0;
}


