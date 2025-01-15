#include "FireState.h"
#include "SuperState.h"

//コンストラクタ

FireState::FireState(Mario& holder_)
	: StateBase(holder_, holder_.GetHandle()) {}

//デストラクタ
FireState::~FireState() {}

//更新処理
StateBase* FireState::ChangeState(std::string item_type) {
	//ダメージによる形態遷移
	if (this->holder.IsDamage()) {
		Mario& h = this->holder;
		delete this;
		return new SuperState(h);
	}

	return this;
}


void FireState::Update() {
	holder.Squat();
}