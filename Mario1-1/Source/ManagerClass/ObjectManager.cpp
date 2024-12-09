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