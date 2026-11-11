#include "pch.h"

DWORD WINAPI LaunchWindowsStartup(LPVOID lpThread)
{
    Sleep(5000);

    AllocConsole();

    FILE* File = nullptr;

    freopen_s(&File, "CONOUT$", "w+", stdout);
    freopen_s(&File, "CONIN$", "r", stdin);
    freopen_s(&File, "CONOUT$", "w+", stderr);

    SetConsoleTitleA("TGS: 4.5: Setting Up: Made By Tezzy!");

    if (MH_Initialize() != MH_OK) { ExitThread(0); }

    Sleep(2500);

    SetConsoleTitleA("TGS: 4.5: Patching: Made By Tezzy!");
    *reinterpret_cast<bool*>(InSDKUtils::GetImageBase() + 0x4DAD489) = false; // GIsClient
    *reinterpret_cast<bool*>(InSDKUtils::GetImageBase() + 0x4DAD48A) = true; // GIsServer

    Sleep(1000);

    SetConsoleTitleA("TGS: 4.5: Loading World: Made By Tezzy!");
    GWorldContext->OwningGameInstance->LocalPlayers.Remove(0);
    UGameplayStatics::OpenLevel(GWorldContext, UKismetStringLibrary::Conv_StringToName(L"Athena_Terrain"), false, FString());

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ReasonForCall, LPVOID lpReserved)
{
    if (ReasonForCall == DLL_PROCESS_ATTACH)
        CreateThread(nullptr, 0, LaunchWindowsStartup, lpReserved, 0, nullptr);

    return TRUE;
}