#include "DebugScene_Awata.h"
#include "..\ManagerClass\ObjectManager.h"

DebugObject::DebugObject()
	: ObjectBase(Vector2(40,40),0) {}

DebugObject::~DebugObject() {}

//コンストラクタ
DebugScene_Awata::DebugScene_Awata()
	: SceneBase("DebugScene : Awata") {
	DebugObject* object = new DebugObject();
}

void DebugObject::Update() {

}

void DebugObject::Draw() {
	DrawCircle(position.x, position.y, 20, GetColor(255, 0, 0), TRUE);
}

//デストラクタ
DebugScene_Awata::~DebugScene_Awata() {}

//更新処理
SceneBase* DebugScene_Awata::Update() {
	
	//ゲーム内のオブジェクトの更新処理
	ObjectManager::getInstance()->Update();

	return this;
}

//描画処理
void DebugScene_Awata::Draw() {
	//シーンの種類を表示
	DrawType();
	//ゲーム内のオブジェクトの描画処理
	ObjectManager::getInstance()->Draw();
}