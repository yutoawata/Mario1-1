#include "FireBall.h"

const float FireBall::animInterval = 0.5f;
const float FireBall::upInterval = 1.0f;

//コンストラクタ
FireBall::FireBall(Vector2 position_, bool is_front)
	: ObjectBase(Vector2::ZERO, handle[0], "FireBall") {
	position = position_;
	isFront = is_front;
}

//デストラクタ
FireBall::~FireBall() {}

//更新処理
void FireBall::Update() {
	static float timer = 0.0f;

	if (isUp) {
		timer += FPSManager::GetInstance()->GetDeltaTime();
		if (timer >= upInterval) {
			isUp = false;
			timer = 0.0f;
		}
	}

	PlayAnimation();
}

//描画処理
void FireBall::Draw() {
	DrawGraph(position.x, position.y, handle[currentAnim.first + imageNum], TRUE);
}

//衝突時の処理
void FireBall::OnCollision(const CollideResult& result_) {
	if (result_.GetCollideObject().GetTag() == "Block") {
		isUp = true;
	}
}

void FireBall::Move() {

	position.x += isFront ? frontPower : -frontPower;
	position.y += isUp ? -upPower : upPower;
}

//アニメーション再生処理
void FireBall::PlayAnimation() {
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