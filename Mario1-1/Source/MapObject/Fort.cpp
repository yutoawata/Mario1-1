#include "Fort.h"

Fort::Fort(Vector2 position_, int image_handle) :ObjectBase(position_, image_handle, "Flag"), imageHandle(image_handle)
{
	isActive = false;
}

Fort::~Fort()
{

}

void Fort::Update()
{
	position += Mario::GetScrollValue();
	//position += MoveValueManager::GetMoveValue();
}

void Fort::Draw()
{
	DrawGraph(position.x, position.y, imageHandle, TRUE);
}