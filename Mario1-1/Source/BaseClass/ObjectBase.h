#pragma once
#include <vector>
#include "..\Math\Vector2.h"
#include "..\Collider\BoxCollider.h"
#include "..\Collider\CollideResult.h"

class CollideResult;

class ObjectBase : public BoxCollider {
	//
public:
	//コンストラクタ
	ObjectBase(Vector2 position_, int image_handle, std::string tag_ = "");
	ObjectBase(Vector2 position_, std::string tag_, int width, int height);
	//デストラクタ
	virtual ~ObjectBase();

	//アクセサ

	Vector2 GetPosition() const { return position; }
	bool IsVisible() const { return isVisible; }
	bool IsActive() const { return isActive; }

	//更新処理
	virtual void Update() = 0;
	//描画処理
	virtual void Draw() = 0;
	//衝突時の処理
	virtual void OnCollision(const CollideResult& result_);

	//メンバ変数
protected:
	Vector2 position;	//原点座標(矩形の左上)
	bool isVisible;		//描画フラグ
	bool isActive;		//活性化フラグ
};