#pragma once
#include "..\BaseClass\\ItemBlockBase.h"
#include "..\ManagerClass\FPSManager.h"

class BrickBlock : public ItemBlockBase
{
public:
	// メンバ関数

	BrickBlock(int* handle_, Vector2 position_, ItemType item_type, int item_value = 1, bool is_visible); // コンストラクタ
	~BrickBlock(); // デストラクタ
	void Update() override; // 更新処理
	void Draw() override; // 描画処理

private:
	// メンバ定数

	static const int HANDLE_VALUE = 2; // 画像の枚数

	// メンバ変数
	int* imageHandles; // 画像ハンドルの保存変数
	bool isVisible; // 通常時の描画フラグ
};