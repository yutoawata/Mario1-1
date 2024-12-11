#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = new ObjectManager();

std::vector<ObjectBase*> ObjectManager::objectList = std::vector<ObjectBase*>();

ObjectManager::ObjectManager() {}

//デストラクタ
ObjectManager::~ObjectManager() {
	ClearList();
}

//更新処理
void ObjectManager::Update() {
	for (ObjectBase* const object : objectList) {
		object->Update();
	}
}

//描画処理
void ObjectManager::Draw() {
	for (ObjectBase* const object : objectList) {
		if (object->IsVisible()) {
			object->Draw();
		}
	}
}

void ObjectManager::CollideObjects(ObjectBase& object_, int object_num) {

	//制作中
	/*for (int i = object_num + 1; i < objectList.size(); i++) {
		if (CheckCollision(object_, *objectList[i])) {
			if (object_.IsTrigger() || objectList[i]->IsTrigger()) {
				object_.OnTrigger(objectList[i])
			}
		}
	}*/
}

bool ObjectManager::CheckCollision(const BoxCollider& collider_01, const BoxCollider& colliser_02) {
	//制作中
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