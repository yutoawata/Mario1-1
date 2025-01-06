#pragma once
#include "..\..\BaseClass\StateBase.h"

class BigState : public StateBase {
	//メンバ関数
public:
	//コンストラクタ
	BigState();
	//デストラクタ
	~BigState();

	//更新処理
	void Update();
	//描画処理
	void Draw();

private:

};
