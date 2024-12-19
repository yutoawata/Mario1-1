#pragma once
#include "..\BaseClass\SceneBase.h"
#include "..\Map\Map.h"

class DebugScene_Itou : public SceneBase {
public:
	// メンバ関数

	DebugScene_Itou(); // コンストラクタ
	~DebugScene_Itou(); // デストラクタ

	SceneBase* Update() override;

	void Draw() override;

private:
	// メンバ変数
	Map *map = new Map();

};