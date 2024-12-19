#pragma once
#include "DxLib.h"
#include "..\\Math\\Vector2.h" // �f�o�b�O�p
#include <stdio.h>
#include <vector>
#include <string>



class Map
{
public:

	// �����o�֐�

	Map(); // �R���X�g���N�^
	~Map(); // �f�X�g���N�^
	void MovePositionDebug(); // �}�b�v�ړ�(�f�o�b�O)
	void ViewDataDebug(); // �}�b�v�f�[�^�\��(�f�o�b�O�p)


private:

	// �����o�֐�

	void LoadMapData(); // �}�b�v�f�[�^�̓ǂݎ��


	// �����o�萔
	const int MAP_SIZE_X = 213; // ���̃u���b�N��
	const int MAP_SIZE_Y = 30;  // �c�̃u���b�N��
	const int BLOCK_SIZE = 32;  // �P�u���b�N�̃T�C�Y

	// �����o�ϐ�

	std::vector<int> fGroundBlockImageHandle;   // �n�ʃu���b�N�̉摜�n���h�� 
	std::vector<int> fUnbreakBlockImageHandle;  // ��j��u���b�N�̉摜�n���h��
	std::vector<int> fBrickBlockImageHandle;	// �����K�u���b�N�̉摜�n���h��
	std::vector<int> fQuestionBlockImageHandle; // �H�u���b�N�̉摜�n���h��
	std::vector<int> bGroundBlockImageHandle;   // �n�ʃu���b�N�̉摜�n���h��
	std::vector<int> bBrickBlockImageHandle;	// �����K�u���b�N�̉摜�n���h��

	int* mapData = new int[MAP_SIZE_X * MAP_SIZE_Y]; // �}�b�v�f�[�^�ۑ��z��
	int mapDataHandle; // �}�b�v�f�[�^�̃n���h��
	Vector2 position = Vector2::ZERO;
	bool isHitKey = false;


};