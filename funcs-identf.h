#pragma once
#include "include.h"

typedef uintptr_t(*tCamera__get_main)();
tCamera__get_main oCamera__get_main = nullptr;

typedef uintptr_t(*tGameObject__get_transform)(uintptr_t);
tGameObject__get_transform oGameObject__get_transform = nullptr;

typedef Vector3(*tTransform__get_position)(uintptr_t);
tTransform__get_position oTransform__get_position = nullptr;

typedef Vector3(*tWorldToScreenPoint)(uintptr_t, Vector3);
tWorldToScreenPoint oWorldToScreenPoint = nullptr;

typedef uintptr_t(*tFindObjectOfType)(void*);
tFindObjectOfType oFindObjectOfType = nullptr;

typedef uintptr_t(*tFindGameObjectWithTag)(void*);
tFindGameObjectWithTag oFindGameObjectWithTag = nullptr;

typedef bool(*tSurvival_IsEndingPlaying)(uintptr_t);
tSurvival_IsEndingPlaying oSurvival_IsEndingPlaying = nullptr;
tSurvival_IsEndingPlaying oSurvival_IsJumpScarePlaying = nullptr;
tSurvival_IsEndingPlaying oSurvival_StartingToPlayFailEnding = nullptr;