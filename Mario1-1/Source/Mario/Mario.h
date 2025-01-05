#pragma once
#include "..\BaseClass\ObjectBase.h"
#include "..\Input\Input.h"

class Mario : public ObjectBase {
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

	static const int JUMP_PEWER = 10;
private:
	int moveSpeed;
};