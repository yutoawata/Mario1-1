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
	// move_val = Mario::GetScrollValue();
	move_val = MoveValueManager::GetMoveValue();
	position += move_val;
}
