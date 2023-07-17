#define _CRT_SECURE_NO_WARNINGS
#include "KLinkedList.h"// 링크드리스트 노드생성,삽입,삭제
#include "KStudent.h" //학생 데이터
#include "KFileIO.h" //저장, 로드
#include "KPrint.h" //순회(출력)
#include "KInsert.h" //삽입
#include "KUpdate.h" //수정
#include "KFind.h" //검색
#include "KSort.h" //정렬

//클래스
//학생, 링크드리스트, 프로젝트 매니저,
//순회(앞, 뒤), 검색, 파일 저장 로드, 
//수정(원본 저장할지 안할지 설정)
//정렬 : 원본 유지, 훼손x, 제2의 버퍼에 저장

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
	KStudent* NewStudentData(); // 학생 데이터 생성
	void SaveFile(const char* filename, KLinkedList<KStudent> KlinkedList);
	void LoadFile(const char* filename);

	~KStudentManager() {
		KlinkedList.DeleteAllNode();
	}

};

KStudent* KStudentManager::NewStudentData() {
	KStudent* NodeData = new KStudent();
	NodeData->ValueSetting(); //점수는 랜덤으로 받자
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
		printf(" ----------------------------학생 관리 프로그램을 실행합니다--------------------------\n");
		printf("|  0. 종료 | 1. 학생 생성 | 2. 학생 출력 | 3. 학생 삽입 | 4. 학생 삭제 | 5. 학생 수정 |\n ");
		printf("-------------------------------------------------------------------------------------\n");
		printf("| 6. 전체 초기화 | 7. 학생 찾기 | 8. 학생 총점 정렬 | 9. 학생 저장 | 10. 학생 불러오기|\n ");
		printf("-------------------------------------------------------------------------------------\n");
		printf("번호를 입력해 주세요 : ");
		if (scanf("%d", &choose) != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);

		}
	
		if (choose == Exit) //종료
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
				printf("ID 값 중복으로 학생을 생성할 수 없습니다.\n");
				delete node;
			}
			else {
				printf("0. 앞으로 연결,  1. 뒤로 연결\n");
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
			printf("0. 앞부터 출력,  1. 뒤부터 출력\n");
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

			printf("몇번째에 학생을 추가하시겠습니까?\n");
			scanf("%d", &pushChoice);
			

			if (pushChoice >= 1 && nodeNum >= pushChoice) {//노드 전체 길이로 범위 체크
				KStudent* NodeData = NewStudentData();
				NodeBox<KStudent>* node = KlinkedList.NewNode();
				node->nb_Data = NodeData;

				Kfind.KFindList = &KlinkedList;
				NodeBox<KStudent>* dupNode = Kfind.find(NodeData->m_ID);
				if (dupNode != nullptr) {
					printf("ID 값 중복으로 학생을 생성할 수 없습니다.\n");
					delete NodeData;
					break;
				}

				Kinsert.KInsertList = &KlinkedList;
				Kinsert.PushInsert(node, pushChoice);
			}
			else {
				printf("노드 삽입 실패 : 노드 범위 밖을 입력하셨습니다.\n");
			}
		
		}break;

		case DeleteNode: {
			int pushChoice;

			printf("몇번째에 있는 학생을 삭제하시겠습니까?\n");
			scanf("%d", &pushChoice);
			KlinkedList.DeleteNode(pushChoice);
		}break;

		case UpdateNode: {
			int pushChoice;

			printf("몇번째에 있는 학생을 수정하시겠습니까?\n");
			scanf("%d", &pushChoice);
			Kupdate.KUpdateList = &KlinkedList;
			Kupdate.UpdateNode(pushChoice);

		}break;
		case DeleteNodeAll: {

			printf("학생전체가 삭제됩니다.\n");
			KlinkedList.DeleteAllNode();

		}break;
		case FindNode: {
			int pushChoice, findID;
			char tempName[20] = { 0, };

			printf("1. id(유일값)으로 검색하기  2. 이름으로 검색하기\n");
			scanf("%d", &pushChoice);

			if (pushChoice == 1) {
				printf("검색할 id(유일값)을 입력하여 주세요.\n");
				scanf("%d", &findID);
				Kfind.KFindList = &KlinkedList;
				NodeBox<KStudent>* node = Kfind.find(findID);

				if (node != nullptr) {
					printf("-----------------------------------------------------------------------------\n");
					printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(유일값)", "이름", "국어", "영어", "수학", "총점", "평균");
					printf("-----------------------------------------------------------------------------\n");
					node->nb_Data->Print();
				}
				else {
					printf("해당 학생을 찾을 수 없습니다.\n");
				}
					
			}
			else if (pushChoice == 2) {
				printf("검색할 학생 이름을 입력하여주세요.\n");
				scanf("%s", tempName);
				//const char* name=strcpy(tempName, tempName);
				Kfind.KFindList = &KlinkedList;
				NodeBox<KStudent>* node = Kfind.find(tempName);

				if (node != nullptr) {
					printf("-----------------------------------------------------------------------------\n");
					printf("%6s | %6s   | %6s   | %6s   | %6s   | %6s   | %6s\n", "ID(유일값)", "이름", "국어", "영어", "수학", "총점", "평균");
					printf("-----------------------------------------------------------------------------\n");
					node->nb_Data->Print();
				}
				else {
					printf("해당 학생을 찾을 수 없습니다.\n");
				}
					
			}

			


		}break;
		case SortNode: {
			int pushChoice, sortChoice;

			printf("1. 총점을 오름차순으로 정렬하기  2. 총점을 내림차순으로 정렬하기\n");
			scanf("%d", &pushChoice);
			if (pushChoice == 1) {
				Ksort.KSortList = KlinkedList;
				Ksort.AscendSortNode();
				Kprint.KPrintList = &Ksort.KSortList;
				Kprint.PrintFront();

				if (KlinkedList.head.nb_Next->nb_Next != nullptr) {
					printf("1. 다른 파일에 저장하시겠습니까? (원본 데이터는 유지됩니다.)\n");
					printf("   나가고 싶으시면 아무 숫자를 입력해주세요.\n");
					scanf("%d", &sortChoice);
					if (sortChoice == 1) {
						char filename[20] = { 0, };
						printf("저장할 파일의 파일명을 입력하세요 :\n");
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
					printf("1. 다른 파일에 저장하시겠습니까? (원본 데이터는 유지됩니다.)\n");
					printf("   나가고 싶으시면 아무 숫자를 입력해주세요.\n");
					scanf("%d", &sortChoice);
					if (sortChoice == 1) {
						char filename[20] = { 0, };
						printf("저장할 파일의 파일명을 입력하세요 :\n");
						scanf("%s", filename);
						SaveFile(filename, Ksort.KSortList);
					}
				}
			}	
		}break;

		case SaveNode: {
			char filename[20] = { 0, };
			printf("저장할 파일의 파일명을 입력하세요 :\n");
			scanf("%s", filename);
			SaveFile(filename, KlinkedList);

		}break;

		case LoadNode: {
			char filename[20] = { 0, };
			printf("불러올 파일 이름을 입력하세요 : \n");
			scanf("%s", filename);
			LoadFile(filename);

		}break;

		default:
			break;
		}
	}
}
