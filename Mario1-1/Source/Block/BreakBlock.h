#pragma once
#include "..\BaseClass\\BlockBase.h"

class BreakBlock : public BlockBase
{
public:
	// メンバ関数
	BreakBlock(); // コンストラクタ
	~BreakBlock(); // デストラクタ
	void Update() override; // 更新処理
	void Draw() override; // 描画処理
	void OnCollision(const CollideResult& result_) override; // 衝突時の処理

private:

	// メンバ変数
	int imageHandle; // 画像ハンドル
};
