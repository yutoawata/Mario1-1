#include "StateBase.h"


//コンストラクタ
StateBase::StateBase(Mario& holder_, int* handle_, std::string tag_)
	: holder(holder_), tag(tag_) {
	for (int i = 0; i < imageValue; i++) {
		handle[i] = handle_[i];
		holder.GetHandle()[i] = handle_[i];
	}
	currentAnim = holder_.GetAnim();
}

//デストラクタ
StateBase::~StateBase() {}


//画像のハンドルの配列を渡す
void StateBase::GetImageHandle(int* handle_) {
	for (int i = 0; i < imageValue; i++) {
		handle_[i] = handle[i];
	}
}