#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = new ObjectManager();

std::vector<ObjectBase*> ObjectManager::objectList = std::vector<ObjectBase*>();

ObjectManager::ObjectManager() {}

//�f�X�g���N�^
ObjectManager::~ObjectManager() {
	ClearList();
}

//�X�V����
void ObjectManager::Update() {
	for (ObjectBase* const object : objectList) {
		object->Update();
	}
}

//�`�揈��
void ObjectManager::Draw() {
	for (ObjectBase* const object : objectList) {
		if (object->IsVisible()) {
			object->Draw();
		}
	}
}

//�o�^����
void ObjectManager::AddList(ObjectBase* object_) {
	objectList.emplace_back(object_);
}


void ObjectManager::ClearList() {
	//���X�g���̃C���X�^���X��S�č폜
	for (const ObjectBase* object : objectList) {
		delete object;
	}
	objectList.clear();
}

void ObjectManager::DeleteInstance() {
	delete instance;
}