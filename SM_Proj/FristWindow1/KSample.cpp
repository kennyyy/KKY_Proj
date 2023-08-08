#include "KSample.h"

bool KSample::Init() {
	return true;
}
bool KSample::Frame() {
	return true;
}
bool KSample::Render() {
	return true;
}
bool KSample::Release() {
	return true;
}

KGAME(L"kgca", 800, 600);