#pragma once
#include "Overlay.hpp"

bool Glow = false;

bool showmenu = true;
bool rendering = true;
int frame = 0;
FOverlay* g_overlay;

float ScreenCenterX = 1080.0f;
float ScreenCenterY = 1980.0f;

uintptr_t localPlayer;
uintptr_t entList;
uintptr_t viewRenderer;
uintptr_t viewMatrix;

namespace offsets
{
	DWORD CurrentLevel = 0x40;
	DWORD	Actors = 0xA8;
	DWORD	GameInstance = 0x190;
	DWORD	AcknowledgedPawn = 0x2F8;
	DWORD	PlayerController = 0x40;
	DWORD	ArrayLocalPlayer = 0x48;
	DWORD GetBonePos = 0x36D66C0;
	DWORD UWORLD   = 0x64A91E0;
}