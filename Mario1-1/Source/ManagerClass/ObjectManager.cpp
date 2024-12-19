#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = new ObjectManager();

ObjectManager::ObjectManager() {}

//デストラクタ
ObjectManager::~ObjectManager() {
	ClearList();
	
}

//更新処理
void ObjectManager::Update() {
	int objectNum = 0;
	for (ObjectBase* const  object : objectList) {
		object->Update();
		CollideObjects(*object, objectNum);
		objectNum++;
	}
}

//描画処理
void ObjectManager::Draw() {
	for (ObjectBase* const object : objectList) {
		if (object->IsVisible()) {
			object->Draw();
			object->DrawCollider();
		}
	}
}

void ObjectManager::CollideObjects(ObjectBase& object_, int object_num) {

	bool isCollide = false;//衝突フラグ
	//制作中
	for (int i = object_num + 1; i < objectList.size(); ++i) {
		if (object_.Collide(*objectList[i])) {
			object_.OnCollision(CreateResult(object_, *objectList[i]));
		}
		if (objectList[i]->Collide(object_)) {
			objectList[i]->OnCollision(CreateResult(*objectList[i],object_));
		}
	}
}

bool ObjectManager::CheckCollision(const BoxCollider& collider_01, const BoxCollider& collider_02) {

	//collider_01の左だり上の座標がCollider_02の右下の座標より左にある
	return (collider_01.GetLeftUpPosition().x <= collider_02.GetRightBottomPosition().x
		//かつ Collider_01の右下の座標がcollider_02の左上の座標より右にある
		&& collider_01.GetRightBottomPosition().x >= collider_02.GetLeftUpPosition().x
		//かつ collider_01の左上の座標がcollider_02の右下の座標より上にある
		&& collider_01.GetLeftUpPosition().y <= collider_02.GetRightBottomPosition().y
		//かつ collider_01の右下の座標がcollider_02の左上の座標より下にある ならば衝突している
		&& collider_01.GetRightBottomPosition().y >= collider_02.GetLeftUpPosition().y
		);
}

CollideResult ObjectManager::CreateResult(const ObjectBase& collider_01, const ObjectBase& collider_02) {
	Vector2 CenterPosition = collider_01.GetLeftUpPosition() + (collider_01.GetLength() / 2);
	Vector2 otherCenterPosition = collider_02.GetLeftUpPosition() + (collider_02.GetLength() / 2);

	Vector2 direction = otherCenterPosition - CenterPosition;
	int deltaX = (collider_01.GetWidth() + collider_02.GetWidth()) - abs(direction.x);
	int deltaY = (collider_01.GetHeigth() + collider_02.GetHeigth()) - abs(direction.y);

	std::string collideDirection;
	if (deltaX >= deltaY) {
		if (direction.y < 0) {
			collideDirection = "Up";
		}
		else if (direction.y < 0) {
			collideDirection = "Down";
		}
	}
	if (deltaX <= deltaY) {
		if (direction.x < 0) {
			collideDirection = "Left";
		}
		else if (direction.x > 0) {
			collideDirection = "Right";
		}
	}

	CollideResult result = CollideResult(collider_02, collideDirection);

	return result;
}

//登録処理
void ObjectManager::AddList(ObjectBase* object_) {
	objectList.emplace_back(object_);
}


void ObjectManager::ClearList() {
	//リスト内のインスタンスを全て削除
	for (const ObjectBase* object : objectList) {
		delete object;
	}
	objectList.clear();
}

void ObjectManager::DeleteInstance() {
	delete instance;
}