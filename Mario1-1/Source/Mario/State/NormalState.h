#pragma once
#include "../../BaseClass/StateBase.h"

template<class Holder>
class NormalState : public StateBase<Holder> {
	//メンバ関数
public:
	//コンストラクタ
	NormalState(Holder& holder_);
	//デストラクタ
	~NormalState();

	//更新処理
	StateBase<Holder>* Update() override;

private:
};