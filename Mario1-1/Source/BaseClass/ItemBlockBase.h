#pragma once
#include "BlockBase.h"
#include "..\Item\ItemType.h"

class ItemBlockBase : public BlockBase
{
public:
	// メンバ関数

	ItemBlockBase(int* handle_,Vector2 position_, ItemType item_type, int item_value); // コンストラクタ
	~ItemBlockBase(); // デストラクタ
	void OnCollision(const CollideResult& result_) override; // 衝突時の処理

private:
	// メンバ関数
	void CreateItem(); // アイテムの生成


protected:
	// メンバ変数

	ItemType itemType; // アイテムの種類の格納
	int itemValue; // アイテムの生成個数
};