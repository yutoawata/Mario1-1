#include "Pole.h"

Pole::Pole(Vector2 position_, int image_handle):ObjectBase(position_,image_handle,"Pole"),imageHandle(image_handle)
{

}

Pole::~Pole()
{

}

void Pole::Update()
{
	position += Mario::GetScrollValue();
	//position += MoveValueManager::GetMoveValue();
}

void Pole::Draw()
{
	DrawGraph(position.x, position.y, imageHandle, TRUE);
}