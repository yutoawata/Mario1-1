#include "DebugScene_Awata.h"
#include "..\ManagerClass\ObjectManager.h"

DebugObject::DebugObject()
	: ObjectBase(Vector2(40,40),0) {}

DebugObject::~DebugObject() {}

//�R���X�g���N�^
DebugScene_Awata::DebugScene_Awata()
	: SceneBase("DebugScene : Awata") {
	DebugObject* object = new DebugObject();
}

void DebugObject::Update() {

}

void DebugObject::Draw() {
	DrawCircle(position.x, position.y, 20, GetColor(255, 0, 0), TRUE);
}

//�f�X�g���N�^
DebugScene_Awata::~DebugScene_Awata() {}

//�X�V����
SceneBase* DebugScene_Awata::Update() {
	
	//�Q�[�����̃I�u�W�F�N�g�̍X�V����
	ObjectManager::getInstance()->Update();

	return this;
}

//�`�揈��
void DebugScene_Awata::Draw() {
	//�V�[���̎�ނ�\��
	DrawType();
	//�Q�[�����̃I�u�W�F�N�g�̕`�揈��
	ObjectManager::getInstance()->Draw();
}