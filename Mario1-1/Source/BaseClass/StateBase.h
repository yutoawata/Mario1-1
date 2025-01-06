#pragma once
#include <utility>

class StateBase {
	//メンバ関数
public:
	//コンストラクタ
	StateBase(int* handle_);
	//デストラクタ
	~StateBase();

	//アクセサ
	std::pair<int, int> GetCurrentAnim() { return currentAnim; }

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	const int* const handle;
	std::pair<int, int> currentAnim;

};