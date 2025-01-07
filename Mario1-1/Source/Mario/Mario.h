#pragma once
#include <vector>
#include <utility>
#include "../BaseClass/StateBase.h"
#include "../BaseClass/ObjectBase.h"
#include "../Input/Input.h"

class Mario : public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	Mario(Vector2 position_);
	//デストラクタ
	~Mario();

	int* GetHandle() { return handle; }
	bool IsDamage() const { return isDamage; }

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
	static int scrollValue;
private:
	int handle[9];
	//アニメーション画像の番号(first:アニメーションの先頭要素番号/second:画像枚数)
	std::pair<int, int> currentAnim;	//現在のアニメーション情報
	std::pair<int,int> idle  = { 0, 1 };//待機状態の情報
	std::pair<int, int> run  = { 3, 3 };//走行状態の情報
	std::pair<int, int> jump = { 1, 1 };//ジャンプ状態の情報
	std::pair<int, int> die  = { 2, 1 };//ゲームオーバー状態の情報
	std::pair<int, int> goal = { 6, 2 };//ゲームクリア状態の情報
	StateBase<Mario>* currentState = nullptr;
	int animationValue = 0;
	int imageNum = 0;
	int moveSpeed = 10;
	bool isJump = false;
	bool isDamage = false;
};