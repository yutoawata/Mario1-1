#include "NormalState.h"
#include "../../ManagerClass/FPSManager.h"
#include "FireState.h"

//コンストラクタ
NormalState::NormalState(Mario& holder_)
	: StateBase(holder_, holder_.normalImageHandle, "Normal") {}

//デストラクタ
NormalState::~NormalState() {}

//更新処理
void NormalState::Update() {
	currentAnim = holder.GetAnim();
}