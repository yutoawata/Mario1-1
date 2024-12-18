#pragma once
#include <string>
#include "..\BaseClass\ObjectBase.h"

class ObjectBase;

class CollideResult {
	//メンバ関数
public:
	CollideResult(const ObjectBase& object_, std::string collideDirection);
	~CollideResult();

	//アクセサ

	const ObjectBase& GetCollideObject() const;
	//上方向からの衝突フラグを渡す
	bool IsUpCollide() const;
	//下方向からの衝突フラグを渡す
	bool IsBottomCollide() const;
	//左方向からの衝突フラグを渡す
	bool IsLeftCollide() const;
	//右方向からの衝突フラグを渡す
	bool IsRightCollide() const;

private:
	const ObjectBase& object;
	bool isUpCollide = false;
	bool isBottomCollide = false;
	bool isLeftCollide = false;
	bool isRightCollide = false;

};