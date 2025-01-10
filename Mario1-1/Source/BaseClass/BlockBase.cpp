#include "BlockBase.h"

BlockBase::BlockBase(Vector2 position_, int handle_) : ObjectBase(position_, handle_, "Block")
{

}

BlockBase::~BlockBase()
{

}

void BlockBase::Update()
{
	Move();
}

void BlockBase::Move()
{
	// スクロール処理

	// デバッグ用入力
	if (CheckHitKeyAll != 0)
	{
		if (CheckHitKey(KEY_INPUT_W))
		{
			position.y -= 5;
		}
		else if (CheckHitKey(KEY_INPUT_S))
		{
			position.y += 5;
		}

		if (CheckHitKey(KEY_INPUT_A))
		{
			position.x -= 5;
		}
		else if (CheckHitKey(KEY_INPUT_D))
		{
			position.x += 5;
		}
	}
}
