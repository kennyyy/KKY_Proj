#include "KLinkedList.h"

template <class T>
class KPrint
{
public:
	KLinkedList<T>*  KPrintList;

	//출력(순회)
	void PrintFront(); //head의 Next 노드부터 시작하여  전체 노드 출력
	void PrintBack(); //tail의 Prev 노드부터 시작하여  전체 노드 출력

	void PrintFront(NodeBox<T>* startNode); //head노드의 Next 노드부터 매개변수에 지정된 노드까지 출력
	void PrintBack(NodeBox<T>* startNode); //tail의 Prev 노드부터 매개변수에 지정된 노드까지 출력

	KPrint() {
		KPrintList = nullptr;
	}
};
template <class T>
void KPrint<T>::PrintFront(){
	printf("-----------------------------------------------------------------------------\n");
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(유일값)","이름","국어","영어","수학","총점","평균");
	printf("-----------------------------------------------------------------------------\n");
	for (NodeBox<T>* node = KPrintList->head.nb_Next; node->nb_Next != nullptr; node = node->nb_Next){
		node->nb_Data->Print();
	}
	printf("-----------------------------------------------------------------------------\n");
}

template <class T>
void KPrint<T>::PrintBack(){
	printf("-----------------------------------------------------------------------------\n");
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(유일값)", "이름", "국어", "영어", "수학", "총점", "평균");
	printf("-----------------------------------------------------------------------------\n");
	for (NodeBox<T>* node = KPrintList->tail.nb_Prev; node->nb_Prev != nullptr; node = node->nb_Prev){
		node->nb_Data->Print();
	}
	printf("-----------------------------------------------------------------------------\n");
}

//



template <class T>
void KPrint<T>::PrintFront(NodeBox<T>* StartNode) {
	printf("-----------------------------------------------------------------------------\n");
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(유일값)", "이름", "국어", "영어", "수학", "총점", "평균");
	printf("-----------------------------------------------------------------------------\n");
	for (NodeBox<T>* node = KPrintList->head.nb_Next; node != StartNode; node = node->nb_Next) {
		node->nb_Data->Print();
	}
	printf("-----------------------------------------------------------------------------\n");
}

template <class T>
void KPrint<T>::PrintBack(NodeBox<T>* StartNode) {
	printf("-----------------------------------------------------------------------------\n");
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(유일값)", "이름", "국어", "영어", "수학", "총점", "평균");
	printf("-----------------------------------------------------------------------------\n");
	for (NodeBox<T>* node = KPrintList->tail.nb_Prev; node != StartNode; node = node->nb_Prev) {
		node->nb_Data->Print();
	}
	printf("-----------------------------------------------------------------------------\n");
}

