#include "ObjectBase.h"
#include "..\ManagerClass\ObjectManager.h"

//コンストラクタ
ObjectBase::ObjectBase(Vector2 position_, int image_handle)
	:/*BoxCollider(image_handle) ,*/position(position_), imageHandle(image_handle), isVisible(true) {
	ObjectManager::AddList(this);
}

//デストラクタ
ObjectBase::~ObjectBase() {}