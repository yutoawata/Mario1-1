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
	StateBase* ChangeState(std::string item_type) override;
	void Update() override;
	
private:

};