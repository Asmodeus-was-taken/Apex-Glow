#pragma once
#include <Windows.h>
#include <iostream>
#include "driver.hpp"
#include <string>

DWORD64 GetEntityById(int Ent, DWORD64 Base)
{

	DWORD64 EntityList = Base + 0x1F6CAB8; 
	DWORD64 BaseEntity = driver.read<DWORD64>(EntityList); 
	if (!BaseEntity) 
		return NULL;

	return driver.read<DWORD64>(EntityList + (Ent << 5)); 
}


void Glow()
{

	float r, g, b;

	DWORD Base = driver.get_module_base(_("r5apex.exe").c_str());

	while (true)
	{
		for (int i = 0; i < 75; i++)
		{
			DWORD64 Entity = GetEntityById(i, Base);

				if (Entity == 0) continue;

				DWORD64 EnityH = driver.read<DWORD64>(Entity + 0x500);

				if (Entity > 1)
				{
					driver.write<bool>(Entity + 0x380, true); 
					driver.write<int>(Entity + 0x2F0, 1); 
					driver.write<float>(Entity + 0x1B0, r); 
					driver.write<float>(Entity + 0x1B4, g); 
					driver.write<float>(Entity + 0x1B8, b); 
				}
				
		}
	}

}
