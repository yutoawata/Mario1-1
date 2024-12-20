#include "ObjectBase.h"
#include "..\ManagerClass\ObjectManager.h"

//コンストラクタ
ObjectBase::ObjectBase(Vector2 position_, int image_handle, std::string tag_)
	:BoxCollider(position, image_handle, tag_), position(position_), isVisible(true), isActive(true) {
	ObjectManager::GetInstance()->AddList(this);
}

ObjectBase::ObjectBase(Vector2 position_, std::string tag_, int width_, int height_)
	:BoxCollider(position, width_, height_, tag_), position(position_), isVisible(true), isActive(true) {
	ObjectManager::GetInstance()->AddList(this);
}

//デストラクタ
ObjectBase::~ObjectBase() {}

//更新処理
void ObjectBase::Update() {}

//描画処理
void ObjectBase::Draw() {}

//衝突判定時の処理
void ObjectBase::OnCollision(const CollideResult& result_) {}