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

	void ViewDataDebug();


private:

	void LoadMapData(); // マップデータの読み取り

	// メンバ定数
	const std::string mapPath = "Resource/mario_1-1_mapdata.csv";
	const int MAP_SIZE_X = 213;
	const int MAP_SIZE_Y = 15;
	const int BLOCK_SIZE = 32;

	// メンバ変数
	int* mapData = new int[MAP_SIZE_X * MAP_SIZE_Y];
	int mapDataHandle;
	std::string viewNum;
};