#include "SuperState.h"
#include "NormalState.h"
#include "../Mario.h"

template class SuperState<Mario>;

//コンストラクタ
template<class Holder>
SuperState<Holder>::SuperState(Holder& holder_)
	: StateBase<Holder>(holder_, holder_.GetHandle()) {

}

//デストラクタ
template<class Holder>
SuperState<Holder>::~SuperState() {}

//更新処理
template<class Holder>
StateBase<Holder>* SuperState<Holder>::Update() {
	if (this->holder.IsDamage()) {
		Holder& h = this->holder;
		delete this;
		return new NormalState<Holder>(h);
	}

	return this;
}