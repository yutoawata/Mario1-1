#include "FireState.h"
#include "SuperState.h"
#include "..\Mario.h"

template class FireState<Mario>;

//コンストラクタ
template<class Holder>
FireState<Holder>::FireState(Holder& holder_)
	: StateBase<Holder>(holder_, holder_.GetHandle()) {}

//デストラクタ
template<class Holder>
FireState<Holder>::~FireState() {}

//更新処理
template<class Holder>
StateBase<Holder>* FireState<Holder>::Update() {
	if (this->holder.IsDamage()) {
		Holder& h = this->holder;
		delete this;
		return new SuperState<Holder>(h);
	}

	return this;
}