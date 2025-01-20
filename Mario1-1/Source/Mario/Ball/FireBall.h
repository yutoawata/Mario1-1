#pragma once
#include "../../BaseClass/ObjectBase.h"
#include "../../ManagerClass/FPSManager.h"

class FireBall :public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	FireBall(Vector2 position_, bool isFront);
	//デストラクタ
	~FireBall();

	//更新処理
	void Update() override;
	//描画処理
	void Draw() override;
	//衝突時の処理
	void OnCollision(const CollideResult& result_) override;
	//移動処理
	void Move();
	//アニメーション再生処理
	void PlayAnimation();

	//メンバ変数
private:
	static const float animInterval;	//アニメーション画像の切り替え間隔
	static const float upInterval;		//上昇と下降の切り替え間隔
	int handle[6];
	//アニメーション情報(first:アニメーションの先頭要素番号  second:アニメーションの画像数)
	std::pair<int, int> currentAnim;		//現在再生中のアニメーション情報
	std::pair<int, int> move = { 0, 4 };	//移動時のアニメーション情報
	std::pair<int, int> hit = { 4, 2 };		//着弾時のアニメーション情報
	//-------------------------------------------------------------------------------------
	int frontPower = 3;		//前に進む力
	int upPower = 3;		//上に進む力
	int imageNum = 0;		//アニメーション画像の枚数
	float animTimer = 0.0f;	//アニメーション再生時間タイマー
	float upTimer = 0.0f;	//上昇時間のタイマー
	bool isFront = false;	//前方進行フラグ
	bool isUp = false;		//上昇フラグ
};