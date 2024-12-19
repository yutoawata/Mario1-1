#include "DebugScene_Monda.h"
#include "..\ManagerClass\ObjectManager.h"

//�R���X�g���N�^
DebugScene_Monda::DebugScene_Monda()
	:SceneBase("DebugScene : Monda") {}

//�f�X�g���N�^
DebugScene_Monda::~DebugScene_Monda() {}

//�X�V����
SceneBase* DebugScene_Monda::Update() {
	
	//�Q�[�����̃I�u�W�F�N�g�̍X�V����
	ObjectManager::GetInstance()->Update();

	return this;
}

//�`�揈��
void DebugScene_Monda::Draw() {
	DrawType();
	//�Q�[�����̃I�u�W�F�N�g�̕`�揈��
	ObjectManager::GetInstance()->Draw();
}