#include "KLinkedList.h"

template <class T>
class KUpdate
{
public:
	KLinkedList<T>* KUpdateList;

	//수정
	void UpdateNode(int id);  //id(유일한 값)를 기준으로 노드를 찾아서 데이터를 수정해준다

	KUpdate() {
		KUpdateList = nullptr;
	}
};


template <class T>
void KUpdate<T> ::UpdateNode(int id) {
	NodeBox<T>* FindNode = KUpdateList->head.nb_Next;
	
	//노드 전체 길이로 범위 체크
	if (id >= 1 && KUpdateList->iCounter >= id) {
		for (int i = 1; i < id; i++) {//몇번째 노드까지 갈지 순회
			if (FindNode->nb_Next == nullptr) { // tail(끝)까지
				break;
			}
			else {
				FindNode = FindNode->nb_Next;
			}
		}
		int updateChoice;

		printf("무엇을 변경 하시겠습니까? 1.ID값  2.이름  3.성적(성적은 랜덤으로) 4.전체 변경\n ");//바꾸고 compute해서 총점 평균 계산
		scanf("%d", &updateChoice);

		if (updateChoice == 1) {
			int tempId;
			printf("(비밀번호와 같은)식별할 숫자를 입력해주세요. 현재 값 : ( %d )\n", FindNode->nb_Data->m_ID);
			scanf("%d", &tempId);
			FindNode->nb_Data->m_ID = tempId;

		}
		else if (updateChoice == 2) {
			printf("이름을 입력해주세요. 현재 값 : ( %s ) \n", FindNode->nb_Data->m_Name);
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
		printf("노드 범위 밖을 검색하셨거나 노드가 없습니다.\n");
	}
}


