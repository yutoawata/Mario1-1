#pragma once
#include "DxLib.h"
#include <stdio.h>
#include <vector>
#include <string>


class Map
{
public:

	// メンバ関数

	Map(); // コンストラクタ
	~Map(); // デストラクタ
	void ViewDataDebug(); // マップデータ表示(デバッグ用)


private:

	void LoadMapData(); // マップデータの読み取り

	// メンバ定数
	const std::string mapPath = "Resource/mario_1-1_mapdata.csv"; // マップデータのファイルパス
	const int MAP_SIZE_X = 213; // 横のブロック数
	const int MAP_SIZE_Y = 15;  // 縦のブロック数
	const int BLOCK_SIZE = 32;  // １ブロックのサイズ

	// メンバ変数
	int* mapData = new int[MAP_SIZE_X * MAP_SIZE_Y]; // マップデータ保存配列
	int mapDataHandle; // マップデータのハンドル
};