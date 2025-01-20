#include "Mario.h"
#include "State/NormalState.h"
#include "State/SuperState.h"
#include "State/FireState.h"
#include "..\GameMain\GameManagerh.h"
#include "../ManagerClass/FPSManager.h"

int Mario::normalImageHandle[9] = {};
int Mario::superImageHandle[9] = {};
int Mario::FireImageHandle[9] = {};

Vector2 Mario::scrollValue = Vector2::ZERO;

//コンストラクタ
Mario::Mario(Vector2 position_)
	: ObjectBase(position_, -1, "Mario")
	, moveSpeed(0), currentState(new NormalState(*this)) {
	currentState->GetImageHandle(handle);
	GetGraphSize(handle[0], &length.x, &length.y);
	ChangeAnim(idle);
}

//デストラクタ
Mario::~Mario() {
	for (int i = 0; i < 9; i++) {
		DeleteGraph(handle[i]);
	}
}

//更新処理
void Mario::Update() {
	bool isAction = false;
	isDamage = false;
	isGround = false;
	DrawPosition = position;
	
	if (Move()) {
		isAction = true;
	}
	if (Jump()) {
		isAction = true;
	}

	if (Squat()) {
		isAction = true;
	}

	if (!isAction) {
		ChangeAnim(idle);
		DrawCircle(30, 200, 5, GetColor(255, 255, 255), TRUE);
	}
	if (CheckHitKey(KEY_INPUT_1)) {
		ChangeState(StateType::NORMAL);
	}
	else if (CheckHitKey(KEY_INPUT_2)) {
		ChangeState(StateType::SUPER);
	}
	else if (CheckHitKey(KEY_INPUT_3)) {
		ChangeState(StateType::FIRE);
	}
}

//判定処理後の更新処理
void Mario::LateUpdate() {
	//現在の形態の更新処理
	currentState->Update();
	//現在の形態が指定するアニメーションを取得
	currentAnim = currentState->GetCurrentAnim();
	currentState->GetImageHandle(handle);

	if (!isGround) {
		position.y += 5;
	}

	//アニメーションを再生
	PlayAnimation();
}

//描画処理
void Mario::Draw() {

	if (isTurn) {
		//左右反転描画
		DrawTurnGraph(DrawPosition.x, DrawPosition.y, handle[currentAnim.first + imageNum], TRUE);
	}
	else {
		//通常の描画
		DrawGraph(DrawPosition.x, DrawPosition.y, handle[currentAnim.first + imageNum], TRUE);
	}
	
	DrawCollider();
}

//衝突時の処理
void Mario::OnCollision(const CollideResult& result_) {
	
	//ブロックの上に立っていれば
	if (result_.GetCollideObject().GetTag() == "Block" && result_.IsBottomCollide()) {
		isJump = false;
		isGround = true;
	}
	//敵オブジェクトに衝突すれば
	else if (result_.GetCollideObject().GetTag() == "Enemy" 
		&& (result_.IsLeftCollide() || result_.IsRightCollide() || result_.IsUpCollide())) {
		isDamage = true;
	}
	else if (result_.GetCollideObject().GetTag() == "Mashroom") {
		ChangeState(StateType::SUPER);
	}
	else if (result_.GetCollideObject().GetTag() == "FireFlower") {
		ChangeState(StateType::FIRE);
	}

}

//移動処理
bool Mario::Move() {
	static float timer = 0.0f;
	bool isMove = false;
	scrollValue = Vector2::ZERO;

	//座標移動処理
	if (Input::GetInstance().GetInputDirectionButtonLeft()) {
		moveSpeed--;
		
		ChangeAnim(run);
		isTurn = true;
		isMove = true;
	}
	else if (Input::GetInstance().GetInputDirectionButtonRight()) {
		ChangeAnim(run);
		isTurn = false;
		isMove = true;
		moveSpeed++;
	}

	
	if (abs(moveSpeed) > SPEED_LIMIT) {
		moveSpeed = moveSpeed > 0 ? SPEED_LIMIT : -SPEED_LIMIT;
	}

	//画面中央または移動量がマイナスならば
	if (position.x >= GameManager::SCREEN_WIDTH / 2 && moveSpeed > 0) {
		scrollValue.x += moveSpeed;
	}
	else {
		position.x += moveSpeed;
	}
	

	if (CheckHitKey(KEY_INPUT_M)) {
		ChangeAnim(run);
		isMove = true;
	}

	//移動入力が無ければ
	if (!isMove) {
		if (moveSpeed != 0) {
			//移動量を減少させる
			if (moveSpeed > 0) {
				moveSpeed-= 3;
				if (moveSpeed < 0) {
					moveSpeed = 0;
				}
			}
			else if (moveSpeed < 0) {
				moveSpeed+=3;
				if (moveSpeed > 0) {
					moveSpeed = 0;
				}
			}
		}
	}

	return isMove;
}

//ジャンプ処理
bool Mario::Jump() {
	static int jumpPower = 0;

	if (Input::GetInstance().GetInputLeftButton() && !isJump) {
		jumpPower = -JUMP_POWER;
		isJump = true;
	}

	if (isJump && jumpPower != 0) {
		ChangeAnim(jump);
		position.y += jumpPower;
		jumpPower++;
		return true;
	}
	else if (isJump && jumpPower >= 0) {
		position.y += 4;
	}

	return false;
}

//しゃがみ処理
bool Mario::Squat() {

	if (Input::GetInstance().GetInputDirectionButtonDown() && currentState->GetTag() != "Normal") {
		int width = 0;
		int height = 0;
		GetGraphSize(handle[0], &width, &height);
		length = Vector2(width, height / 2);
		DrawPosition.y -= length.y;
		currentAnim = squat;
		return true;
	}

	return false;
}

//形態遷移処理
void Mario::ChangeState(StateType state_tag) {
	
	if (state_tag == StateType::NORMAL) {
		if (currentState->GetTag() != "Normal") {
			position.y += 25;
		}
		delete currentState;
		currentState = new NormalState(*this);
	}
	else if (state_tag == StateType::SUPER) {
		if (currentState->GetTag() == "Normal") {
			position.y -= 35;
		}
		delete currentState;
		currentState = new SuperState(*this);
	}
	else if (state_tag == StateType::FIRE) {
		if (currentState->GetTag() == "Normal") {
			position.y -= 35;
		}
		delete currentState;
		currentState = new FireState(*this);
	}
	currentState->GetImageHandle(handle);
	//形態遷移後の大きさに合わせたColliderのサイズにする
	GetGraphSize(handle[0], &length.x, &length.y);
}

//アニメーション遷移処理
void Mario::ChangeAnim(std::pair<int, int> anim_) {
	//現在のアニメーションと変更後が同じなら処理を抜ける
	if (currentAnim == anim_) {
		return;
	}

	//アニメーションを変更
	if (currentAnim == squat) {
		position.y -= 35;
		GetGraphSize(handle[currentAnim.first], &length.x, &length.y);
	}
	currentAnim = anim_;
	imageNum = 0;
	
}

//アニメーション再生処理
void Mario::PlayAnimation() {
	static float timer = 0.0f;
	static bool isAdd = true;
	timer += FPSManager::GetInstance()->GetDeltaTime();

	if (timer >= animInterval) {
		imageNum++;
		if (imageNum >= currentAnim.second) {
			imageNum = 0;
		}
		timer = 0.0f;
	}
}