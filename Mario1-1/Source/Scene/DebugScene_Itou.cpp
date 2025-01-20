#include "DebugScene_Itou.h"
#include "..\ManagerClass\ObjectManager.h"

//コンストラクタ
DebugScene_Itou::DebugScene_Itou()
	:SceneBase("DebugScene : Itou")
{
	ImageManager::LoadImages();

	map -> CreateMap();
}

//デストラクタ
DebugScene_Itou::~DebugScene_Itou() 
{
	ImageManager::DeleteImages();
	delete map;
	delete debugBlockMove;
}

//更新処理
SceneBase* DebugScene_Itou::Update() {


	//ゲーム内のオブジェクトの更新処理
	ObjectManager::GetInstance()->Update();

	debugBlockMove->Update();

	return this;
}

//描画処理
void DebugScene_Itou::Draw() {
	DrawType();



	//ゲーム内のオブジェクトの描画処理
	ObjectManager::GetInstance()->Draw();
}