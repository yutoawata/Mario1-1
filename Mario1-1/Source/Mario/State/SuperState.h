#pragma once
#include "..\..\BaseClass\StateBase.h"

class SuperState : public StateBase {
	//メンバ関数
public:
	//コンストラクタ
	SuperState(Mario& holder);
	//デストラクタ
	~SuperState();

	//更新処理
	void Update() override;

private:
	std::pair<int, int> squat = { 8, 1 };//しゃがみ状態のアニメーション情報
};
