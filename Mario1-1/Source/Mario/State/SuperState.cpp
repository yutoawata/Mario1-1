#include "SuperState.h"
#include "NormalState.h"
#include "../Mario.h"

//コンストラクタ
SuperState::SuperState(Mario& holder_)
	: StateBase(holder_, holder_.superImageHandle, "Super") {

}

//デストラクタ
SuperState::~SuperState() {}

//更新処理
void SuperState::Update() {
	currentAnim = holder.GetAnim();
	this->holder.Squat();
}