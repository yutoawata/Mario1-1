#pragma once
#include <string>
#include "..\Math\Vector2.h"

class BoxCollider {
	//メンバ関数
public:
	//コンストラクタ(画像素材に合わせたサイズ)
	BoxCollider(Vector2& left_up_position, int graph_handle, std::string tag_ = "");
	//コンストラクタ(画像素材なし)
	BoxCollider(Vector2& position, int width, int height, std::string tag_ = "");
	//デストラクタ
	virtual ~BoxCollider();

	//アクセサ

	//オブジェクトの判別タグを渡す
	std::string GetTag() const { return tag; }
	//原点座標(左上)を渡す
	Vector2 GetLeftUpPosition() const { return leftUpPosition; }
	//右下の座標を渡す
	Vector2 GetRightBottomPosition() const { return leftUpPosition + length; }
	Vector2 GetLength()const { return length; }
	//横幅を渡す
	int GetWidth() const { return length.x; }
	//縦幅を渡す
	int GetHeigth() const { return length.y; }

	void DrawCollider();
	bool Collide(BoxCollider& other_);
	
	//メンバ変数
private:
	std::string tag;		//コライダータグ
	Vector2& leftUpPosition;//オブジェクトの原点座標(左上)
	Vector2 latePosition;	//移動前の座標
	Vector2 moveVector;		//移動ベクトル
	Vector2 length;			//各軸方向の幅(x:横幅, y:縦幅)
};