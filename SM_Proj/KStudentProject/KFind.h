#include "KLinkedList.h"
#include <string.h>

template <class T>
class KFind
{
public:
	KLinkedList<T>* KFindList;

	//�˻�
	NodeBox<T>* find(int id); //id(������ ��)�� �������� ��带 ã�Ƽ� ��ȯ, ���� �ܺο��� ������ ���� �ʱⰪ���� �־ �Լ��� ȣ���ϸ� id�� ���ڷ� �޴� Ŭ���� ����
	NodeBox<T>* find(const char* name); //�̸��� �������� ��带 ã�Ƽ� ��ȯ, �ߺ��� ������� ���� ��忡 �ִ� �̸� ��ȯ , ���� �ܺο��� ������ ���� �ʱⰪ���� �־ �Լ��� ȣ���ϸ� id�� ���ڷ� �޴� Ŭ���� ����


	KFind() {
		KFindList = nullptr;
	}
};


template <class T>
NodeBox<T>* KFind<T>::find(int id) {
	
	NodeBox<T>* FindNode = nullptr;
	if (KFindList->head.nb_Next->nb_Next == nullptr) {
		return FindNode;
	}
	for (NodeBox<T>* node = KFindList->head.nb_Next; node != nullptr; node = node->nb_Next) {
		if (node->nb_Next == nullptr) {
			return FindNode;
		}
		if (node->nb_Data->m_ID == id) {
			FindNode = node;
			break;
		}
	}
}


template <class T>
NodeBox<T>* KFind<T>::find(const char* name) {

	NodeBox<T>* FindNode = nullptr;
	if (KFindList->head.nb_Next->nb_Next == nullptr) {
		return FindNode;
	}
	for (NodeBox<T>* node = KFindList->head.nb_Next; node != nullptr; node = node->nb_Next) {
		if (node->nb_Next == nullptr) {
			return FindNode;
		}
		if (!strcmp(node->nb_Data->m_Name, name)) {
			FindNode = node;
			break;
		}
	}
	return FindNode;
}
