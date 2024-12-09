#include "TitleScene.h"
#include "PlayScene.h"
#include "DebugScene_Awata.h"
#include "DebugScene_Itou.h"
#include "DebugScene_Monda.h"

//�R���X�g���N�^
TitleScene::TitleScene()
	:SceneBase("Title  Return") {}

//�f�X�g���N�^
TitleScene::~TitleScene() {}

//�X�V����
SceneBase* TitleScene::Update() {

	if (CheckHitKey(KEY_INPUT_RETURN)) {
		return ChangeScene<PlayScene>();
	}
	else if (CheckHitKey(KEY_INPUT_A)) {
		return ChangeScene<DebugScene_Awata>();
	}
	else if (CheckHitKey(KEY_INPUT_I)) {
		return ChangeScene<DebugScene_Itou>();
	}
	else if (CheckHitKey(KEY_INPUT_M)) {
		return ChangeScene<DebugScene_Monda>();
	}


	return this;
}

//�`�揈��
void TitleScene::Draw() {
	
	DrawType();

	DrawString(30, 30, "Awata : Input A", GetColor(255, 255, 255));
	DrawString(30, 60, "Itou : Input I", GetColor(255, 255, 255));
	DrawString(30, 90, "Monda : Input M", GetColor(255, 255, 255));
}