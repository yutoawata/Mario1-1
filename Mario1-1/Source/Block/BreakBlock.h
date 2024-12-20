#pragma once
#include "..\BaseClass\\BlockBase.h"

class BreakBlock : public BlockBase
{
public:
	// メンバ関数
	BreakBlock(Vector2 position_, int handle_); // コンストラクタ
	~BreakBlock(); // デストラクタ
	void Draw() override; // 描画処理
	void OnCollision(const CollideResult& result_) override; // 衝突時の処理

private:

	// メンバ変数
	int imageHandle; // 画像ハンドル
};
