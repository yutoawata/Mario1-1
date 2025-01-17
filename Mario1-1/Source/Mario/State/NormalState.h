#pragma once
#include "../../BaseClass/StateBase.h"

class NormalState : public StateBase {
	//メンバ関数
public:
	//コンストラクタ
	NormalState(Mario& holder_);
	//デストラクタ
	~NormalState();

	static void SetUpImageHandle();

	//更新処理
	StateBase* ChangeState(std::string item_type) override;
	void Update() override;

private:
};