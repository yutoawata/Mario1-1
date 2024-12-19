#include "Block.h"

const std::string Block::TAG = "Block";

// コンストラクタ(アイテムなし)
Block::Block(Vector2 position_,std::vector<int> handle_, bool can_break)
	:ObjectBase(handle_,position_, TAG), inItem(InItem::NONE), itemValue(0), canBreak(can_break)
{};

// コンストラクタ(アイテムあり)
Block::Block(Vector2 position_, std::vector<int> handle_, InItem type_, int value_)
	:ObjectBase(handle_,position_, TAG), inItem(type_), itemValue(value_), canBreak(false)
{

};

Block::~Block()
{

}

void Block::Update()
{

}

void Block::Draw()
{
	//DrawGraph(position.x, position.y, imageHandle, TRUE);
}