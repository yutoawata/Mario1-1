#include "BreakBlock.h"

BreakBlock::BreakBlock(Vector2 position_, int handle_) :BlockBase(position_, handle_),imageHandle(handle_)
{

}

BreakBlock::~BreakBlock()
{

}

void BreakBlock::Draw()
{
	DrawGraph(position.x, position.y, imageHandle, TRUE);
}

void BreakBlock::OnCollision(const CollideResult& result_)
{
	// ÚG‚Ìˆ—
}