#include "Pype.h"

Pype::Pype(Vector2 position_,int image_handle,std::string tag_):ObjectBase(position_,image_handle,tag_),imageHandle(image_handle)
{

}

Pype::~Pype()
{

}

void Pype::Update()
{
	// position += Mario::GetScrollValue();
	position += MoveValueManager::GetMoveValue();
}

void Pype::Draw()
{
	DrawGraph(position.x, position.y, imageHandle,TRUE);
}