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
				NormalBlock* fGroundBlock = new NormalBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), ImageManager::GetFGroundBlockHandle());
				break;
			}
			case 2:
			{
				// 地面ブロック(裏)
				NormalBlock* bGroundBlock = new NormalBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), ImageManager::GetBGroundBlockHandle());
				break;
			}
			case 3:
			{
				// 非破壊ブロック
				NormalBlock* unBreakBlock = new NormalBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE), 
														   ImageManager::GetUnBreakBlockHandle());
				break;
			}
			case 4:
			{
				// レンガ(アイテムなし・表・破壊可)
				BreakBlock* breakBlock = new BreakBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
																ImageManager::GetFBrickBlockHandle()[0]);
				break;
			}
			case 5:
			{
				// レンガ(アイテムなし・裏・非破壊)
				NormalBlock* bBrickBlock = new NormalBlock(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
														   ImageManager::GetBBrickBlockHandle());
				break;
			}
			case 6:
			{
				// レンガ(コイン・表)
				BrickBlock* brickBlockCoin = new BrickBlock(ImageManager::GetFBrickBlockHandle(),
														Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
														ItemType::COIN, 5,
														true);
				break;
			}
			case 7:
			{
				// レンガ(スター・表)
				BrickBlock* brickBlockStar = new BrickBlock(ImageManager::GetFBrickBlockHandle(),	
														Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
														ItemType::STAR,1,
														true);
				break;
			}
			case 8:
			{
				// ?(コイン) 
				QuestionBlock* questionBlockCoin = new QuestionBlock(ImageManager::GetQuestionBlockHandle(),
																 Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
																 ItemType::COIN);
				break;
			}
			case 9:
			{
				// ?(キノコ)
				QuestionBlock* questionBlockMashroom = new QuestionBlock(ImageManager::GetQuestionBlockHandle(),
																 Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
																 ItemType::MASHROOM);
				break;
			}
			case 10:
			{
				// ?(フラワー)
				QuestionBlock* questionBlockFlower = new QuestionBlock(ImageManager::GetQuestionBlockHandle(),
																	   Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
																	   ItemType::FIRE_FLOWER);
				break;
			}
			case 11:
			{
				// 透明(1UP)
				BrickBlock* hiddenBlockOneUpMashroom = new BrickBlock(ImageManager::GetFBrickBlockHandle(),
																	  Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
																	  ItemType::ONEUP_MASHROOM,1,
																	  false);
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
				// 土管(表)_口_左
				Pype* fPypeMouthLeft = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
												 ImageManager::GetFPypeHandle()[0],
												 "fPypeMouth");
				break;
			}
			case 15:
			{
				// 土管(表)_口_右
				Pype* fPypeMouthRight = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
												  ImageManager::GetFPypeHandle()[1],
												  "fPypeMouth");
				break;
			}
			case 16:
			{
				// 土管(表)_首_左
				Pype* fPypeNeckLeft = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
												ImageManager::GetFPypeHandle()[2],
												"fPypeNeck");
				break;
			}
			case 17:
			{
				// 土管(表)_首_右
				Pype* fPypeNeckRight = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
												 ImageManager::GetFPypeHandle()[3],
												 "fPypeNeck");
				break;
			}
			case 18:
			{
				// 土管(裏)_口_上
				Pype* bPypeMouthTop = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
											   ImageManager::GetbPypeHandle()[0],
											   "bPypeMouth");
				break;
			}
			case 19:
			{
				// 土管(裏)_首_上
				Pype* bPypeNeckTop = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
											  ImageManager::GetbPypeHandle()[1],
											  "bPypeNeck");
				break;
			}
			case 20:
			{
				// 土管(裏)_接続部_上
				Pype* bPypejointTop = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
											   ImageManager::GetbPypeHandle()[2],
											   "bPypejoint");
				break;
			}
			case 21:
			{
				// 土管(裏)_口_下
				Pype* bPypeMouthBottom = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
											   ImageManager::GetbPypeHandle()[3],
											   "bPypeMouth");
				break;
			}
			case 22:
			{
				// 土管(裏)_首_下
				Pype* bPypeNeckBottom = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
											     ImageManager::GetbPypeHandle()[4],
											     "bPypeNeck");
				break;
			}
			case 23:
			{
				// 土管(裏)_接続部_下
				Pype* bPypejointBottom = new Pype(Vector2(x * BLOCK_SIZE, y * BLOCK_SIZE),
											      ImageManager::GetbPypeHandle()[5],
											      "bPypejoint");
				break;
			}
			case 24:
			{
				// ゴールポール_頭
				break;
			}
			case 25:
			{
				// ゴールポール_首
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