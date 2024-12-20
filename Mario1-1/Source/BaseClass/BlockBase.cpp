#include "BlockBase.h"

BlockBase::BlockBase(Vector2 position_, int handle_):ObjectBase(handle_,position_, TAG)
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
