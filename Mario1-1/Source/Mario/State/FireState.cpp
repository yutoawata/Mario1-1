#include "FireState.h"
#include "SuperState.h"

//コンストラクタ

FireState::FireState(Mario& holder_)
	: StateBase(holder_, ImageManager::GetFiremarioHandle(), "Fire") {}

//デストラクタ
FireState::~FireState() {}


//更新処理
void FireState::Update() {
	currentAnim = holder.GetAnim();
}

//
void FireState::ShrowFireBall() {
	if (Input::GetInstance().GetInputDownButton()) {

	}
}