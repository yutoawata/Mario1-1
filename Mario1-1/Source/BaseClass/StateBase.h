#pragma once
#include <utility>

template<class Holder>
class StateBase {
	//メンバ関数
public:
	//コンストラクタ
	StateBase(Holder& holder_, int* handle_);
	//デストラクタ
	virtual ~StateBase();

	//アクセサ

	void GetImageHandle(int* handle_);
	std::pair<int, int> GetCurrentAnim() { return currentAnim; }

	virtual StateBase* Update() = 0;

private:
	static const int imageValue = 9;
protected:
	
	int handle[9];
	Holder& holder;
	//アニメーション画像の番号(first:アニメーションの先頭要素番号/second:画像枚数)
	std::pair<int, int> currentAnim;	//現在のアニメーション情報
	std::pair<int, int> idle = { 0, 1 };//待機状態の情報
	std::pair<int, int> run  = { 3, 3 };//走行状態の情報
	std::pair<int, int> jump = { 1, 1 };//ジャンプ状態の情報
	std::pair<int, int> die  = { 2, 1 };//ゲームオーバー状態の情報
	std::pair<int, int> goal = { 6, 2 };//ゲームクリア状態の情報
};