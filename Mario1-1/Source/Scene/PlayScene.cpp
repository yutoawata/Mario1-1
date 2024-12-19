#include "PlayScene.h"
#include"TitleScene.h"
#include "..\ManagerClass\ObjectManager.h"

//�R���X�g���N�^
PlayScene::PlayScene()
	: SceneBase("Play  Space") {}
//�f�X�g���N�^
PlayScene::~PlayScene() {

}

//�X�V����
SceneBase* PlayScene::Update() {

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		return ChangeScene<TitleScene>();
	}

	ObjectManager::GetInstance()->Update();

	return this;
}

//�`�揈��
void PlayScene::Draw() {
	DrawType();
	ObjectManager::GetInstance()->Draw();
}
