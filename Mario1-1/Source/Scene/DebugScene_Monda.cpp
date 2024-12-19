#include "DebugScene_Monda.h"
#include "..\ManagerClass\ObjectManager.h"

//コンストラクタ
DebugScene_Monda::DebugScene_Monda()
	:SceneBase("DebugScene : Monda") {}

//デストラクタ
DebugScene_Monda::~DebugScene_Monda() {}

//更新処理
SceneBase* DebugScene_Monda::Update() {
	
	//ゲーム内のオブジェクトの更新処理
	ObjectManager::GetInstance()->Update();

	return this;
}

//描画処理
void DebugScene_Monda::Draw() {
	DrawType();
	//ゲーム内のオブジェクトの描画処理
	ObjectManager::GetInstance()->Draw();
}