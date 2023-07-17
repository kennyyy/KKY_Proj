#include "TTimer.h"
bool	TTimer::Init()
{
	m_fFramePerSecond = 0.0f;
	m_fGameTimer = 0.0f;
	m_fSecondPerFrame = 0.0f;
	m_dwBeforeTime = timeGetTime();// tick coounter 1000 => 1초
	return true;


}
bool	TTimer::Frame()
{
	DWORD dwCurrentTime = timeGetTime();
	DWORD dwElapseTime = dwCurrentTime - m_dwBeforeTime; //경과시간
	m_fSecondPerFrame = dwElapseTime / 1000.0f; // timeGetTime();함수에서 ms를 기준으로해서 1000을 나눠야함->   1프레임당 소요되는 시간 
	m_fGameTimer += m_fSecondPerFrame;
	m_dwBeforeTime = dwCurrentTime;// 현재시간은 이제 이전시간으로 


	m_fFramePerSecond += m_fSecondPerFrame;// 1초당 몇번의 틱(프레임)이 도는가
	return true;
}


int   TTimer::GetFPS()//1초가 넘으면 몇번의 프레임이 돌았는지 축척했다가 리턴
{
	static int iFPS = 0;
	if (m_fFramePerSecond >= 1.0f)
	{
		m_iFPS = iFPS;
		iFPS = 0;
		m_fFramePerSecond -= 1.0f;
	}
	iFPS++;
	return m_iFPS;
}
bool	TTimer::Render()
{
	std::cout << "[FPS]" << GetFPS() << " [GT]" << m_fGameTimer << " [SPF]" << m_fSecondPerFrame << std::endl;
	return true;
}
bool	TTimer::Release()
{
	return true;
}