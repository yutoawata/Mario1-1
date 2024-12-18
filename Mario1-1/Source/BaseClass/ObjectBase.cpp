#include "ObjectBase.h"
#include "..\ManagerClass\ObjectManager.h"

//�R���X�g���N�^
ObjectBase::ObjectBase(std::vector<int> graph_handles, Vector2 position_, std::string tag_)
	:BoxCollider(position, graph_handles[0], tag_), graphHandles(graph_handles), position(position_), isVisible(true) {
	ObjectManager::AddList(this);
}

ObjectBase::ObjectBase(Vector2 position_, std::string tag_, int width_, int height_)
	:BoxCollider(position, width_, height_, tag_), position(position_), isVisible(true) {
	ObjectManager::AddList(this);
}

//�f�X�g���N�^
ObjectBase::~ObjectBase() {}

//�X�V����
void ObjectBase::Update() {}

//�`�揈��
void ObjectBase::Draw() {}

//�Փ˔��莞�̏���
void ObjectBase::OnCollision(const CollideResult& result_) {}