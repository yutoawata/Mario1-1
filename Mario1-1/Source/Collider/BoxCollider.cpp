#include "BoxCollider.h"
#include "..\ManagerClass\ObjectManager.h"

//コンストラクタ(画像素材の大きさ)
BoxCollider::BoxCollider(Vector2& left_up_posision, int graph_hndle, std::string tag_)
	: leftUpPosition(left_up_posision), moveVector(Vector2::ZERO), tag(tag_) {
	//コライダーの大きさを画像サイズに合わせる
	GetGraphSize(graph_hndle, &length.x, &length.y);
}

//コンストラクタ(画像無し)
BoxCollider::BoxCollider(Vector2& center_position, int width_, int height_, std::string tag_)
	: leftUpPosition(center_position), moveVector(Vector2::ZERO), length(Vector2(width_, height_)), tag(tag_) {}


//デストラクタ
BoxCollider::~BoxCollider() {}

void BoxCollider::DrawCollider() {
	Vector2 rightBottomPosition = leftUpPosition + length;
	DrawFillBox(leftUpPosition.x, leftUpPosition.y, rightBottomPosition.x, rightBottomPosition.y, GetColor(255, 0, 0));
	DrawCircle(GetLeftUpPosition().x, GetLeftUpPosition().y, 10, GetColor(255, 255, 255), TRUE);
	DrawCircle(GetRightBottomPosition().x, GetRightBottomPosition().y, 10, GetColor(255, 255, 255), TRUE);
}

//衝突処理
bool BoxCollider::Collide(BoxCollider& other_) {
	//移動量を算出
	moveVector = leftUpPosition - latePosition;
	bool isCollide = false;
	//ブロックをすり抜けないため衝突しない場所まで戻す
	if (tag != "Block" && other_.GetTag() == "Block") {
		Vector2 checkPosition = latePosition + Vector2(moveVector.x, 0);
		BoxCollider checkCollider = BoxCollider(checkPosition, length.x, length.y, tag);
		
		//左右方向の移動量で当たり判定を行う
		if (ObjectManager::CheckCollision(checkCollider, static_cast<const BoxCollider&>(other_))) {
			//衝突していれば移動量を引く
			leftUpPosition.x -= moveVector.x;
			isCollide = true;
		}

		checkPosition = latePosition + Vector2(0, moveVector.y);
		//上下方向の移動量で当たり判定を行う
		if (ObjectManager::CheckCollision(checkCollider, static_cast<const BoxCollider&>(other_))) {
			//衝突していれば移動量を引く
			leftUpPosition.y -= moveVector.y;
			isCollide = true;
		}
	}
	else {
		if (ObjectManager::CheckCollision(*this, static_cast<const BoxCollider&>(other_))) {
			isCollide = true;
			DrawString(150, 0, "Collide", GetColor(255, 255, 255));
		}
	}
	//移動前の座標を更新
	latePosition = leftUpPosition;
	return isCollide;
}