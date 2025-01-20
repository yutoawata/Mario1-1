#pragma once
#include "..\BaseClass\SceneBase.h"
#include "../Move_D/DebugBlockMove.h"
#include "..\Map\Map.h"

class DebugScene_Itou : public SceneBase {
public:
	// メンバ関数

	DebugScene_Itou(); // コンストラクタ
	~DebugScene_Itou(); // デストラクタ

	SceneBase* Update() override; // 更新処理
	void Draw() override; // 描画処理

private:

	DebugBlockMove* debugBlockMove = new DebugBlockMove();
	Map* map = new Map();
};