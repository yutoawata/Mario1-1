#pragma once
#include "..\BaseClass\\ItemBlockBase.h"

class BrickBlock : public ItemBlockBase
{
public:
	// メンバ関数

	BrickBlock(int* handle_, Vector2 position_, ItemType item_type, int item_value = 1); // コンストラクタ
	~BrickBlock(); // デストラクタ
	void Update() override; // 更新処理
	void Draw() override; // 描画処理

private:
	// メンバ定数

	static const int HANDLE_VALUE = 2; // 画像の枚数

	// メンバ変数
	
	int* imageHandles; // 画像ハンドルの保存変数
	int handleID; // 描画する画像ハンドル番号
    float timer; // 画像切り替えのタイマー
};