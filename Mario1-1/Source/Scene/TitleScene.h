#pragma once
#include "..\BaseClass\SceneBase.h"

class TitleScene : public SceneBase {
	//メンバ関数
public:
	//コンストラクタ
	TitleScene();
	//デストラクタ
	~TitleScene();

	//更新処理
	SceneBase* Update() override;
	//描画処理
	void Draw() override;
};