#include "NormalBlock.h"

NormalBlock::NormalBlock(Vector2 position_,int handle_):BlockBase(position_,handle_),imageHandle(handle_)
{

}

NormalBlock::~NormalBlock()
{

}

void NormalBlock::Draw()
{
	DrawGraph(position.x, position.y, imageHandle, TRUE);
}