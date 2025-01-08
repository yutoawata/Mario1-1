#include "Map.h"

Map::Map()
{
	LoadMapData();
}

Map::~Map()
{
	delete[] mapData;
}

void Map::LoadMapData()
{
	mapDataHandle = FileRead_open("Resource/mario_1-1_mapdata.csv");
	for (int i = 0; i < MAP_SIZE_X * MAP_SIZE_Y; ++i)
	{
		if (FileRead_scanf(mapDataHandle, "%d,",mapData + i) == -1)
		{
			break;
		}
	}
	FileRead_close(mapDataHandle);
}

void Map::CreateMap()
{
	for (int y = 0; y < MAP_SIZE_Y; ++y)
	{
		for (int x = 0; x < MAP_SIZE_X; ++x)
		{
			switch(mapData[x + y * MAP_SIZE_X])
			{
			case 0:
			{
				// 生成なし
				break;
			}
			case 1:
			{
				// 地面ブロック(表)
				NormalBlock* normalBlock = new NormalBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), ImageManager::GetFGroundBlockHandle());
				break;
			}
			case 2:
			{
				// 地面ブロック(裏)
				NormalBlock* normalBlock = new NormalBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), ImageManager::GetBGroundBlockHandle());
				break;
			}
			case 3:
			{
				// 非破壊ブロック
				NormalBlock* normalBlock = new NormalBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), 
														   ImageManager::GetUnBreakBlockHandle());
				break;
			}
			case 4:
			{
				// レンガ(アイテムなし・表)
				BreakBlock* breakBlock = new BreakBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), ImageManager::GetFBrickBlockHandle()[0]);
				break;
			}
			case 5:
			{
				// レンガ(アイテムなし・裏)
				BreakBlock* breakBlock = new BreakBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), ImageManager::GetBBrickBlockHandle());
				break;
			}
			case 6:
			{
				// レンガ(コイン・表)
				break;
			}
			case 7:
			{
				// レンガ(スター・表)
				break;
			}
			case 8:
			{
				// ?(コイン) 
				break;
			}
			case 9:
			{
				// ?(キノコ)
				break;
			}
			case 10:
			{
				// ?(フラワー)
				break;
			}
			case 11:
			{
				// 透明(1UP)
				break;
			}
			case 12:
			{
				// コイン(表)
				break;
			}
			case 13:
			{
				// コイン(裏)
				break;
			}
			case 14:
			{
				// 土管(上)_01
				break;
			}
			case 15:
			{
				// 土管(上)_02
				break;
			}
			case 16:
			{
				// 土管(上)_03
				break;
			}
			case 17:
			{
				// 土管(上)_04
				break;
			}
			case 18:
			{
				// 土管(左)_01
				break;
			}
			case 19:
			{
				// 土管(左)_02
				break;
			}
			case 20:
			{
				// 土管(左)_03
				break;
			}
			case 21:
			{
				// 土管(左)_04
				break;
			}
			case 22:
			{
				// 土管(接続部)_01
				break;
			}
			case 23:
			{
				// 土管(接続部)_02
				break;
			}
			case 24:
			{
				// ゴールポール_01
				break;
			}
			case 25:
			{
				// ゴールポール_02
				break;
			}
			case 26:
			{
				// 旗
				break;
			}
			case 27:
			{
				// 砦_01
				break;
			}
			case 28:
			{
				// 砦_02
				break;
			}
			case 29:
			{
				// 砦_03
				break;
			}
			case 30:
			{
				// 砦_04
				break;
			}
			case 31:
			{
				// 砦_05
				break;
			}
			case 32:
			{
				// 砦_06
				break;
			}
			case 33:
			{
				// 砦_07
				break;
			}
			case 34:
			{
				// 砦_08
				break;
			}
			case 35:
			{
				// 砦_09
				break;
			}
			case 36:
			{
				// 砦_10
				break;
			}
			case 37:
			{
				// 砦_11
				break;
			}
			case 38:
			{
				// 砦_12
				break;
			}
			case 39:
			{
				// 砦_13
				break;
			}
			case 40:
			{
				// 砦_14
				break;
			}
			case 41:
			{
				// 砦_15
				break;
			}
			case 42:
			{
				// 砦_16
				break;
			}
			case 43:
			{
				// 砦_17
				break;
			}
			case 44:
			{
				// 砦_18
				break;
			}
			case 45:
			{
				// 砦_19
				break;
			}
			case 46:
			{
				// 砦_20
				break;
			}
			case 47:
			{
				// 砦_21
				break;
			}
			case 48:
			{
				// 砦_22
				break;
			}
			case 49:
			{
				// 砦_23
				break;
			}
			case 50:
			{
				// 砦_24
				break;
			}
			case 51:
			{
				// 砦_25
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
}