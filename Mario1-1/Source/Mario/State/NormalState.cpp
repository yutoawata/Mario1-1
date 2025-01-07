#include "NormalState.h"
#include "../../ManagerClass/FPSManager.h"
#include "..\Mario.h"

template class NormalState<Mario>;

//コンストラクタ
template<class Holder>
NormalState<Holder>::NormalState(Holder& holder_)
	: StateBase<Holder>(holder_, holder_.GetHandle()) {}

//デストラクタ
template<class Holder>
NormalState<Holder>::~NormalState() {}

//更新処理
template<class Holder>
StateBase<Holder>* NormalState<Holder>::Update() {
	if (this->holder.IsDamage()) {
		delete this;
		return nullptr;
	}

	return this;
}