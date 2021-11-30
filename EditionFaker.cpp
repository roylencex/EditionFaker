#include <Windows.h>
#include "MinHook.h"
#include "Memory.h"

INT AppPlatform_getGameEdition_hook()
{
	return 1; // 1 = Android
}

VOID WINAPI Inject()
{
	if (MH_Initialize() == MH_OK)
	{
		LPVOID AppPlatform_getGameEdition = reinterpret_cast<LPVOID>(FindSignature("8B 91 ?? ?? ?? ?? 85 D2 74 1C 83 EA 01"));
		if (MH_CreateHook(AppPlatform_getGameEdition, &AppPlatform_getGameEdition_hook, 0) == MH_OK)
		{
			MH_EnableHook(AppPlatform_getGameEdition);
		}
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Inject), hinstDLL, 0, 0);
	}
	return TRUE;
}
