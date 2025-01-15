#include "SuperState.h"
#include "NormalState.h"
#include "../Mario.h"

//コンストラクタ
SuperState::SuperState(Mario& holder_)
	: StateBase(holder_, holder_.GetHandle()) {

}

//デストラクタ
SuperState::~SuperState() {}

//更新処理
StateBase* SuperState::ChangeState(std::string item_type) {
	if (this->holder.IsDamage()) {
		Mario& h = this->holder;
		delete this;
		return new NormalState(h);
	}

	return this;
}


void SuperState::Update() {
	this->holder.Squat();
}