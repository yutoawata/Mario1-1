#include "Map.h"

Map::Map()
{
	LoadMapData();
}

Map::~Map()
{

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

void Map::ViewDataDebug()
{
	for (int y = 0; y < MAP_SIZE_Y; ++y)
	{
		for (int x = 0; x < MAP_SIZE_X; ++x)
		{
			DrawFormatString(x * BLOCK_SIZE, y * BLOCK_SIZE, GetColor(255, 255, 255), "%d",mapData[x*y]);
		}
	}
}