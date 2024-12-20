#pragma once
#include "ObjectBase.h"

class BlockBase : public ObjectBase
{
public:
	// メンバ関数
	BlockBase(Vector2 position_, int handle_); // コンストラクタ
	~BlockBase(); // デストラクタ
	void Update() override; // 更新処理

private:
	// メンバ関数
	void Move(); // スクロール処理

	// メンバ定数
	const std::string TAG = "Block"; // Object識別用のタグ

};