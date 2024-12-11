#pragma once
#include "DxLib.h"
#include <stdio.h>
#include <vector>
#include <string>



class Map
{
public:
	// �����o�֐�

	Map(); // �R���X�g���N�^
	~Map(); // �f�X�g���N�^

	void ViewDataDebug();


private:

	void LoadMapData(); // �}�b�v�f�[�^�̓ǂݎ��

	// �����o�萔
	const std::string mapPath = "Resource/mario_1-1_mapdata.csv";
	const int MAP_SIZE_X = 213;
	const int MAP_SIZE_Y = 15;
	const int BLOCK_SIZE = 32;

	// �����o�ϐ�
	int* mapData = new int[MAP_SIZE_X * MAP_SIZE_Y];
	int mapDataHandle;
	std::string viewNum;
};