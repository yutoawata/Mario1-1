#pragma once
#include "..\..\BaseClass\StateBase.h"

template<class Holder>
class SuperState : public StateBase<Holder> {
	//メンバ関数
public:
	//コンストラクタ
	SuperState(Holder& holder);
	//デストラクタ
	~SuperState();

	//更新処理
	StateBase<Holder>* Update() override;

private:

};
