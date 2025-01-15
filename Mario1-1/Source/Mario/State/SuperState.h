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
	StateBase* ChangeState(std::string item_type) override;
	void Update() override;

	const std::string needItem = "Mathroom";
private:
};
