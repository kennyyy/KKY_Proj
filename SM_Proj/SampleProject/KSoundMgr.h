#include "fmod.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#include "Kstd.h"
#pragma comment (lib, "fmod_vc.lib")
#pragma once

class KSound
{
public:
	std::wstring m_csName;
	std::wstring m_csPath;
public:
	FMOD::System* m_pSystem; //  사운드파일단위
	FMOD::Sound* m_pSound;
	FMOD::Channel* m_pChannel;
public:
	bool Load(std::wstring sFilepath);
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
public:
	void Set(FMOD::System* pSystem);
	void SetName(std::wstring name);
	void VolumeSet(float volume);
	void Play(bool bLoop = true);
	void PlayEffect();
	void Stop();
	void Paused();
	void VolumeUp();
	void VolumeDown();
};
class KSoundMgr {
	FMOD::System* m_pSystem;
	std::map < std::wstring, std::unique_ptr<KSound>> m_list;
public:
	static KSoundMgr& GetInstance() {
		static KSoundMgr soundMgr;
		return soundMgr;
	}
public:
	bool Frame();
	bool Release();
	KSound* LoadSound(std::wstring szFilepath);
	KSound* GetPtr(std::wstring key);
	bool Get(std::wstring key, KSound& ret);
private:
	KSoundMgr();
public:
	virtual ~KSoundMgr();
};

#define I_Sound KSoundMgr::GetInstance()




