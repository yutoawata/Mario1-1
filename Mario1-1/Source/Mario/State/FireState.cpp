#include "FireState.h"
#include "SuperState.h"

//コンストラクタ

FireState::FireState(Mario& holder_)
	: StateBase(holder_, holder_.FireImageHandle, "Fire") {}

//デストラクタ
FireState::~FireState() {}


//更新処理
void FireState::Update() {
	currentAnim = holder.GetAnim();
	holder.Squat();
}

//
void FireState::ShrowFireBall() {
	if (Input::GetInstance().GetInputDownButton()) {

	}
}