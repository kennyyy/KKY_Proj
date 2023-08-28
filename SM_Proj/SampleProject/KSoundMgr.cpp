#include "KSoundMgr.h"

bool KSound::Load(std::wstring sFilepath) {
	std::string soundFile = wtm(sFilepath);
	m_pSystem->createSound(soundFile.c_str(), FMOD_DEFAULT, 0, &m_pSound);
	
	return true;
}

void KSound::Play(bool bLoop) {
	if (m_pChannel == nullptr) {
		if (bLoop) {
			m_pSound->setMode(FMOD_LOOP_NORMAL);
		}
		else {
			m_pSound->setMode(FMOD_LOOP_OFF);
		}
		m_pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);
	}
	else {
		bool play;
		m_pChannel->isPlaying(&play);
		if (play == false) {
			if (bLoop) {
				m_pSound->setMode(FMOD_LOOP_NORMAL);
			}
			else {
				m_pSound->setMode(FMOD_LOOP_OFF);
			}
			m_pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);
		}
	}
}

void KSound::PlayEffect() {
	m_pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);
}
void KSound::Stop() {
	m_pChannel->stop();
}
void KSound::Paused() {
	bool paused;
	m_pChannel->getPaused(&paused);
	m_pChannel->setPaused(!paused);
}
void KSound::VolumeUp() {
	float fVolume;
	m_pChannel->getVolume(&fVolume);
	fVolume += 0.2f;
	fVolume = min(1.0f, fVolume);
	m_pChannel->setVolume(fVolume);
}
void KSound::VolumeDown() {
	float fVolume;
	m_pChannel->getVolume(&fVolume);
	fVolume -= 0.2f;
	fVolume = max(0.0f, fVolume);
	m_pChannel->setVolume(fVolume);
}

void   KSound::Set(FMOD::System* pSystem) { 
	m_pSystem = pSystem;
}
void KSound::VolumeSet(float volume) {
	m_pChannel->setVolume(volume);
}
void  KSound::SetName(std::wstring name) {
	m_csName = name;
};

bool KSound::Init() {
	return true;
}
bool KSound::Frame() {
	return true;
}
bool KSound::Render() {
	return true;
}
bool KSound::Release() {
	if (m_pSound)m_pSound->release();
	return true;
}


KSound* KSoundMgr::LoadSound(std::wstring szFilepath) {
	std::size_t found = szFilepath.find_last_of(L"/");
	std::wstring path = szFilepath.substr(0, found + 1);
	std::wstring name = szFilepath.substr(found + 1);
	KSound* data = GetPtr(name);
	if (data != nullptr) {
		return data;
	}
	std::unique_ptr<KSound> newData = std::make_unique<KSound>();
	newData->SetName(name);
	newData->Set(m_pSystem);
	if (newData->Load(szFilepath)) {
		m_list.insert(std::make_pair(name, std::move(newData)));
		return GetPtr(name);
	}
	return nullptr;
}
KSound* KSoundMgr::GetPtr(std::wstring key) {
	if (m_list.find(key) != m_list.end()) {
		return m_list.find(key)->second.get();
	}
	return nullptr;
}
bool KSoundMgr::Get(std::wstring key, KSound& ret) {
	if (m_list.find(key) != m_list.end()) {
		ret = *(m_list.find(key)->second);
		return true;
	}
	return false;
}
bool KSoundMgr::Frame() {
	m_pSystem->update();
	for (auto& data : m_list) {
		data.second->Frame();
	}
	return true;
}
bool KSoundMgr::Release() {
	for (auto& data : m_list) {
		data.second->Release();
	}
	m_list.clear();
	m_pSystem->close();
	m_pSystem->release();
	return true;
}

KSoundMgr::KSoundMgr() {
	FMOD::System_Create(&m_pSystem);
	m_pSystem->init(32, FMOD_INIT_NORMAL, 0);//maxchannel = 동시에 들리는 사운드 수
}

KSoundMgr::~KSoundMgr() {
	Release();
}

