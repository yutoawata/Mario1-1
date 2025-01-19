#include "BrickBlock.h"

BrickBlock::BrickBlock(int* handle_, Vector2 position_, ItemType item_type, int item_value, bool is_visible) 
	: ItemBlockBase(handle_,position_,item_type,item_value),imageHandles(handle_),isVisible(is_visible)
{
	
}

BrickBlock::~BrickBlock()
{

}

void BrickBlock::Update()
{
	BlockBase::Update();
}

void BrickBlock::Draw()
{
	if(itemValue <= 0)
	{
		DrawGraph(position.x, position.y, imageHandles[1], TRUE);
	}
	else if(isVisible)
	{
		DrawGraph(position.x, position.y, imageHandles[0], TRUE);
	}
}