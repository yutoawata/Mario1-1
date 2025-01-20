#pragma once
#include "DxLib.h"
#include "../Math/Vector2.h"
class MoveValueManager
{
public:

	static Vector2 GetMoveValue() { return moveValue; }
	static void SetMoveValue(Vector2 set_value) { moveValue = set_value; }

private:

	static Vector2 moveValue;
};
