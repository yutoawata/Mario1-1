#include "PlayScene.h"
#include"TitleScene.h"
#include "..\ManagerClass\ObjectManager.h"

//コンストラクタ
PlayScene::PlayScene()
	: SceneBase("Play  Space") {}
//デストラクタ
PlayScene::~PlayScene() {

}

//更新処理
SceneBase* PlayScene::Update() {

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		return ChangeScene<TitleScene>();
	}

	ObjectManager::GetInstance()->Update();

	return this;
}

//描画処理
void PlayScene::Draw() {
	DrawType();
	ObjectManager::GetInstance()->Draw();
}
