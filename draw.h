#pragma once
#include "include.h"

void DrawBox(float x, float y, float w, float h, ImColor color, float thickness)
{
	auto drawlist = ImGui::GetBackgroundDrawList();

	drawlist->AddLine(ImVec2{ x, y }, ImVec2{ x + w, y }, color, thickness);
	drawlist->AddLine(ImVec2{ x, y }, ImVec2{ x, y + h }, color, thickness);
	drawlist->AddLine(ImVec2{ x + w, y }, ImVec2{ x + w, y + h }, color, thickness);
	drawlist->AddLine(ImVec2{ x, y + h }, ImVec2{ x + w, y + h }, color, thickness);
}