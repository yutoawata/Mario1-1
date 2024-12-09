#pragma once
#include "..\BaseClass\SceneBase.h"

class PlayScene : public SceneBase {
	//メンバ関数
public:
	//コンストラクタ
	PlayScene();
	//デストラクタ
	~PlayScene();

	//更新処理
	SceneBase* Update() override;
	//描画処理
	void Draw() override;
};