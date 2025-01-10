#pragma once
#include "DxLib.h"
#include "../Item/ItemType.h"
#include "../ManagerClass/ImageManager.h"
#include "../Block/NormalBlock.h"
#include "../Block/BreakBlock.h"
#include "../Block/BrickBlock.h"
#include "../Block/QuestionBlock.h"


class Map
{
public:

	// メンバ関数

	Map(); // コンストラクタ
	~Map(); // デストラクタ
	void CreateMap(); // マップの生成

private:

	// メンバ関数

	void LoadMapData(); // マップデータの読み取り


	// メンバ定数
	const int MAP_SIZE_X = 213; // 横のブロック数
	const int MAP_SIZE_Y = 30;  // 縦のブロック数
	const int BLOCK_SIZE = 32;  // １ブロックのサイズ

	// メンバ変数

	int* mapData = new int[MAP_SIZE_X * MAP_SIZE_Y]; // マップデータ保存配列
	int mapDataHandle; // マップデータのハンドル
};