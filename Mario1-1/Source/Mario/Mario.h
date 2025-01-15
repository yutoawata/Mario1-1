#pragma once
#include <vector>
#include <utility>
#include "../BaseClass/StateBase.h"
#include "../BaseClass/ObjectBase.h"
#include "../Input/Input.h"

class StateBase;

class Mario : public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	Mario(Vector2 position_);
	//デストラクタ
	~Mario();

	int* GetHandle() { return handle; }
	std::pair<int, int> GetAnim() { return currentAnim; }
	bool IsDamage() const { return isDamage; }

	//更新処理
	void Update() override;
	//判定処理後の更新処理
	void LateUpdate() override;
	//描画処理
	void Draw() override;
	//衝突時の処理
	void OnCollision(const CollideResult& result_) override;
	
	//移動処理
	void Move();
	//ジャンプ処理
	void Jump();
	//しゃがみ処理
	void Squat();
	//アニメーション再生処理
	void PlayAnimation();

	static const int JUMP_POWER = 20;	//ジャンプする力
	static int scrollValue;				//画面スクロールの移動量
private:
	int handle[9];						//画像素材のハンドルの配列
	//アニメーション画像の番号(first:アニメーションの先頭要素番号/second:画像枚数)
	std::pair<int, int> currentAnim;	//現在のアニメーション情報
	std::pair<int, int> idle  = { 0, 1 };//待機状態の情報
	std::pair<int, int> run   = { 3, 3 };//走行状態の情報
	std::pair<int, int> jump  = { 1, 1 };//ジャンプ状態の情報
	std::pair<int, int> die   = { 2, 1 };//ゲームオーバー状態の情報
	std::pair<int, int> goal  = { 6, 2 };//ゲームクリア状態の情報
	StateBase* currentState;			//現在の形態
	int imageNum = 0;					//現在再生中の画像の番号
	int moveSpeed = 10;					//移動速度
	float animInterval = 0.1f;			//アニメーションの画像切り替えの感覚
	bool isTurn = false;				//画像の左右反転フラグ
	bool isJump = false;				//ジャンプフラグ
	bool isDamage = false;				//ダメージフラグ
};