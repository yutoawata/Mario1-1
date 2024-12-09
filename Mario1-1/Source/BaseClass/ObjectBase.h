#pragma once
#include "..\Math\Vector2.h"

class ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	ObjectBase(Vector2 position_, int image_handle);
	//デストラクタ
	virtual ~ObjectBase();

	//アクセサ

	Vector2 GetPosition() { return position; }
	bool IsVisible() { return isVisible; }

	//更新処理
	virtual void Update() = 0;
	//描画処理
	virtual void Draw() = 0;

	//メンバ変数
protected:
	Vector2 position;	//オブジェクトの中心座標
	int imageHandle;	//画像素材のハンドル
	bool isVisible;		//描画フラグ
};