#include "DebugBlockMove.h"
DebugBlockMove::DebugBlockMove()
{

}

DebugBlockMove::~DebugBlockMove()
{

}

void DebugBlockMove::Update()
{
	Input();
}

void DebugBlockMove::Input()
{
	// スクロール処理

// デバッグ用入力
	if (CheckHitKeyAll != 0)
	{
		if (CheckHitKey(KEY_INPUT_W))
		{
			move_val.y = 5;
		}
		else if (CheckHitKey(KEY_INPUT_S))
		{
			move_val.y = -5;
		}
		else
		{
			move_val.y = 0;
		}

		if (CheckHitKey(KEY_INPUT_A))
		{
			move_val.x = 5;
		}
		else if (CheckHitKey(KEY_INPUT_D))
		{
			move_val.x = -5;
		}
		else
		{
			move_val.x = 0;
		}
	}

}