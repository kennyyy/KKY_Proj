#define _CRT_SECURE_NO_WARNINGS
#include "KLinkedList.h"// ��ũ�帮��Ʈ ������,����,����
#include "KStudent.h" //�л� ������
#include "KFileIO.h" //����, �ε�
#include "KPrint.h" //��ȸ(���)
#include "KInsert.h" //����
#include "KUpdate.h" //����
#include "KFind.h" //�˻�
#include "KSort.h" //����

//Ŭ����
//�л�, ��ũ�帮��Ʈ, ������Ʈ �Ŵ���,
//��ȸ(��, ��), �˻�, ���� ���� �ε�, 
//����(���� �������� ������ ����)
//���� : ���� ����, �Ѽ�x, ��2�� ���ۿ� ����

enum menu { Exit, CreateNode, PrintNode, InsertNode, DeleteNode, UpdateNode, DeleteNodeAll, FindNode, SortNode, SaveNode, LoadNode };

class KStudentManager {

public:
	KLinkedList<KStudent>  KlinkedList;
	KPrint<KStudent> Kprint;
	KInsert<KStudent> Kinsert;
	KUpdate<KStudent> Kupdate;
	KFind<KStudent> Kfind;
	KSort<KStudent> Ksort;

	void Run();
	KStudent* NewStudentData(); // �л� ������ ����
	void SaveFile(const char* filename, KLinkedList<KStudent> KlinkedList);
	void LoadFile(const char* filename);

	~KStudentManager() {
		KlinkedList.DeleteAllNode();
	}

};

KStudent* KStudentManager::NewStudentData() {
	KStudent* NodeData = new KStudent();
	NodeData->ValueSetting(); //������ �������� ����
	NodeData->TotalAvgCompute();
	return NodeData;
}

void KStudentManager::SaveFile(const char* filename, KLinkedList<KStudent> KlinkedList)
{
	KFileIO fileIO;
	FILE* fpWrite = fileIO.CreateFile(filename,"w");
	if (fpWrite != NULL)
	{
		for (NodeBox<KStudent>* pNode = KlinkedList.head.nb_Next;
			pNode->nb_Next != NULL;
			pNode = pNode->nb_Next)
		{
			pNode->nb_Data->Save(fpWrite);
		}
		fileIO.CloseFile();
	}
}

void KStudentManager::LoadFile(const char* filename)
{
	KlinkedList.DeleteAllNode();

	KFileIO fileIO;
	FILE* fpRead = fileIO.CreateFile(filename, "r");
	if (fpRead != NULL)
	{
		while (1)
		{
			if (feof(fpRead))
			{
				break;
			}
			NodeBox<KStudent>* pNewNode = KlinkedList.NewNode();
			pNewNode->nb_Data = new KStudent;
			_ASSERT(pNewNode->nb_Data);
			pNewNode->nb_Data->Read(fpRead);
			pNewNode->nb_Data->TotalAvgCompute();
			KlinkedList.PushHead(pNewNode);
		}
		fileIO.CloseFile();
	}
	
}


void KStudentManager::Run() {
	while (1) {
		int choose;

		printf("\n\n\n");
		printf(" ----------------------------�л� ���� ���α׷��� �����մϴ�--------------------------\n");
		printf("|  0. ���� | 1. �л� ���� | 2. �л� ��� | 3. �л� ���� | 4. �л� ���� | 5. �л� ���� |\n ");
		printf("-------------------------------------------------------------------------------------\n");
		printf("| 6. ��ü �ʱ�ȭ | 7. �л� ã�� | 8. �л� ���� ���� | 9. �л� ���� | 10. �л� �ҷ�����|\n ");
		printf("-------------------------------------------------------------------------------------\n");
		printf("��ȣ�� �Է��� �ּ��� : ");
		if (scanf("%d", &choose) != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);

		}
	
		if (choose == Exit) //����
			break;

		switch (choose) {

		case CreateNode: {
			int pushChoice;
			KStudent* NodeData = NewStudentData();
			NodeBox<KStudent>* node = KlinkedList.NewNode();
			node->nb_Data = NodeData;

			
			Kfind.KFindList = &KlinkedList;
			NodeBox<KStudent>* dupNode = Kfind.find(NodeData->m_ID);
			if (dupNode != nullptr) {
				printf("ID �� �ߺ����� �л��� ������ �� �����ϴ�.\n");
				delete node;
			}
			else {
				printf("0. ������ ����,  1. �ڷ� ����\n");
				scanf("%d", &pushChoice);
				if (pushChoice == 0) {
					KlinkedList.PushHead(node);
				}
				else if (pushChoice == 1) {
					KlinkedList.PushTail(node);
				}
				else {
					delete NodeData;
					delete node;
				}
			}

			

		}break;

		case PrintNode: {
			int pushChoice;
			Kprint.KPrintList = &KlinkedList;
			printf("0. �պ��� ���,  1. �ں��� ���\n");
			scanf("%d", &pushChoice);
			if (pushChoice == 0) {
				Kprint.PrintFront();
			}
			else if (pushChoice == 1) {
				Kprint.PrintBack();
			}

		}break;

		case InsertNode: {
			int pushChoice;
			int nodeNum = KlinkedList.iCounter;

			printf("���°�� �л��� �߰��Ͻðڽ��ϱ�?\n");
			scanf("%d", &pushChoice);
			

			if (pushChoice >= 1 && nodeNum >= pushChoice) {//��� ��ü ���̷� ���� üũ
				KStudent* NodeData = NewStudentData();
				NodeBox<KStudent>* node = KlinkedList.NewNode();
				node->nb_Data = NodeData;

				Kfind.KFindList = &KlinkedList;
				NodeBox<KStudent>* dupNode = Kfind.find(NodeData->m_ID);
				if (dupNode != nullptr) {
					printf("ID �� �ߺ����� �л��� ������ �� �����ϴ�.\n");
					delete NodeData;
					break;
				}

				Kinsert.KInsertList = &KlinkedList;
				Kinsert.PushInsert(node, pushChoice);
			}
			else {
				printf("��� ���� ���� : ��� ���� ���� �Է��ϼ̽��ϴ�.\n");
			}
		
		}break;

		case DeleteNode: {
			int pushChoice;

			printf("���°�� �ִ� �л��� �����Ͻðڽ��ϱ�?\n");
			scanf("%d", &pushChoice);
			KlinkedList.DeleteNode(pushChoice);
		}break;

		case UpdateNode: {
			int pushChoice;

			printf("���°�� �ִ� �л��� �����Ͻðڽ��ϱ�?\n");
			scanf("%d", &pushChoice);
			Kupdate.KUpdateList = &KlinkedList;
			Kupdate.UpdateNode(pushChoice);

		}break;
		case DeleteNodeAll: {

			printf("�л���ü�� �����˴ϴ�.\n");
			KlinkedList.DeleteAllNode();

		}break;
		case FindNode: {
			int pushChoice, findID;
			char tempName[20] = { 0, };

			printf("1. id(���ϰ�)���� �˻��ϱ�  2. �̸����� �˻��ϱ�\n");
			scanf("%d", &pushChoice);

			if (pushChoice == 1) {
				printf("�˻��� id(���ϰ�)�� �Է��Ͽ� �ּ���.\n");
				scanf("%d", &findID);
				Kfind.KFindList = &KlinkedList;
				NodeBox<KStudent>* node = Kfind.find(findID);

				if (node != nullptr) {
					printf("-----------------------------------------------------------------------------\n");
					printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(���ϰ�)", "�̸�", "����", "����", "����", "����", "���");
					printf("-----------------------------------------------------------------------------\n");
					node->nb_Data->Print();
				}
				else {
					printf("�ش� �л��� ã�� �� �����ϴ�.\n");
				}
					
			}
			else if (pushChoice == 2) {
				printf("�˻��� �л� �̸��� �Է��Ͽ��ּ���.\n");
				scanf("%s", tempName);
				//const char* name=strcpy(tempName, tempName);
				Kfind.KFindList = &KlinkedList;
				NodeBox<KStudent>* node = Kfind.find(tempName);

				if (node != nullptr) {
					printf("-----------------------------------------------------------------------------\n");
					printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(���ϰ�)", "�̸�", "����", "����", "����", "����", "���");
					printf("-----------------------------------------------------------------------------\n");
					node->nb_Data->Print();
				}
				else {
					printf("�ش� �л��� ã�� �� �����ϴ�.\n");
				}
					
			}

			


		}break;
		case SortNode: {
			int pushChoice, sortChoice;

			printf("1. ������ ������������ �����ϱ�  2. ������ ������������ �����ϱ�\n");
			scanf("%d", &pushChoice);
			if (pushChoice == 1) {
				Ksort.KSortList = KlinkedList;
				Ksort.AscendSortNode();
				Kprint.KPrintList = &Ksort.KSortList;
				Kprint.PrintFront();

				if (KlinkedList.head.nb_Next->nb_Next != nullptr) {
					printf("1. �ٸ� ���Ͽ� �����Ͻðڽ��ϱ�? (���� �����ʹ� �����˴ϴ�.)\n");
					printf("   ������ �����ø� �ƹ� ���ڸ� �Է����ּ���.\n");
					scanf("%d", &sortChoice);
					if (sortChoice == 1) {
						char filename[20] = { 0, };
						printf("������ ������ ���ϸ��� �Է��ϼ��� :\n");
						scanf("%s", filename);
						SaveFile(filename, Ksort.KSortList);
					}
				}
			}
			else if (pushChoice == 2) {
				Ksort.KSortList = KlinkedList;
				Ksort.DescendSortNode();
				Kprint.KPrintList = &Ksort.KSortList;
				Kprint.PrintFront();

				if (KlinkedList.head.nb_Next->nb_Next != nullptr) {
					printf("1. �ٸ� ���Ͽ� �����Ͻðڽ��ϱ�? (���� �����ʹ� �����˴ϴ�.)\n");
					printf("   ������ �����ø� �ƹ� ���ڸ� �Է����ּ���.\n");
					scanf("%d", &sortChoice);
					if (sortChoice == 1) {
						char filename[20] = { 0, };
						printf("������ ������ ���ϸ��� �Է��ϼ��� :\n");
						scanf("%s", filename);
						SaveFile(filename, Ksort.KSortList);
					}
				}
			}	
		}break;

		case SaveNode: {
			char filename[20] = { 0, };
			printf("������ ������ ���ϸ��� �Է��ϼ��� :\n");
			scanf("%s", filename);
			SaveFile(filename, KlinkedList);

		}break;

		case LoadNode: {
			char filename[20] = { 0, };
			printf("�ҷ��� ���� �̸��� �Է��ϼ��� : \n");
			scanf("%s", filename);
			LoadFile(filename);

		}break;

		default:
			break;
		}
	}
}
