#include "StateBase.h"
#include "../Mario/Mario.h"

template class StateBase<Mario>;

//コンストラクタ
template<class Holder>
StateBase<Holder>::StateBase(Holder& holder_, int* handle_)
	: holder(holder_){
	for (int i = 0; i < imageValue; i++) {
		handle[i] = handle_[i];
		holder.GetHandle()[i] = handle_[i];
	}
}

//デストラクタ
template<class Holder>
StateBase<Holder>::~StateBase() {}


//
template<class Holder>
void StateBase<Holder>::GetImageHandle(int* handle_) {
	for (int i = 0; i < imageValue; i++) {
		handle_[i] = handle[i];
	}
}