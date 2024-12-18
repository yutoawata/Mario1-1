#pragma once
#include "..\BaseClass\ObjectBase.h"
#include<vector>
#include<string>

class Block : public ObjectBase
{
public:
	enum class InItem
	{
		NONE,
		MUSHROOM,
		ONEUP_MASHROOM,
		FIRE_FLOWER,
		STAR
	};

	// メンバ関数

	Block(Vector2 position_,std::vector<int> handle_,bool can_break); // コンストラクタ(アイテムなし) 
	Block(Vector2 position_,std::vector<int> handle_, InItem type_, int value_); // コンストラクタ(アイテムあり)
	~Block(); // デストラクタ
	void Update() override; // 更新処理
	void Draw() override; // 描画処理
	// 移動
	// プレイヤーと接触
	
private:
	// メンバ定数
	static const std::string TAG;

	// メンバ変数

	InItem inItem; // 中に入っているアイテムの種類
	int itemValue; // アイテムの個数
	bool canBreak; // 壊れるか壊れないかのフラグ


};