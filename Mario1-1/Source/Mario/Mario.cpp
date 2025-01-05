#include "Mario.h"

//コンストラクタ
Mario::Mario(Vector2 position_)
	: ObjectBase(position_, 1, "Mario")
	, moveSpeed(2) {
	length = Vector2(50, 50);
}

//デストラクタ
Mario::~Mario() {}

//更新処理
void Mario::Update() {
	Move();

	position.y += 1;
}

//描画処理
void Mario::Draw() {
	DrawFillBox(position.x, position.y, position.x + length.x, position.y + length.y, GetColor(255, 0, 0));
}

//衝突時の処理
void Mario::OnCollision(const CollideResult& result_) {

}

//移動処理
void Mario::Move() {
	if (Input::GetInstance().GetInputDirectionButtonLeft()) {
		position.x -= moveSpeed;
	}
	else if (Input::GetInstance().GetInputDirectionButtonRight()) {
		position.x += moveSpeed;
	}
}

//ジャンプ処理
void Mario::Jump() {
	static bool isJump = false;

	
}