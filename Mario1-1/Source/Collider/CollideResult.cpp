#include "CollideResult.h"

CollideResult::CollideResult(const ObjectBase& object_, std::string collideDirection) 
	: object(object_) {
	if (collideDirection == "上") {
		isUpCollide = true;
	}
	else if (collideDirection == "下") {
		isBottomCollide = true;
	}
	else if (collideDirection == "左") {
		isLeftCollide = true;
	}
	else if (collideDirection == "右") {
		isRightCollide = true;
	}
}

CollideResult::~CollideResult() {}

//衝突相手を渡す
const ObjectBase& CollideResult::GetCollideObject() const { return object; }
//上方向からの衝突フラグを返す
bool CollideResult::IsUpCollide() const { return isUpCollide; }
//下方向からの衝突フラグを返す
bool CollideResult::IsBottomCollide() const { return isBottomCollide; }
//左方向からの衝突フラグを返す
bool CollideResult::IsLeftCollide() const { return isLeftCollide; }
//右方向からの衝突フラグを返す
bool CollideResult::IsRightCollide() const { return isRightCollide; }