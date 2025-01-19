#pragma once
#include "../../BaseClass/ObjectBase.h"

class FireBall : public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	FireBall();
	//デストラクタ
	~FireBall();

	//更新処理
	void Update() override;
	//描画処理
	void Draw() override;
};