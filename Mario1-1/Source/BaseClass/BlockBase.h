#pragma once
#include "ObjectBase.h"
#include "../Move_D/DebugBlockMove.h"
#include "../Mario/Mario.h"

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

	DebugBlockMove* debugMoveBlock = new DebugBlockMove();

	Vector2 move_val; // 移動量
};