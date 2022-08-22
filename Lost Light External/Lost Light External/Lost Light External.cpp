#include <iostream>
#include "driver.hpp"
#include "function.hpp"
#include "include.hpp"
#include <thread>
#include "overlay.hpp"
#include "Menu.h"
#include "glob.hpp"
#include "vec.h"

HWND hGameWnd;
HWND hOverlayWnd;
RECT wndRect;

namespace controller
{
	bool setup()
	{
		function.setup();

		if (!driver.is_mapped()) NULL; 

		while (driver.get_pid()) {
			driver.set_pid(_("r5apex.exe").c_str(), _("Apex Legends").c_str());
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		return driver.is_mapped() && driver.get_pid();
	}
}

static void render(FOverlay* overlay) {
	while (rendering) {
		overlay->begin_scene();
		overlay->clear_scene();
		frame++;
		ESPLoop();
		RenderMenu();
		overlay->end_scene();
	}
}

static void _init(FOverlay* overlay) {
	if (!overlay->window_init()) {
		printf("Fail Created Windows & hijacking -- 0x992\n");
		Sleep(5000);
		return;
	}
	else {
		printf("Sucessfully Created Windows & hijacking -- 0x881\n");
	}

	if (!overlay->init_d2d())
		return;

	std::thread r(render, overlay);
	r.join();

	overlay->d2d_shutdown();

	return;
}

int main(int op)
{
	
	controller::setup;
	system("color 3");
	SetConsoleTitleA("Apex  External");
	MessageBoxA(NULL, "Cheat Is Loading", "Apex Chaet", MB_OK);
	Sleep(3000);
    std::cout << "Hello Welcome to The Apex Glow Cheat\n";

	std::cout << "________________________________________\n";
	std::cout << "Game Info:\n";
	std::cout << "Game PID = " << std::hex << driver.get_pid() << "\n";
	std::cout << "Game Base Address = " << std::hex << driver.get_module_base(_("r5apex.exe").c_str()) << "\n";
	std::cout << "________________________________________\n\n";
	std::cout << "Press Enter To Load Cheat\n";
	std::cin.get();
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	HDC monitor = GetDC(hDesktop);
	int current = GetDeviceCaps(monitor, VERTRES);
	int total = GetDeviceCaps(monitor, DESKTOPVERTRES);
	ScreenCenterX = GetSystemMetrics(SM_CXSCREEN) / 2;
	ScreenCenterY = GetSystemMetrics(SM_CYSCREEN) / 2;
	g_overlay = { 0 };
	_init(g_overlay);
	std::cin.get();

	
}
