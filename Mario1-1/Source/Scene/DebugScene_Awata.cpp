#include "DebugScene_Awata.h"
#include "..\ManagerClass\ObjectManager.h"
#include "..\ManagerClass\FPSManager.h"

//コンストラクタ
DebugObject::DebugObject(Vector2 position_, std::string tag_, int width_, int height_)
	: ObjectBase(position_, tag_, width_, height_) {
}
//デストラクタ
DebugObject::~DebugObject() { ImageManager::DeleteImages(); }

void DebugObject::Update() {}
void DebugObject::Draw() {
	DrawCollider();
}

//コンストラクタ
DebugScene_Awata::DebugScene_Awata()
	: SceneBase("DebugScene : Awata") {
	DebugObject* object01 = new DebugObject(Vector2(0, 450), "Block", 450, 20);
	DebugObject* object02 = new DebugObject(Vector2(200, 400), "FireFlower", 30, 30);
	Input::CreateInstance();
	Input::GetInstance().SetUpJoypadInput(DX_PADTYPE_DUAL_SENSE);
	ImageManager::LoadImages();
	Mario* mario = new Mario(Vector2(0, 0));
}

void DebugObject::OnCollision(const CollideResult& other_) {
	DrawCircle(100, 100, 20, GetColor(0, 0, 255), TRUE);
	
}

//デストラクタ
DebugScene_Awata::~DebugScene_Awata() {
	Input::DeleteInsatance();
	ImageManager::DeleteImages();
}

//更新処理
SceneBase* DebugScene_Awata::Update() {
	static float timer = 0.0f;
	timer += FPSManager::GetInstance()->GetDeltaTime();

	if (Input::GetInstance().GetInputRightButton()) {
		if (timer >= 2.0f) {
			FireBall* ball = new FireBall(Vector2(100, 400), true);
			timer = 0.0f;
		}
	}
	
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