#include "KLinkedList.h"

template <class T>
class KPrint
{
public:
	KLinkedList<T>*  KPrintList;

	//���(��ȸ)
	void PrintFront(); //head�� Next ������ �����Ͽ�  ��ü ��� ���
	void PrintBack(); //tail�� Prev ������ �����Ͽ�  ��ü ��� ���

	void PrintFront(NodeBox<T>* startNode); //head����� Next ������ �Ű������� ������ ������ ���
	void PrintBack(NodeBox<T>* startNode); //tail�� Prev ������ �Ű������� ������ ������ ���

	KPrint() {
		KPrintList = nullptr;
	}
};
template <class T>
void KPrint<T>::PrintFront(){
	printf("-----------------------------------------------------------------------------\n");
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(���ϰ�)","�̸�","����","����","����","����","���");
	printf("-----------------------------------------------------------------------------\n");
	for (NodeBox<T>* node = KPrintList->head.nb_Next; node->nb_Next != nullptr; node = node->nb_Next){
		node->nb_Data->Print();
	}
	printf("-----------------------------------------------------------------------------\n");
}

template <class T>
void KPrint<T>::PrintBack(){
	printf("-----------------------------------------------------------------------------\n");
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(���ϰ�)", "�̸�", "����", "����", "����", "����", "���");
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
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(���ϰ�)", "�̸�", "����", "����", "����", "����", "���");
	printf("-----------------------------------------------------------------------------\n");
	for (NodeBox<T>* node = KPrintList->head.nb_Next; node != StartNode; node = node->nb_Next) {
		node->nb_Data->Print();
	}
	printf("-----------------------------------------------------------------------------\n");
}

template <class T>
void KPrint<T>::PrintBack(NodeBox<T>* StartNode) {
	printf("-----------------------------------------------------------------------------\n");
	printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(���ϰ�)", "�̸�", "����", "����", "����", "����", "���");
	printf("-----------------------------------------------------------------------------\n");
	for (NodeBox<T>* node = KPrintList->tail.nb_Prev; node != StartNode; node = node->nb_Prev) {
		node->nb_Data->Print();
	}
	printf("-----------------------------------------------------------------------------\n");
}

