#pragma once
#include "../../BaseClass/StateBase.h"

class NormalState : public StateBase {
	//メンバ関数
public:
	//コンストラクタ
	NormalState(Mario& holder_);
	//デストラクタ
	~NormalState();

	//更新処理
	void Update() override;
};