#include "KLinkedList.h"

template <class T>
class KUpdate
{
public:
	KLinkedList<T>* KUpdateList;

	//����
	void UpdateNode(int id);  //id(������ ��)�� �������� ��带 ã�Ƽ� �����͸� �������ش�

	KUpdate() {
		KUpdateList = nullptr;
	}
};


template <class T>
void KUpdate<T> ::UpdateNode(int id) {
	NodeBox<T>* FindNode = KUpdateList->head.nb_Next;
	
	//��� ��ü ���̷� ���� üũ
	if (id >= 1 && KUpdateList->iCounter >= id) {
		for (int i = 1; i < id; i++) {//���° ������ ���� ��ȸ
			if (FindNode->nb_Next == nullptr) { // tail(��)����
				break;
			}
			else {
				FindNode = FindNode->nb_Next;
			}
		}
		int updateChoice;

		printf("������ ���� �Ͻðڽ��ϱ�? 1.ID��  2.�̸�  3.����(������ ��������) 4.��ü ����\n ");//�ٲٰ� compute�ؼ� ���� ��� ���
		scanf("%d", &updateChoice);

		if (updateChoice == 1) {
			int tempId;
			printf("(��й�ȣ�� ����)�ĺ��� ���ڸ� �Է����ּ���. ���� �� : ( %d )\n", FindNode->nb_Data->m_ID);
			scanf("%d", &tempId);
			FindNode->nb_Data->m_ID = tempId;

		}
		else if (updateChoice == 2) {
			printf("�̸��� �Է����ּ���. ���� �� : ( %s ) \n", FindNode->nb_Data->m_Name);
			scanf("%s", FindNode->nb_Data->m_Name);
			strcpy(FindNode->nb_Data->m_Name, FindNode->nb_Data->m_Name);
		}
		else if (updateChoice == 3) {
			srand((unsigned int)time(NULL));
			FindNode->nb_Data->m_Kor = rand() % 101;
			FindNode->nb_Data->m_Eng = rand() % 101;
			FindNode->nb_Data->m_Mat = rand() % 101;
			FindNode->nb_Data->TotalAvgCompute();
		}
		else if (updateChoice == 4) {
			FindNode->nb_Data->ValueSetting();
		}
		else {
			//error
		}
	
	}
	else {
		printf("��� ���� ���� �˻��ϼ̰ų� ��尡 �����ϴ�.\n");
	}
}


