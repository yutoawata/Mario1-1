#pragma once
#include <vector>
#include <utility>
#include "..\BaseClass\ObjectBase.h"
#include "..\Input\Input.h"

class Mario : public ObjectBase {
	//列挙型
	enum class Animation {
		IDLE,	//待機状態
		RUN,	//走行状態
		JUMP,	//ジャンプ状態
		DIE,	//ゲームオーバー状態
		GOAL	//ゴール状態
	};
	struct AnimInfo {
		std::string name;	//アニメーション名
		int firstID;		//最初のアニメーション画像の配列番号
		int value;			//アニメーション画像の枚数
	};
	//メンバ関数
public:
	//コンストラクタ
	Mario(Vector2 position_);
	//デストラクタ
	~Mario();

	//更新処理
	void Update() override;
	//描画処理
	void Draw() override;
	//衝突時の処理
	void OnCollision(const CollideResult& result_) override;
	//移動処理
	void Move();
	//ジャンプ処理
	void Jump();

	static const int JUMP_POWER = 10;
private:
	//アニメーション画像の番号(first:アニメーションの先頭要素番号/second:画像枚数)
	std::pair<int, int> currentAnim;	//現在のアニメーション情報
	std::pair<int,int> idle  = { 0, 1 };//
	std::pair<int, int> run  = { 3, 3 };
	std::pair<int, int> jump = { 1, 1 };
	std::pair<int, int> die  = { 2, 1 };
	std::pair<int, int> goal = { 6, 2 };
	int* handle;
	int animationValue = 0;
	int moveSpeed;
	bool isJump = false;
};