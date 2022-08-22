#pragma once
#include <d2d1helper.h>
#include "glob.hpp"


HWND hwnd = NULL;
HWND hwnd_active = NULL;
HWND OverlayWindow = NULL;

void ESPLoop() {

	hwnd = FindWindowA("UnrealWindow", NULL);
	OverlayWindow = FindWindow("CEF-OSC-WIDGET", "NVIDIA GeForce Overlay");
	hwnd_active = GetForegroundWindow();

	if (hwnd_active == hwnd) {

		ShowWindow(OverlayWindow, SW_SHOW);
	}
	else
	{
		ShowWindow(OverlayWindow, SW_HIDE);
	}

	if (!FindWindowA("UnrealWindow", NULL))
	{
		rendering = false;
		showmenu = false;
		Sleep(1000);
		MessageBoxA(NULL, "Bye", "Bye", MB_OK);
		exit(0);

	}
}
	
void RenderMenu()
{
	if (showmenu && rendering)
	{
		g_overlay->draw_text(785, 5, D2D1::ColorF(0, 220, 220, 255), "	Apex Glow EXTERNAL CHEAT");
		g_overlay->draw_text(800, 20, D2D1::ColorF(50, 220, 220, 255), "____________________________________________");
		g_overlay->draw_text(800, 20, D2D1::ColorF(50, 220, 220, 255), "Made By Lëgend#0283| https://github.com/Asmodeus-was-taken");


		if (Glow)
			g_overlay->draw_text(50, 500, D2D1::ColorF(0, 0, 85, 255), "[F1] Glow : ON");
		else
			g_overlay->draw_text(50, 500, D2D1::ColorF(0, 0, 85, 255), "[F1] Glow : OFF");

	}

	if (GetAsyncKeyState(VK_F1) & 0x1)
	{
		Glow = !Glow;
	}
}

