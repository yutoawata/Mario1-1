#include "Mario.h"
#include "State/NormalState.h"
#include "State/SuperState.h"
#include "State/FireState.h"
#include "../ManagerClass/FPSManager.h"

int Mario::scrollValue = 0;

//コンストラクタ
Mario::Mario(Vector2 position_)
	: ObjectBase(position_, 1, "Mario")
	, moveSpeed(2), currentState(new NormalState<Mario>(*this)) {
	length = Vector2(50, 50);
	LoadDivGraph("././Resource/Images/NormalMario.png", 9, 3, 3, 32, 32, handle);
	currentAnim = idle;
}

//デストラクタ
Mario::~Mario() {}

//更新処理
void Mario::Update() {
	
	Move();

	currentState = currentState->Update();
	currentAnim = currentState->GetCurrentAnim();

	if (CheckHitKey(KEY_INPUT_M)) {
		currentAnim = run;
	}
	else if (CheckHitKey(KEY_INPUT_1)) {
		delete currentState;
		currentState = new NormalState<Mario>(*this);
	}
	else if (CheckHitKey(KEY_INPUT_2)) {
		delete currentState;
		currentState = new SuperState<Mario>(*this);
	}
	else if (CheckHitKey(KEY_INPUT_3)) {
		delete currentState;
		currentState = new FireState<Mario>(*this);
	}
	position.y += 1;
}

//描画処理
void Mario::Draw() {
	DrawGraph(position.x, position.y, handle[currentAnim.first + imageNum], TRUE);
	//DrawFillBox(position.x, position.y, position.x + length.x, position.y + length.y, GetColor(255, 0, 0));
}

//衝突時の処理
void Mario::OnCollision(const CollideResult& result_) {
	if (result_.GetCollideObject().GetTag() == "Block" && result_.IsBottomCollide()) {
		isJump = false;
	}
}

//移動処理
void Mario::Move() {
	
	//座標移動処理

	if (Input::GetInstance().GetInputDirectionButtonLeft()) {
		position.x -= moveSpeed;
		currentAnim = run;
		//scrollValue++;
	}
	else if (Input::GetInstance().GetInputDirectionButtonRight()) {
		position.x += moveSpeed;
		currentAnim = run;
	}

	//移動アニメーション処理

	static float timer = 0.0f;
	static bool isAdd = true;
	timer += FPSManager::GetInstance()->GetDeltaTime();

	if (timer >= 0.1f) {
		if (isAdd) {
			imageNum++;
			if (imageNum >= currentAnim.second) {
				isAdd = false;
				imageNum--;
			}
		}
		else {
			imageNum--;
			if (imageNum < 0) {
				isAdd = true;
				imageNum++;
			}
		}
		timer = 0.0f;

	}
}

//ジャンプ処理
void Mario::Jump() {
	static int jumpPower = 0;

	if (Input::GetInstance().GetInputLeftButton() && !isJump) {
		jumpPower = JUMP_POWER;
		currentAnim = jump;
	}

	if (isJump) {
		position.y += jumpPower;
		jumpPower--;
	}
}