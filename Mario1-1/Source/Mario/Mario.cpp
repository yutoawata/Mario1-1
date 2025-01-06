#include "Mario.h"

//コンストラクタ
Mario::Mario(Vector2 position_)
	: ObjectBase(position_, 1, "Mario")
	, moveSpeed(2) {
	length = Vector2(50, 50);
	LoadDivGraph("..\..\Resouce\Image\NormalMario.png", 9, 3, 3, 32, 64, handle);
}

//デストラクタ
Mario::~Mario() {}

//更新処理
void Mario::Update() {
	currentAnim = idle;
	Move();

	position.y += 1;
}

//描画処理
void Mario::Draw() {
	for (int i = 0; i < currentAnim.second; i++) {
		DrawGraph(position.x, position.y, handle[currentAnim.first + i], TRUE);
	}
	
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
	if (Input::GetInstance().GetInputDirectionButtonLeft()) {
		position.x -= moveSpeed;
		currentAnim = run;
	}
	else if (Input::GetInstance().GetInputDirectionButtonRight()) {
		position.x += moveSpeed;
		currentAnim = run;
	}
}

//ジャンプ処理
void Mario::Jump() {
	static int jumpPower = 0;

	if (Input::GetInstance().GetInputLeftButton() && !isJump) {
		jumpPower = JUMP_POWER;
	}

	if (isJump) {
		position.y += jumpPower;
		jumpPower--;
	}
	

}