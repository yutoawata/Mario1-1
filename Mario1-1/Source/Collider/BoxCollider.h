#pragma once
#include <string>
#include "..\Math\Vector2.h"

class BoxCollider {
	//メンバ関数
	BoxCollider(int width_, int height_, std::string tag_, bool is_trigger = false);
	//デストラクタ
	~BoxCollider();

	void OnCollision();
	void OnTrigger();

private:
	std::string tag;	//コライダータグ
	Vector2 moveVector;	//移動ベクトル
	int width;		//横幅
	int height;		//縦幅
	bool isTrigger;		//すり抜けフラグ
};