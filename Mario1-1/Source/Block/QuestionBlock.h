#pragma once
#include "..\BaseClass\\ItemBlockBase.h"
#include "..\ManagerClass\FPSManager.h"

class QuestionBlock : public ItemBlockBase
{
public:
	// メンバ関数

	QuestionBlock(int* handle_, Vector2 position_, ItemType item_type, int item_value = 1); // コンストラクタ
	~QuestionBlock(); // デストラクタ
	void Update() override; // 更新処理
	void Draw() override; // 描画処理

private:
	// メンバ定数

	static const int HANDLE_VALUE = 4; // 画像の枚数
	static const int LOOP_TOTAL_TIME = 2; // ループにかかる時間
	static const int LOOP_PATERN_VALUE = 5; // 1回のループで変更する数

	// メンバ変数
	int loopPatern[LOOP_PATERN_VALUE] = { 0,1,2,1,0 };
	int* imageHandles; // 画像ハンドルの保存変数
	int count;
	float timer; // 画像切り替えのタイマー

	Vector2 move_val = Vector2::ZERO;
};
