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
	std::vector<int> tempdata;
	Vector2 draw_pos;
	DrawFormatString(6 * BLOCK_SIZE, 10, GetColor(255, 255, 255), "X:%d,Y:%d,MAPDATA:%d", position.x, position.y,position.x + position.y * MAP_SIZE_X);

	for (int y = 0; y < 15; ++y)
	{
		for (int x = 0; x < 16; ++x)
		{
			tempdata.push_back(mapData[(x + position.x) + (y + position.y) * MAP_SIZE_X]);
		}
	}

	DrawFormatString(10 * BLOCK_SIZE, 10, GetColor(255, 255, 255), "data.size:%d",tempdata.size());

	for (int i = 0; i < tempdata.size(); ++i)
	{
		DrawFormatString(draw_pos.x * BLOCK_SIZE, BLOCK_SIZE + draw_pos.y * BLOCK_SIZE, GetColor(255, 255, 255), "%d", tempdata[i]);
		draw_pos.x++;
		if (draw_pos.x > 15)
		{
			draw_pos.x = 0;
			draw_pos.y++;
		}
	}

}