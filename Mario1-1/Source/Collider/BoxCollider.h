#pragma once
#include <string>
#include "..\Math\Vector2.h"
#include"..\BaseClass\ObjectBase.h"

class ObjectBase;

class BoxCollider {
	//メンバ関数
public:
	//コンストラクタ(画像素材に合わせたサイズ)
	BoxCollider(int graph_handle, std::string tag_ = "", bool is_trigger = false);
	//コンストラクタ(画像素材なし)
	BoxCollider(Vector2 position, int width, int height, std::string tag_ = "", bool is_trigger = false);
	//デストラクタ
	virtual ~BoxCollider();

	//アクセサ
	bool IsTrigger() { return isTrigger; }

	void OnCollision(const ObjectBase& other_);
	void OnTrigger(const ObjectBase& other_);

private:
	std::string tag;	//コライダータグ
	Vector2 moveVector;	//移動ベクトル
	Vector2 length;
	bool isTrigger;		//すり抜けフラグ
};