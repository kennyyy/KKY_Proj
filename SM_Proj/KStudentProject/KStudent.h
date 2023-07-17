#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class KStudent {
public:
    int     m_ID;//식별을 위한 유일한 고유 값 설정
    char    m_Name[20];
    int     m_Kor;
    int     m_Eng;
    int     m_Mat;
    int     m_Total;
    float     m_Average;
    KStudent* m_pNext;
    KStudent* m_pPrev;
    static int    m_iCounter;

public:
    void    Print();
    void    ValueSetting();//값 세팅
    void    ValueReset();//값 초기화
    void    TotalAvgCompute();
    void    Save(FILE* fp);
    void    Read(FILE* fp);

};

int KStudent::m_iCounter = 0;

void KStudent::Print() {
    printf("%6d %11s %10d %10d %10d %10d %11.2f \n",m_ID, m_Name, m_Kor, m_Eng, m_Mat, m_Total, m_Average);
    
}

void KStudent::ValueSetting() {
    printf("(비밀번호와 같은)식별할 숫자를 입력해주세요\n");
    scanf("%d", &m_ID);

    printf("이름도 입력해주세요.(점수는 자동 생성) : \n");
    scanf("%s", m_Name);
    srand((unsigned int)time(NULL));

    strcpy(m_Name, m_Name);
    m_Kor = rand() % 101;
    m_Eng = rand() % 101;
    m_Mat = rand() % 101;
    TotalAvgCompute();
}
void KStudent::ValueReset() {
    m_Kor = 0;
    m_Eng = 0;
    m_Mat = 0;
    m_Total = 0;
    m_Average = 0;
}

void  KStudent::TotalAvgCompute() {
    m_Total = m_Kor + m_Eng + m_Mat;
    m_Average = (float)m_Total / 3;

}

void KStudent::Save(FILE* fp)
{
    fprintf(fp, "%d %s %d %d %d\n", m_ID, m_Name, m_Kor, m_Eng, m_Mat);
}

void KStudent::Read(FILE* fp)
{
    fscanf(fp, "%d %s %d %d %d\n", &m_ID, this->m_Name, &m_Kor, &m_Eng, &m_Mat);
}




