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

	//��ũ�帮��Ʈ �������
	NodeBox<T>* NewNode(); // ��� �ϳ��� ����
	void PushHead(NodeBox<T>* newNode); //���� ���� : head�� Next�� ������� ���� head->next
	void PushTail(NodeBox<T>* newNode); //���� ���� : tail�� Prev�� ������� ���� tail->Prev
	void DeleteNode(int nodeNum);  //���� : head�������� ���° ��带 ��������
	void DeleteAllNode(); //��ü ����(��� �ʱ�ȭ) : head->Next���� tail->Prev���� ��ü ��� ����

	KLinkedList() {
		head.nb_Next = &tail;
		head.nb_Prev = nullptr;
		tail.nb_Next = nullptr;
		tail.nb_Prev = &head;
	}

};

template<class T>
int  KLinkedList<T>::iCounter = 0; // ��ü ��� ����

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

	//��� ��ü ���̷� ���� üũ
	if (nodeNum >= 1 && iCounter >= nodeNum) {
		for (int i = 1; i < nodeNum; i++) {//���° ������ ���� ��ȸ
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
		printf("��� ���� ���� : ��� ���� ���� �˻��ϼ̽��ϴ�.\n");
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

	printf("��ü��� �����Ϸ�\n");
	iCounter = 0;
}


