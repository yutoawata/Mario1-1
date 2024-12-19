#pragma once
#include "..\BaseClass\BlockBase.h"

class NormalBlock : public BlockBase
{
public:
	// メンバ関数
	NormalBlock(Vector2 position_,int handle_); // コンストラクタ
	~NormalBlock(); // デストラクタ
	void Draw() override; // 描画処理

private:

	// メンバ変数
	int imageHandle;
};