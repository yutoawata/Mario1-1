#pragma once
#include "..\BaseClass\SceneBase.h"

class DebugScene_Itou : public SceneBase {
	//メンバ関数
public:
	//コンストラクタ
	DebugScene_Itou();
	//デストラクタ
	~DebugScene_Itou();

	SceneBase* Update() override;

	void Draw() override;

	//メンバ変数
private:
};