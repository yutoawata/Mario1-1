#include "NormalState.h"
#include "../../ManagerClass/FPSManager.h"
#include "FireState.h"

//コンストラクタ
NormalState::NormalState(Mario& holder_)
	: StateBase(holder_, holder_.GetHandle()) {}

//デストラクタ
NormalState::~NormalState() {}

//更新処理
StateBase* NormalState::ChangeState(std::string item_type) {
	if (this->holder.IsDamage()) {
		delete this;
		return nullptr;
	}

	if (item_type == "FireFlower") {
		Mario& holder = this->holder;
		delete this;
		return new FireState(holder);
	}
	
	return this;
}

void NormalState::Update() {
	this->currentAnim = this->holder.GetAnim();
}