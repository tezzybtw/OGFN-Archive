#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>
#include <iostream>

#include "Engine/Source/ThirdParty/MinHook/Include/MinHook.h"
#include "Engine/Source/ThirdParty/SDK/SDK.hpp"

using namespace SDK;

#define GEngineContext UEngine::GetEngine()
#define GWorldContext UWorld::GetWorld()
#define ANY_PACKAGE (UObject*)-1

#endif