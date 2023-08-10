#include "KCore.h"


bool KCore::Init() { 
	return true;
}
bool KCore::Frame() {
	return true;
}
bool KCore::Render() {
	return true;
}
bool KCore::Realease() {
	return true;
}


bool KCore::EngineInit() {
	Init();
	return true;
}
bool KCore::EngineFrame() {
	Frame();
	return true;
}
bool KCore::EngineRender() {
	Render();
	return true;
}
bool KCore::EngineRealease() {
	Realease();
	return true;

}

bool KCore::Run() {
	EngineInit();
	MSG msg = { 0 };

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

			if (!EngineFrame() || !EngineRender()){
				break;
			}

		}
	}
	EngineRealease();
	return true;
}
