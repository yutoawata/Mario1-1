#pragma once
#include "../../BaseClass/StateBase.h"


class FireState : public StateBase {
	//メンバ関数
public:
	//コンストラクタ
	FireState(Mario& holder_);
	//デストラクタ
	~FireState();

	//更新処理
	void Update() override;
	//攻撃アクション
	void ShrowFireBall();

private:
	std::pair<int, int> squat = {8, 1};//しゃがみ状態のアニメーション情報
};