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
	// ƒXƒNƒ[ƒ‹ˆ—
}
