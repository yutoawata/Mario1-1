#include "Block.h"

const std::string Block::TAG = "Block";

// �R���X�g���N�^(�A�C�e���Ȃ�)
Block::Block(Vector2 position_,std::vector<int> handle_, bool can_break)
	:ObjectBase(position_,handle_[0]),inItem(InItem::NONE),itemValue(0),canBreak(can_break)
{};

// �R���X�g���N�^(�A�C�e������)
Block::Block(Vector2 position_, std::vector<int> handle_, InItem type_, int value_)
	:ObjectBase(position_, handle_[0]), inItem(type_),itemValue(value_),canBreak(false)
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
	DrawGraph(position.x, position.y, imageHandle, TRUE);
}