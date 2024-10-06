#pragma once
#include "include.h"

static uintptr_t optionsHelpers{}, cachedSurvival{};

bool IsInGame()
{
	if (!optionsHelpers)
		if (!(optionsHelpers = FindObjectOfType("OptionsHelpers")))
			return false;

	return *(bool*)(optionsHelpers + 0x85); // private bool <inGame>k__BackingField; // 0x85
}

bool IsSequencePlaying()
{
	if (!cachedSurvival)
		if (!(cachedSurvival = FindObjectOfType("Survival")))
			return false;

	if (cachedSurvival)
	{
		if (oSurvival_IsEndingPlaying(cachedSurvival)) return true;
		if (oSurvival_IsJumpScarePlaying(cachedSurvival)) return true;
		if (oSurvival_StartingToPlayFailEnding(cachedSurvival)) return true;
	}

	return false;
}

uintptr_t azazel{}, transform{}, camera{}, last_tick{};

void RunAzazelESP()
{
	__try
	{
		DWORD64 current_tick = GetTickCount64();

		if (current_tick - last_tick > 500)
		{
			azazel = FindGameObjectWithTag("Azazel");
			if (!azazel) return;

			transform = oGameObject__get_transform(azazel);
			if (!transform) return;

			camera = oCamera__get_main();
			if (!camera) return;

			last_tick = current_tick;
		}

		if (!transform || !camera || !azazel)
			return;

		auto pos = oTransform__get_position(transform);

		Vector3 footpos = oWorldToScreenPoint(camera, { pos.x, pos.y - 0.25f, pos.z });
		Vector3 headpos = oWorldToScreenPoint(camera, { pos.x, pos.y + 2.0f, pos.z });

		if (footpos.z > 0.0f)
		{
			float height = headpos.y - footpos.y;
			float width = height * 0.5f;

			float boxX = footpos.x - (width / 2);
			float boxY = static_cast<float>(1080) - footpos.y - height;

			DrawBox(boxX, boxY, width, height, ImVec4(255.f, 0.f, 0.f, 255.f), 2.0f);
		}
	}
	__except (1) {}
}

void MainLogix()
{
	static bool reinit = false;
	if (IsInGame() && !IsSequencePlaying())
	{
		RunAzazelESP();

		if (reinit) reinit = false;
	}
	else
	{
		if (!reinit)
		{
			azazel = 0;
			transform = 0;
			camera = 0;
			optionsHelpers = 0;
			cachedSurvival = 0;

			reinit = true;
		}
	}
}