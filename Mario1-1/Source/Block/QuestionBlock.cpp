#include "QuestionBlock.h"

QuestionBlock::QuestionBlock(int* handle_, Vector2 position_, ItemType item_type, int item_value)
	: ItemBlockBase(handle_, position_, item_type, item_value), imageHandles(handle_), count(0), timer(0.0f)
{

}

QuestionBlock::~QuestionBlock()
{

}

void QuestionBlock::Update()
{
	timer += FPSManager::GetInstance()->GetDeltaTime();
	if (timer > LOOP_TOTAL_TIME / LOOP_PATERN_VALUE)
	{
		timer = 0.0f;
		count++;
		if (count >= LOOP_PATERN_VALUE)
		{
			count = 0;
		}
	}
}

void QuestionBlock::Draw()
{
	DrawGraph(position.x, position.y, imageHandles[0], TRUE);
}