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

void Map::MovePositionDebug()
{
	if (CheckHitKeyAll())
	{
		if (isHitKey)
		{
			return;
		}

		if (CheckHitKey(KEY_INPUT_UP))
		{
			position.y--;
			isHitKey = true;
			if (position.y < 0)
			{
				position.y = 0;
			}
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			position.y++;
			isHitKey = true;
			if (position.y > MAP_SIZE_Y/2)
			{
				position.y = MAP_SIZE_Y/2;
			}
		}
		
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			position.x--;
			isHitKey = true;
			if (position.x < 0)
			{
				position.x = 0;
			}
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			position.x++;
			isHitKey = true;
			if (position.x > MAP_SIZE_X)
			{
				position.x = MAP_SIZE_X;
			}
		}
	}
	else
	{
		isHitKey = false;
	}
}

void Map::ViewDataDebug()
{

}