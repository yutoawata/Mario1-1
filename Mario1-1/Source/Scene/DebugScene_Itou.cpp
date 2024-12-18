#include "DebugScene_Itou.h"
#include "..\ManagerClass\ObjectManager.h"

//�R���X�g���N�^
DebugScene_Itou::DebugScene_Itou()
	:SceneBase("DebugScene : Itou") {}

//�f�X�g���N�^
DebugScene_Itou::~DebugScene_Itou() {}

//�X�V����
SceneBase* DebugScene_Itou::Update() {

	map->MovePositionDebug();

	//�Q�[�����̃I�u�W�F�N�g�̍X�V����
	ObjectManager::getInstance()->Update();

	return this;
}

//�`�揈��
void DebugScene_Itou::Draw() {
	DrawType();

	map->ViewDataDebug();

	//�Q�[�����̃I�u�W�F�N�g�̕`�揈��
	ObjectManager::getInstance()->Draw();
}