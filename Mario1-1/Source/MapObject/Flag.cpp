#include "Flag.h"

Flag::Flag(Vector2 position_, int image_handle):ObjectBase(position_,image_handle,"Flag"),imageHandle(image_handle)
{
	isActive = false;
}

Flag::~Flag()
{

}

void Flag::Update()
{
	// position += Mario::GetScrollValue();
	position += MoveValueManager::GetMoveValue();
}

void Flag::Draw()
{
	DrawGraph(position.x + 11, position.y + 10, imageHandle,TRUE);
}