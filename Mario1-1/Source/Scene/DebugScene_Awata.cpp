#include "DebugScene_Awata.h"
#include "..\ManagerClass\ObjectManager.h"
#include "..\ManagerClass\FPSManager.h"

//コンストラクタ
DebugObject02::DebugObject02()
	: ObjectBase(Vector2(0, 450), "Block", 520, 30) {}
//デストラクタ
DebugObject02::~DebugObject02() {}

void DebugObject02::Update() {}
void DebugObject02::Draw() {
	DrawCollider();
}

//コンストラクタ
DebugScene_Awata::DebugScene_Awata()
	: SceneBase("DebugScene : Awata") {
	DebugObject02* object02 = new DebugObject02();
	Input::CreateInstance();
	Input::GetInstance().SetUpJoypadInput(DX_PADTYPE_DUAL_SENSE);
}

void DebugObject02::OnCollision(const CollideResult& other_) {
	DrawCircle(100, 100, 20, GetColor(0, 0, 255), TRUE);
	
}

//デストラクタ
DebugScene_Awata::~DebugScene_Awata() {
	Input::DeleteInsatance();
}

//更新処理
SceneBase* DebugScene_Awata::Update() {
	
	Input::GetInstance().GetInputState();
	//ゲーム内のオブジェクトの更新処理
	ObjectManager::GetInstance()->Update();
	timer += FPSManager::GetInstance()->GetDeltaTime();
	
	return this;
}

//描画処理
void DebugScene_Awata::Draw() {
	//シーンの種類を表示
	DrawType();
	//ゲーム内のオブジェクトの描画処理
	ObjectManager::GetInstance()->Draw();
	DrawFormatString(200, 0, GetColor(255, 255, 255), "%f", timer);
}