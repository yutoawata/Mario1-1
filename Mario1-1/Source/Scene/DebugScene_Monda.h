#pragma once
#include "..\BaseClass\SceneBase.h"

class DebugScene_Monda : public SceneBase {
	//メンバ関数
public:
	//コンストラクタ
	DebugScene_Monda();
	//デストラクタ
	~DebugScene_Monda();

	SceneBase* Update() override;

	void Draw() override;

	//メンバ変数
private:
};