#include "ObjectBase.h"
#include "..\ManagerClass\ObjectManager.h"

//�R���X�g���N�^
ObjectBase::ObjectBase(Vector2 position_, int image_handle, std::string tag_)
	:BoxCollider(position, image_handle, tag_), position(position_), isVisible(true), isActive(true) {
	ObjectManager::GetInstance()->AddList(this);
}

ObjectBase::ObjectBase(Vector2 position_, std::string tag_, int width_, int height_)
	:BoxCollider(position, width_, height_, tag_), position(position_), isVisible(true), isActive(true) {
	ObjectManager::GetInstance()->AddList(this);
}

//�f�X�g���N�^
ObjectBase::~ObjectBase() {}

//�X�V����
void ObjectBase::Update() {}

//�`�揈��
void ObjectBase::Draw() {}

//�Փ˔��莞�̏���
void ObjectBase::OnCollision(const CollideResult& result_) {}