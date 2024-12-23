#include "ItemBlockBase.h"

ItemBlockBase::ItemBlockBase(int* handle_, Vector2 position_, ItemType item_type, int item_value)
	:BlockBase(position_,handle_[0]),itemType(item_type),itemValue(item_value)
{

}

ItemBlockBase::~ItemBlockBase()
{

}

void ItemBlockBase::OnCollision(const CollideResult& result_)
{
	if (result_.GetCollideObject().GetTag() == "Player" && result_.IsBottomCollide())
	{
		CreateItem();
	}
	else
	{
		return;
	}
}

void ItemBlockBase::CreateItem()
{
	if (itemValue < 0)
	{
		return;
	}

	itemValue--;
}