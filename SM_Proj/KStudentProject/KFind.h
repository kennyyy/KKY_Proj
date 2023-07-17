#include "KLinkedList.h"
#include <string.h>

template <class T>
class KFind
{
public:
	KLinkedList<T>* KFindList;

	//검색
	NodeBox<T>* find(int id); //id(유일한 값)를 기준으로 노드를 찾아서 반환, 노드는 외부에서 설정한 값을 초기값으로 넣어서 함수를 호출하면 id을 인자로 받는 클래스 구축
	NodeBox<T>* find(const char* name); //이름을 기준으로 노드를 찾아서 반환, 중복이 있을경우 다음 노드에 있는 이름 반환 , 노드는 외부에서 설정한 값을 초기값으로 넣어서 함수를 호출하면 id을 인자로 받는 클래스 구축


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
