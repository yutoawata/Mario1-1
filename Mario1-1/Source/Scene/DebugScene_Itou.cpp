#include "DebugScene_Itou.h"
#include "..\ManagerClass\ObjectManager.h"

//コンストラクタ
DebugScene_Itou::DebugScene_Itou()
	:SceneBase("DebugScene : Itou") {}

//デストラクタ
DebugScene_Itou::~DebugScene_Itou() {}

//更新処理
SceneBase* DebugScene_Itou::Update() {

	map->MovePositionDebug();

	//ゲーム内のオブジェクトの更新処理
	ObjectManager::getInstance()->Update();

	return this;
}

//描画処理
void DebugScene_Itou::Draw() {
	DrawType();

	map->ViewDataDebug();

	//ゲーム内のオブジェクトの描画処理
	ObjectManager::getInstance()->Draw();
}