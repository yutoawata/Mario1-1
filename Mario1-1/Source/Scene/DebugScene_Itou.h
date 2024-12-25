#pragma once
#include "..\BaseClass\SceneBase.h"
#include "..\Map\Map.h"
#include "..\Block\BrickBlock.h"
class DebugScene_Itou : public SceneBase {
public:
	// メンバ関数

	DebugScene_Itou(); // コンストラクタ
	~DebugScene_Itou(); // デストラクタ

	SceneBase* Update() override;

	void Draw() override;

private:

	int debughandle[4]

	BrickBlock* brickblock = new BrickBlock()

};