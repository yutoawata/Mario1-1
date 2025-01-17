#include "BlockBase.h"

BlockBase::BlockBase(Vector2 position_, int handle_) : ObjectBase(position_, handle_, "Block")
{

}

BlockBase::~BlockBase()
{

}

void BlockBase::Update()
{
	debugMoveBlock->Update();
	Move();
}

void BlockBase::Move()
{
	move_val = debugMoveBlock->GetMove_Val();
	position += move_val;
}
