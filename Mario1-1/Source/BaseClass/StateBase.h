#pragma once
#include <utility>
#include <string>
#include "..\Mario\Mario.h"

class Mario;

class StateBase {
	//メンバ関数
public:
	//コンストラクタ
	StateBase(Mario& holder_, int* handle_);
	//デストラクタ
	virtual ~StateBase();

	//アクセサ

	void GetImageHandle(int* handle_);
	std::pair<int, int> GetCurrentAnim() { return currentAnim; }

	virtual StateBase* ChangeState(std::string item_type) = 0;
	virtual void Update() = 0;

private:
	static const int imageValue = 9;
protected:
	
	int handle[9];
	Mario& holder;
	//アニメーション画像の番号(first:アニメーションの先頭要素番号/second:画像枚数)
	std::pair<int, int> currentAnim;	//現在のアニメーション情報
};