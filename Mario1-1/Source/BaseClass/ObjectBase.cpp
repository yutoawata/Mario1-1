#include "ObjectBase.h"
#include "..\ManagerClass\ObjectManager.h"

//�R���X�g���N�^
ObjectBase::ObjectBase(Vector2 position_, int image_handle)
	:/*BoxCollider(image_handle) ,*/position(position_), imageHandle(image_handle), isVisible(true) {
	ObjectManager::AddList(this);
}

//�f�X�g���N�^
ObjectBase::~ObjectBase() {}