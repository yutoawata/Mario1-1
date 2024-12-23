#include "BrickBlock.h"

BrickBlock::BrickBlock(int* handle_, Vector2 position_, ItemType item_type, int item_value) 
	: ItemBlockBase(handle_,position_,item_type,item_value),imageHandles(handle_)
{
	
}

BrickBlock::~BrickBlock()
{

}

void BrickBlock::Update()
{
	
}

void BrickBlock::Draw()
{
	DrawGraph(position.x, position.y, imageHandles[handleID], TRUE);
}