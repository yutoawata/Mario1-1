#include "Mario.h"
#include "State/NormalState.h"
#include "State/SuperState.h"
#include "State/FireState.h"
#include "..\GameMain\GameManagerh.h"
#include "../ManagerClass/FPSManager.h"

int Mario::normalImageHandle[9] = {};
int Mario::superImageHandle[9] = {};
int Mario::FireImageHandle[9] = {};

int Mario::scrollValue = 0;

//コンストラクタ
Mario::Mario(Vector2 position_)
	: ObjectBase(position_, 1, "Mario")
	, moveSpeed(2), currentState(new NormalState(*this)) {
	length = Vector2(32, 32);
	LoadDivGraph("././Resource/Images/NormalMario.png", 9, 3, 3, 32, 32, normalImageHandle);
	LoadDivGraph("././Resouece/Images/SuperMario.png", 9, 3, 3, 32, 32, superImageHandle);
	LoadDivGraph("././Resouece/Images/FireMario.png", 9, 3, 3, 32, 32, FireImageHandle);
	currentState->GetImageHandle(handle);
	currentAnim = idle;
}

//デストラクタ
Mario::~Mario() {
	for (int i = 0; i < 9; i++) {
		DeleteGraph(handle[i]);
	}
}

//更新処理
void Mario::Update() {
	currentAnim = idle;
	isDamage = false;

	Move();
	Jump();

	if (CheckHitKey(KEY_INPUT_M)) {
		currentAnim = run;
	}
	else if (CheckHitKey(KEY_INPUT_1)) {
		delete currentState;
		position.y += length.y;
		currentState = new NormalState(*this);
	}
	else if (CheckHitKey(KEY_INPUT_2)) {
		delete currentState;
		position.y += length.y;
		currentState = new SuperState(*this);
	}
	else if (CheckHitKey(KEY_INPUT_3)) {
		delete currentState;
		currentState = new FireState(*this);
	}
	position.y += 5;
}

//判定処理後の更新処理
void Mario::LateUpdate() {
	//現在の形態の更新処理
	currentState->Update();
	//現在の形態が指定するアニメーションを取得
	currentAnim = currentState->GetCurrentAnim();
	currentState->GetImageHandle(handle);

	//アニメーションを再生
	PlayAnimation();
}

//描画処理
void Mario::Draw() {
	if (isTurn) {
		//左右反転描画
		DrawTurnGraph(position.x, position.y, handle[currentAnim.first + imageNum], TRUE);
	}
	else {
		//通常の描画
		DrawGraph(position.x, position.y, handle[currentAnim.first + imageNum], TRUE);
	}
	
	//DrawFillBox(position.x, position.y, position.x + length.x, position.y + length.y, GetColor(255, 0, 0));
}

//衝突時の処理
void Mario::OnCollision(const CollideResult& result_) {
	
	//ブロックの上に立っていれば
	if (result_.GetCollideObject().GetTag() == "Block" && result_.IsBottomCollide()) {
		isJump = false;
	}
	else {
		//敵オブジェクトに衝突すれば
		if (result_.GetCollideObject().GetTag() == "Enemy") {
			isDamage = true;
		}

		//形態遷移処理(衝突相手のタグから判別)
		currentState = currentState->ChangeState(result_.GetCollideObject().GetTag());
	}

	if (result_.IsUpCollide()) {
		DrawString(30, 100, "Up", GetColor(255, 255, 255));
	}
	else if (result_.IsBottomCollide()) {
		DrawString(30, 100, "Bottom", GetColor(255, 255, 255));
	}
	else if (result_.IsLeftCollide()) {
		DrawString(30, 100, "Left", GetColor(255, 255, 255));
	}
	else if (result_.IsRightCollide()) {
		DrawString(30, 100, "Right", GetColor(255, 255, 255));
	}

}

//移動処理
void Mario::Move() {

	scrollValue = 0;

	//座標移動処理
	if (Input::GetInstance().GetInputDirectionButtonLeft()) {
		position.x -= moveSpeed;
		currentAnim = run;
		isTurn = true;
	}
	else if (Input::GetInstance().GetInputDirectionButtonRight()) {
		isTurn = false;
		currentAnim = run;

		if (position.x >= GameManager::SCREEN_WIDTH / 2) {
			scrollValue++;
		}
		else {
			position.x += moveSpeed;
		}
	}
}

//ジャンプ処理
void Mario::Jump() {
	static int jumpPower = 0;

	if (Input::GetInstance().GetInputLeftButton() && !isJump) {
		jumpPower = -JUMP_POWER;
		isJump = true;
	}

	if (isJump) {
		currentAnim = jump;
		position.y += jumpPower;
		jumpPower++;
	}
}

//しゃがみ処理
void Mario::Squat() {
	length.x /= 2;//しゃがみ状態では高さが1/2
}

void Mario::PlayAnimation() {
	static float timer = 0.0f;
	static bool isAdd = true;
	timer += FPSManager::GetInstance()->GetDeltaTime();

	if (timer >= animInterval) {
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