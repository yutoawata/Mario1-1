#pragma once
#include "DxLib.h"
#include "..\BaseClass\SceneBase.h"
#include "..\Scene\TitleScene.h"

class GameManger {
	//�����o�֐�
public:
	//�R���X�g���N�^
	GameManger();
	//�f�X�g���N�^
	~GameManger();

	//�Q�[�����[�v����
	void ExcuteGameLoop();

	//�����o�萔
public:
	//�Q�[���E�B���h�E�ݒ�萔--------------
	static const int SCREEN_WIDTH = 256;	//�Q�[���E�B���h�E�̉���
	static const int SCREEN_HEIGHT = 240;	//�Q�[���E�B���h�E�̏c��
	static const int SCREEN_COLOR = 32;		//�Q�[���E�B���h�E�̃J���[�r�b�g

	//�����o�ϐ�
private:
	SceneBase* currentScene = new TitleScene();	//���݂̃V�[��
	int isInit = FALSE;							//���C�u�����������֐��̐����t���O
};