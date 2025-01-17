#pragma once
#include "DxLib.h"
#include "../Math/Vector2.h"

class DebugBlockMove
{
public:
	DebugBlockMove();
	~DebugBlockMove();

	void Update();

	Vector2 GetMove_Val() { return move_val; }

private:

	void Input();

	Vector2 move_val = Vector2::ZERO;
};